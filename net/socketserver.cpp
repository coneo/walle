#include "socketserver.h"
#include <unistd.h>
#include "connection.h"
#include "base/safe_define.h"

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

SocketServer::~SocketServer()
{
    SAFE_DELETE(m_poller);
}

bool SocketServer::init(uint16_t port)
{
    if (!m_poller || !m_poller->init())
        return false;

    if (!m_acceptor.init(this, m_poller, port))
        return false;

    return true;
}

void SocketServer::run()
{
    for (;;)
    {
        ::usleep(10000);

        m_poller->wait(MAX_EVENT);

        msgParse();
    }
}

void SocketServer::final()
{
    printf("server end\n");
}

bool SocketServer::addConnection(Connection* con)
{
    if (!con) return false;

    using namespace std::placeholders;

    m_connections.insert(std::make_pair(con->id(), con));
    con->setCloseCallback(std::bind(&SocketServer::removeConnection, this, _1));
    return true;
}

void SocketServer::removeConnection(const Connection* con)
{
    if (!con) return ;

    if (m_connections.count(con->id()))
    {
        fprintf(stderr, "removeConnection %d\n", con->id());
        m_connections.erase(con->id());

        //FIXME 此处有内存泄露
    }
}

void SocketServer::msgParse()
{
    for (auto con : m_connections)
    {
        if (con.second != nullptr)
        {
            con.second->parseMsg();
        }
    }
}
