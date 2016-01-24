#include "net/socketserver.h"
#include <stdio.h>

using namespace walle;

static const uint16_t SERVER_PORT = 9091;

void run()
{
    net::SocketServer server;

    server.init(SERVER_PORT);

    server.run();

    server.final();
}

int main()
{
    run();
}
