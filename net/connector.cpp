#include "connector.h"
#include "connection.h"

using namespace walle::net;

Connector::Connector(uint16_t port)
    : m_endpoint(port)
{
}

Connection* Connector::connect()
{
    int32_t sockfd = sock_op::create_socket();

    Connection* new_con = new Connection(sockfd, m_endpoint);
    if (new_con)
    {
        if (new_con->socket().connect(&m_endpoint) == -1)
            return NULL;
    }

    return new_con;
}
