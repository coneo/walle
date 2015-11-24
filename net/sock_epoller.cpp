#include "sock_epoller.h"
#include "socket.h"
#include <netdb.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

using namespace walle;
using namespace walle::net;

bool Epoller::sp_invalid(int efd)
{
    return efd == -1;
}

int Epoller::sp_create()
{
    return epoll_create(1024);
}

void Epoller::release()
{
    close(m_pollfd);
}

int Epoller::add(Socket* socket)
{
	struct epoll_event ev;
	ev.events = EPOLLIN;
	ev.data.ptr = socket;
	if (epoll_ctl(m_pollfd, EPOLL_CTL_ADD, socket->fd(), &ev) == -1) {
		return 1;
	}
	return 0;
}

void Epoller::del(Socket* socket)
{
    epoll_ctl(m_pollfd, EPOLL_CTL_DEL, socket->fd(), NULL);
}

void Epoller::sp_write(int efd, int sock, void *ud, bool enable)
{
	struct epoll_event ev;
	ev.events = EPOLLIN | (enable ? EPOLLOUT : 0);
	ev.data.ptr = ud;
	epoll_ctl(efd, EPOLL_CTL_MOD, sock, &ev);
}

int Epoller::wait(int max)
{
	struct epoll_event ev[max];
	int n = epoll_wait(m_pollfd , ev, max, -1);
    if (n == -1)
        return -1;
	for (int i=0; i<n; i++) 
    {
        Socket* socket = reinterpret_cast<Socket*>(ev[i].data.ptr);
        if (ev[i].events & EPOLLIN)
        {
            if (socket->pollReadCallBack)
                socket->pollReadCallBack();
        }
        if (ev[i].events & EPOLLOUT)
        {
            if (socket->pollWriteCallBack)
                socket->pollWriteCallBack();
        }
        if ((ev[i].events & EPOLLERR) || (ev[i].events & EPOLLHUP))
        {
            if (socket->pollErrorCallBack)
                socket->pollErrorCallBack();
        }
	}

	return n;
}

void Epoller::sp_nonblocking(int fd)
{
	int flag = fcntl(fd, F_GETFL, 0);
	if ( -1 == flag ) {
		return;
	}

	fcntl(fd, F_SETFL, flag | O_NONBLOCK);
}
