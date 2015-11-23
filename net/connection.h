#ifndef NET_CONNECTION_H
#define NET_CONNECTION_H

#include "socket.h"
#include "endpoint.h"

namespace walle{
namespace net{

class Connection
{
public:
    Connection(int32_t sockfd, const Endpoint& ep);

    Socket& socket() { return m_socket; }

    int32_t send(const void* buf, int32_t len);

private:
    Socket m_socket;
    Endpoint m_endpoint;
};

}}

#endif
