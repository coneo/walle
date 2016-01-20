#include "connection.h"

using namespace walle::net;

Connection::Connection(int32_t sockfd, const Endpoint& ep)
    : m_socket(sockfd),
      m_endpoint(ep),
      m_id(sockfd)
{
}

int32_t Connection::send(const void* buf, int32_t len)
{
    return m_socket.send(buf, len);
}

void Connection::recvMsg()
{
    char buf[SocketBuffer::DATA_CHUNK_SIZE] = {0};
    int32_t len = socket().recv(buf, sizeof(buf));
    if (len == 0 || len == -1)
    {
        socket().shutdown();
        handleClose();
        return ;
    }
    socket().writeToBuf(buf, len);
}

void Connection::parseMsg()
{
    char packet[SocketBuffer::DATA_CHUNK_SIZE] = {0};
    uint32_t len = socket().readFromBuf(packet, sizeof(packet));
    if (len)
    {
        fprintf(stdout, "paseMsg:%s\n",packet);
    }
}

void Connection::handleClose()
{
    fprintf(stderr, "Connection::handleClose\n");

    m_closeCallback(this);
}
