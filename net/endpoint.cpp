/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2014-11-26 19:31 +0800
 *
 * Description: 
 */
#include "endpoint.h"
#include "sock_op.h"

using namespace walle;
using namespace walle::net;

Endpoint::Endpoint()
{
    reset_addr();
}

Endpoint::Endpoint(uint16_t port)
{
    reset_addr();
    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_addr.sin_port = htons(port);
}

Endpoint::Endpoint(const std::string& ip, uint16_t port)
{
    reset_addr();
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons(port);
    sock_op::fromIp(ip.c_str(), &m_addr);
}

Endpoint::Endpoint(const struct sockaddr_in& addr)
    : m_addr(addr)
{
}

std::string Endpoint::getIp() const
{
    char buf[32];
    bzero(buf, sizeof(buf));
    sock_op::toIp(buf, sizeof(buf), m_addr);
    return buf;
}

uint16_t Endpoint::getPort() const
{
    return ntohs(m_addr.sin_port);
}
