//#include "net.h"
#include "socket.h"
#include "sock_op.h"
#include <stdio.h>

using namespace walle;
using namespace walle::net;
using namespace walle::net::sock_op;

static const uint16_t SERVER_PORT = 9091;

void run_server()
{
    int32_t sock = create_socket();
    Socket srv_socket = Socket(sock);
    srv_socket.setReuseAddr(true);

    Endpoint endpoint(SERVER_PORT);
    printf("server info ip:%s,port:%u,reuseAddr:%s\n", 
           endpoint.getIp().c_str(), endpoint.getPort(), srv_socket.isReuseAddr()?"yes":"no");
    srv_socket.bind(&endpoint);
    srv_socket.listen();

    Endpoint cli_point;
    srv_socket.accept(&cli_point);
    printf("accept client: ip=%s, port=%u\n", cli_point.getIp().c_str(), cli_point.getPort());
}

int main()
{
    run_server();
}
