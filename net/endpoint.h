/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2014-11-27 13:25 +0800
 *
 * Description: 
 */
#ifndef WALLE_NET_ENDPOINT_H
#define WALLE_NET_ENDPOINT_H

#include <netinet/in.h>
#include <string>
#include <string.h>

namespace walle{
namespace net{

class Endpoint
{
public:
    Endpoint();
    Endpoint(uint16_t port);
    Endpoint(const std::string& ip, uint16_t port);
    Endpoint(const struct sockaddr_in& addr);

    void setInetAddr(const struct sockaddr_in addr){ m_addr = addr; }

    sockaddr_in getInetAddr() const{ return m_addr; }
    std::string getIp() const;
    uint16_t getPort() const;

private:
    void reset_addr() { bzero(&m_addr, sizeof(m_addr)); }

private:
    struct sockaddr_in m_addr;
};

}}

#endif
