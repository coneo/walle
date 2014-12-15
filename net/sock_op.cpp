#include "sock_op.h"
#include "endpoint.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>

using namespace walle;
using namespace walle::net;
using namespace walle::net::sock_op;

int32_t create_socket()
{
    int32_t sockfd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0)
    {
        fprintf(stderr, "create_socket error");
    }
    return sockfd;
}

int32_t bind_ex(int32_t sockfd, const Endpoint& endpoint)
{
    struct sockaddr_in addr = endpoint.getInetAddr();
    int32_t ret = ::bind(sockfd, (struct sockaddr*)&(addr), sizeof(endpoint.getInetAddr())); //FIXME:sockaddr convert
    if (ret < 0)
    {
        fprintf(stderr, "socket bind error");
    }
    return ret;
}

int32_t listen_ex(int32_t sockfd)
{
    int32_t ret = ::listen(sockfd, SOMAXCONN);
    if (ret < 0)
    {
        fprintf(stderr, "socket listen error");
    }
    return ret;
}

int32_t accept_ex(int32_t sockfd, Endpoint* cliendpoint)
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

int32_t connect_ex(int32_t sockfd, Endpoint* serendpoint)
{
    struct sockaddr_in ser_addr;
    socklen_t addr_len = sizeof (ser_addr);
    int32_t ret = ::connect(sockfd, (sockaddr*)&(ser_addr), addr_len); //FIXME
    if (ret < 0)
    {
        fprintf(stderr, "socket connect error");
    }
    return ret;
}

void fromIp(const char* ip, struct sockaddr_in* addr)
{
    if (::inet_pton(AF_INET, ip, &addr->sin_addr) <= 0)
    {
        fprintf(stderr, "fromIp error");
    }
}

void toIp(char* buf, size_t size, const struct sockaddr_in& addr)
{
    //::inet_ntop(AF_INET, &addr.sin_addr, buf, static_cast<socklen_t>(size));
}
