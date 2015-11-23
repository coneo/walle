#include "socketserver.h"
#include <unistd.h>
#include "connection.h"

#ifdef __linux__
#include "sock_epoller.h"
#endif

using namespace walle::net;

SocketServer::SocketServer()
{
#ifdef __linux__
    m_poller = new Epoller();
#endif
}

bool SocketServer::init(uint16_t port)
{
    if (!m_poller || !m_poller->init())
        return false;

    int32_t sock = sock_op::create_socket();
    m_socket.setFd(sock);
    m_socket.setReuseAddr(true);

    Endpoint endpoint(port);
    printf("server info ip:%s,port:%u,reuseAddr:%s\n", 
           endpoint.getIp().c_str(), endpoint.getPort(), m_socket.isReuseAddr()?"yes":"no");
    m_socket.bind(&endpoint);
    m_socket.listen();
    m_socket.setPollReadCallBack(std::bind(&SocketServer::acceptCallBack, this));

    if (m_poller->add(&m_socket))
    {
        fprintf(stderr, "can't add server fd to event pool.\n");
        m_poller->release();
        return false;
    }

    return true;
}

void SocketServer::run()
{
    for (;;)
    {
        m_poller->wait(MAX_EVENT);
        ::usleep(100000);
    }
}

void SocketServer::final()
{
    printf("server end\n");
}

void SocketServer::acceptCallBack()
{
    if (!m_poller) return;

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
    new_con->socket().setPollReadCallBack(std::bind(&Socket::defaultReadCallBack, &(new_con->socket())));

    char msg[128] = "this is walle server";
    new_con->send(msg, sizeof(msg));

    return ;
}
