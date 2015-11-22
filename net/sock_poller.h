#ifndef NET_SOCK_POLLER_H
#define NET_SOCK_POLLER_H

#include <stdint.h>

namespace walle{
namespace net{

#define MAX_EVENT 64

class Socket;
typedef int poll_fd;

struct poll_event {
	void * s;
	bool read;
	bool write;
};

class Poller
{
public:
    bool init();

    virtual int add(Socket* socket) = 0;
    virtual void del(Socket* socket) = 0;
    virtual void release() = 0;
    virtual int wait(int max) = 0;

protected:
    virtual bool sp_invalid(poll_fd fd) = 0;
    virtual poll_fd sp_create() = 0;
    virtual void sp_write(poll_fd, int sock, void *ud, bool enable) = 0;
    virtual void sp_nonblocking(int sock) = 0;

protected:
    int32_t m_pollfd = -1;
};

}}

#endif
