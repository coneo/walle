#include "acceptor.h"
#include "sock_poller.h"
#include "connection.h"
#include "socketserver.h"

using namespace walle::net;

Acceptor::Acceptor()
{
}

bool Acceptor::init(SocketServer* server, Poller* poller, uint16_t port)
{
    if (poller == nullptr || server == nullptr) return false;

    m_poller = poller;
    m_server = server;

    int32_t sock = sock_op::create_socket();
    m_socket.setFd(sock);
    m_socket.setReuseAddr(true);

    Endpoint endpoint(port);
    printf("server info ip:%s,port:%u,reuseAddr:%s\n", 
           endpoint.getIp().c_str(), endpoint.getPort(), m_socket.isReuseAddr()?"yes":"no");
    m_socket.bind(&endpoint);
    m_socket.listen();
    m_socket.setPollReadCallBack(std::bind(&Acceptor::accept, this));

    if (m_poller->add(&m_socket))
    {
        fprintf(stderr, "can't add server fd to event pool.\n");
    }

    return true;
}

void Acceptor::accept()
{
    if (!m_poller || !m_server) return ;

    Endpoint cli_point;
    int32_t newfd = m_socket.accept(&cli_point);
    printf("call back,accept client: ip=%s, port=%u\n", cli_point.getIp().c_str(), cli_point.getPort());

    Connection* new_con = new Connection(newfd, cli_point);
    if (!new_con) return ;

    fprintf(stdout, "new connection fd%d \n", newfd);

    //FIXME setnonblocking

    if (m_poller->add(&(new_con->socket())))
    {
        fprintf(stderr, "can't add client fd to event pool.\n");
        return ;
    }
    if (!m_server->addConnection(new_con))
    {
        fprintf(stderr, "can't add connection to server.\n");
        return ;
    }
    new_con->socket().setPollReadCallBack(std::bind(&Connection::recvMsg, new_con));

    char msg[128] = "this is walle server";
    new_con->send(msg, sizeof(msg));
}
