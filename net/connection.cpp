#include "connection.h"

using namespace walle::net;

Connection::Connection(int32_t sockfd, const Endpoint& ep)
    : m_socket(sockfd),
      m_endpoint(ep)
{
}

int32_t Connection::send(const void* buf, int32_t len)
{
    return m_socket.send(buf, len);
}
