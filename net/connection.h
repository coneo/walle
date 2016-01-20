/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2015-12-08 23:10 +0800
 *
 * Description: 一个Socket连接
 */

#ifndef NET_CONNECTION_H
#define NET_CONNECTION_H

#include "socket.h"
#include "endpoint.h"

namespace walle{
namespace net{

class Connection
{
public:
    typedef std::function<void (const Connection*)> CloseFunc;

public:
    Connection(int32_t sockfd, const Endpoint& ep);

    int32_t id() const { return m_id; }

    Socket& socket() { return m_socket; }

    int32_t send(const void* buf, int32_t len);

    void recvMsg();

    void parseMsg();

    void handleClose();

    void setCloseCallback(const CloseFunc& func)
    {
        m_closeCallback = func;
    }

private:
    Socket m_socket;
    Endpoint m_endpoint;

    CloseFunc m_closeCallback;

    int32_t m_id = 0;
};

}}

#endif
