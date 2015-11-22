#ifndef NET_SOCKET_SERVER_H
#define NET_SOCKET_SERVER_H

#include <map>
#include "sock_poller.h"
#include "socket.h"

namespace walle{
namespace net{

class Connection;

class SocketServer
{
public:
    SocketServer();

    bool init(uint16_t port);

    void run();

    void final();

private:
    void acceptCallBack();

private:
    typedef std::map<int32_t, Connection*> ConnectionMap;

    Poller* m_poller = nullptr;

    Socket m_socket;

    ConnectionMap m_connections;
};

}}
#endif
