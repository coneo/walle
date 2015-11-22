//#include "net.h"
#include "socket.h"
#include "sock_op.h"
#include <stdio.h>

using namespace walle;
using namespace walle::net;
using namespace walle::net::sock_op;

static const uint16_t SERVER_PORT = 9091;

void run_client()
{
    int32_t sock = create_socket();
    Socket cli_socket = Socket(sock);

    Endpoint endpoint(SERVER_PORT);
    printf("server info ip:%s,port:%u\n", endpoint.getIp().c_str(), endpoint.getPort());
    cli_socket.connect(&endpoint);
    printf("connect server success\n");

    char buf[128] = "hello walle";
    cli_socket.send(buf, sizeof(buf));
}

int main()
{
    run_client();
}
