/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2014-11-26 17:05 +0800
 *
 * Description: 
 */
#ifndef WALLE_NET_SOCKET_H
#define WALLE_NET_SOCKET_H

#include <functional>
#include "endpoint.h"
#include "sock_op.h"
#include "socket_buffer.h"

namespace walle{
namespace net{

class Socket
{
public:
    Socket(int32_t sockfd = -1);

    ~Socket();

    void shutdown();

    void setFd(int32_t sockfd) { m_sockfd = sockfd; }

    int32_t fd() const { return m_sockfd; }

    void bind(Endpoint* endpoint); 

    void listen();

    int32_t accept(Endpoint* endpoint);

    int32_t connect(Endpoint* endpoint);

    int32_t send(const void* buf, int32_t bufLen);

    int32_t recv(void* buf, int32_t bufLen);

    uint32_t writeToBuf(const char* buf, uint32_t len);
    uint32_t readFromBuf(char* buf, uint32_t maxlen);

    void setReuseAddr(bool on);
    bool isReuseAddr() const;

    void defaultReadCallBack();

public:

    typedef std::function<void ()> PollCallBack;

    void setPollReadCallBack(PollCallBack cb);
    void setPollWriteCallBack(PollCallBack cb);
    void setPollErrorCallBack(PollCallBack cb);

    PollCallBack pollReadCallBack;
    PollCallBack pollWriteCallBack;
    PollCallBack pollErrorCallBack;

private:
    int32_t m_sockfd;

    SocketBuffer m_recvBuf;
    SocketBuffer m_sendBuf;
};

}}
#endif //#define WALLE_NET_SOCKET_H
