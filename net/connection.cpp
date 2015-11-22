#include "connection.h"

using namespace walle::net;

Connection::Connection(int32_t sockfd, const Endpoint& ep)
    : m_socket(sockfd),
      m_endpoint(ep)
{
}
