/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2014-11-26 19:31 +0800
 *
 * Description: 
 */
#include "socket.h"
#include "sock_op.h"

using namespace walle;
using namespace walle::net;

Socket::Socket(int32_t sockfd)
    : m_sockfd(sockfd)
{
}

Socket::~Socket()
{
    //close FIXME
}

void Socket::bind(Endpoint* endpoint)
{
    sock_op::bind_ex(m_sockfd, *endpoint);
}

void Socket::listen()
{
    sock_op::listen_ex(m_sockfd);
}

int32_t Socket::accept(Endpoint* endpoint)
{
    return sock_op::accept_ex(m_sockfd, endpoint);
}

int32_t Socket::connect(Endpoint* endpoint)
{
    return sock_op::connect_ex(m_sockfd, endpoint);
}

void Socket::setReuseAddr(bool on)
{
    int32_t opt = on ? 1 : 0;
    ::setsockopt(m_sockfd, SOL_SOCKET, SO_REUSEADDR,
                 &opt, static_cast<socklen_t>(sizeof opt));
}

bool Socket::isReuseAddr() const
{
    int32_t opt;
    socklen_t len_opt = static_cast<socklen_t>(sizeof opt);
    ::getsockopt(m_sockfd, SOL_SOCKET, SO_REUSEADDR,
                 &opt, &len_opt);

    return (opt == 1);
}
