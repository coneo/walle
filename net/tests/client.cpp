//#include "net.h"
#include "net/connector.h"
#include "net/connection.h"
#include "net/socket.h"
#include "net/sock_op.h"
#include <stdio.h>

using namespace walle;
using namespace walle::net;
using namespace walle::net::sock_op;

static const uint16_t SERVER_PORT = 9091;

void run_client()
{
    Connector cor(SERVER_PORT);
    Connection* con = cor.connect();
    if (con)
    {
        char buf[128] = "hello walle";
        con->send(buf, sizeof(buf));

        char revbuf[128] = {0};
        //con->socket().recv(revbuf, sizeof(revbuf));
        //fprintf(stdout, "recv:%s", revbuf);
        con->socket().defaultReadCallBack();

        con->socket().shutdown();

        delete con;
    }

}

int main()
{
    run_client();
}
