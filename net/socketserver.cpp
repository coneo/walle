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

    if (!m_acceptor.init(m_poller, port))
        return false;

    return true;
}

void SocketServer::run()
{
    for (;;)
    {
        m_poller->wait(MAX_EVENT);
        ::usleep(10000);
    }
}

void SocketServer::final()
{
    printf("server end\n");
}

