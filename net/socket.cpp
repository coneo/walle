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
    shutdown();
}

void Socket::shutdown()
{
    sock_op::close_ex(m_sockfd);
    fprintf(stderr, "socket shutdown fd:%d \n", m_sockfd);
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

int32_t Socket::send(const void* buf, int32_t bufLen)
{
    return sock_op::send_ex(m_sockfd, buf, bufLen);
}

int32_t Socket::recv(void* buf, int32_t bufLen)
{
    return sock_op::recv_ex(m_sockfd, buf, bufLen);
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

void Socket::defaultReadCallBack()
{
    char buf[128] = {0};
    int32_t len = this->recv(buf, sizeof(buf));
    if (len == 0 || len == -1)
    {
        shutdown();
        return ;
    }
    fprintf(stdout, "read : %s,%d \n", buf, len);
}

void Socket::setPollReadCallBack(PollCallBack cb)
{
    pollReadCallBack = cb;
}

void Socket::setPollWriteCallBack(PollCallBack cb)
{
    pollWriteCallBack = cb;
}

void Socket::setPollErrorCallBack(PollCallBack cb)
{
    pollErrorCallBack = cb;
}
