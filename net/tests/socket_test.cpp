#include "net/net.h"
#include <stdio.h>

using namespace walle;
using namespace walle::net;

static const uint16_t SERVER_PORT = 9090;

void run_server()
{
    int32_t sock = sock_op::create_socket();
    Socket srv_socket = Socket(sock);

    Endpoint endpoint(SERVER_PORT);
    srv_socket.bind(&endpoint);
    srv_socket.listen();

    Endpoint cli_point;
    srv_socket.accept(&cli_point);
    printf("accept client: ip=%s, port=%u", cli_point.getIp().c_str(), cli_point.getPort());
}

void run_client()
{
    int32_t sock = sock_op::create_socket();
    Socket cli_socket = Socket(sock);

    Endpoint endpoint(SERVER_PORT);
    cli_socket.connect(&endpoint);
    printf("connect server success");
}

int main()
{
#ifdef TEST_SERVER
    run_server();
#else
    run_client();
#endif
}
