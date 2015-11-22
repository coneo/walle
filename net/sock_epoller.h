#ifndef NET_SOCK_EPOLLER_H
#define NET_SOCK_EPOLLER_H

#include "sock_poller.h"

namespace walle{
namespace net{

class Epoller : public Poller
{
    virtual bool sp_invalid(poll_fd fd) override;
    virtual poll_fd sp_create() override;
    virtual void release() override;
    virtual int add(Socket* socket) override;
    virtual void del(Socket* socket) override;
    virtual void sp_write(poll_fd, int sock, void *ud, bool enable) override;
    virtual int wait(int max) override;
    virtual void sp_nonblocking(int sock) override;
};

}}

#endif //#define NET_SOCK_EPOLLER_H
