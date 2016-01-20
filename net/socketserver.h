#ifndef NET_SOCKET_SERVER_H
#define NET_SOCKET_SERVER_H

#include <map>
#include "acceptor.h"
#include "sock_poller.h"
#include "socket.h"

namespace walle{
namespace net{

class Connection;

class SocketServer
{
public:
    SocketServer();

    virtual ~SocketServer();

    bool init(uint16_t port);

    void run();

    void final();

    bool addConnection(Connection* con);

    void removeConnection(const Connection* con);

protected:

    virtual void msgParse();

private:
    typedef std::map<int32_t, Connection*> ConnectionMap;

    Poller* m_poller = nullptr;

    Acceptor m_acceptor;

    ConnectionMap m_connections;
};

}}
#endif
