/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2014-11-26 17:05 +0800
 *
 * Description: 
 */
#ifndef WALLE_NET_SOCKET_H
#define WALLE_NET_SOCKET_H

#include "endpoint.h"

namespace walle{
namespace net{

class Socket
{
public:
    Socket(int32_t sockfd);

    ~Socket();

    int32_t fd() const { return m_sockfd; }

    void bind(Endpoint* endpoint); 

    void listen();

    int32_t accept(Endpoint* endpoint);

    int32_t connect(Endpoint* endpoint);

    void setReuseAddr(bool on);
    bool isReuseAddr() const;

private:
    int32_t m_sockfd;
};

}}
#endif //#define WALLE_NET_SOCKET_H
