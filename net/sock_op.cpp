#include "sock_op.h"
#include "endpoint.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>

using namespace walle;
using namespace walle::net;
//using namespace walle::net::sock_op;

int32_t sock_op::create_socket()
{
    int32_t sockfd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0)
    {
        fprintf(stderr, "create_socket error");
    }
    return sockfd;
}

int32_t sock_op::bind_ex(int32_t sockfd, const Endpoint& endpoint)
{
    struct sockaddr_in addr = endpoint.getInetAddr();
    int32_t ret = ::bind(sockfd, (struct sockaddr*)&(addr), sizeof(endpoint.getInetAddr())); //FIXME:sockaddr convert
    if (ret < 0)
    {
        fprintf(stderr, "socket bind error");
    }
    return ret;
}

int32_t sock_op::listen_ex(int32_t sockfd)
{
    int32_t ret = ::listen(sockfd, SOMAXCONN);
    if (ret < 0)
    {
        fprintf(stderr, "socket listen error");
    }
    return ret;
}

int32_t sock_op::accept_ex(int32_t sockfd, Endpoint* cliendpoint)
{
    struct sockaddr_in cliaddr;
    socklen_t addr_len = sizeof (cliaddr);
    int32_t sock = ::accept(sockfd, (sockaddr*)&(cliaddr), &addr_len); //FIXME
    if (sock < 0)
    {
        fprintf(stderr, "socket accept error");
    }
    else
    {
        cliendpoint->setInetAddr(cliaddr);
    }
    return sock;
}

int32_t sock_op::connect_ex(int32_t sockfd, Endpoint* srv_endpoint)
{
    struct sockaddr_in ser_addr = srv_endpoint->getInetAddr();
    socklen_t addr_len = sizeof (ser_addr);
    int32_t ret = ::connect(sockfd, (sockaddr*)&(ser_addr), addr_len); //FIXME
    if (ret < 0)
    {
        fprintf(stderr, "sock_op::socket connect error\n");
    }
    return ret;
}

void sock_op::close_ex(int32_t sockfd)
{
    //FIXME int
    ::close(sockfd);
}

void sock_op::fromIp(const char* ip, struct sockaddr_in* addr)
{
    if (::inet_pton(AF_INET, ip, &addr->sin_addr) <= 0)
    {
        fprintf(stderr, "fromIp error");
    }
}

void sock_op::toIp(char* buf, size_t size, const struct sockaddr_in& addr)
{
    ::inet_ntop(AF_INET, &addr.sin_addr, buf, static_cast<socklen_t>(size));
}

int32_t sock_op::send_ex(int32_t sockfd, void* buf, int32_t buflen)
{
    int32_t send_len = ::send(sockfd, buf, buflen, MSG_NOSIGNAL);
    if (send_len == -1)
    {
        if(errno == EAGAIN || errno == EWOULDBLOCK)
            return -1;
    }
    return send_len;
}

int32_t sock_op::recv_ex(int32_t sockfd, void* buf, int32_t buflen)
{
    int32_t recv_len = ::recv(sockfd, buf, buflen, 0);
    if (recv_len == -1)
    {
        fprintf(stderr, "recv error");
    }

    return recv_len;
}
