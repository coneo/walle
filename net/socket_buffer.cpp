#include "socket_buffer.h"
#include <string.h>
#include <stdio.h>

using namespace walle::net;


SocketBuffer::SocketBuffer(uint32_t datasize)
{
    m_buffer.resize(datasize);
    m_maxSize = m_buffer.size();
}

uint32_t SocketBuffer::write(const char* data, uint32_t len)
{
    if (m_writeIndex + len < m_maxSize)
    {
        moveSpace();
        m_maxSize += len + DATA_CHUNK_SIZE;
        m_buffer.resize(m_maxSize);
    }

    memcpy((void*)&m_buffer[m_writeIndex], (void*)data, len);
    m_writeIndex += len;

    return len;
}

uint32_t SocketBuffer::read(char* data, uint32_t maxlen)
{
    if (m_readIndex >= m_writeIndex)
        return 0;

    int32_t remain_size = m_writeIndex - m_readIndex;
    if (DATA_HEAD_SIZE > remain_size)
        return 0;

    int32_t pack_size = getReadyPack();
    if (pack_size < 0)
    {
        fprintf(stdout, "socket buffer read incomplete \n");
        return 0;
    }
    if (pack_size > maxlen)
        pack_size = maxlen;
    if (pack_size + DATA_HEAD_SIZE > remain_size)
        return 0;

    memcpy((void*)data, (void*)&m_buffer[m_readIndex + DATA_HEAD_SIZE], pack_size);
    m_readIndex += (pack_size + DATA_HEAD_SIZE);

    return pack_size;
}

uint32_t SocketBuffer::writableSize()
{
    return (m_writeIndex > m_readIndex) ? (m_writeIndex - m_readIndex) : 0;
}

int32_t SocketBuffer::getReadyPack()
{
    uint32_t head = *(uint32_t *)&(m_buffer[m_readIndex]);
    uint32_t len = SOCK_HASH_GET_LEN(head);
    if (len > DATA_CHUNK_SIZE)
    {
        return DATA_CHUNK_SIZE;
    }

    if (len + DATA_HEAD_SIZE > writableSize())
    {
        return -1;
    }
    return len;
}

void SocketBuffer::moveSpace()
{
    std::copy(m_buffer.begin() + m_readIndex,
              m_buffer.begin() + m_writeIndex,
              m_buffer.begin());
    m_writeIndex -= m_readIndex; 
    m_readIndex = 0;
}
