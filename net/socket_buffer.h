#ifndef NET_SOCKET_BUFFER_H
#define NET_SOCKET_BUFFER_H

//#include "type.h"
#include <vector>
#include <stdint.h>

namespace walle{
namespace net{

/* 消息头
 * +-------------------+------------------+------------------+
 * |        是否加密   |     是否压缩     |      消息体长度  |
 * |        (18位)     |     (17 位)      |     (16 - 0 位)  |
 * +-------------------+------------------+------------------+
 */
#define SOCK_HASH_GET_LEN(head) \
    head&0xffff

#define SOCK_HASH_GET_COMPRESS(head) \
    (head>>16)&0x1

#define SOCK_HASH_GET_ENC(head) \
    (head>>17)&0x1

#define SOCK_HASH_LEN(len, head) \
    (head&0xffff0000)|(len&0xffff)

/* SocketBuffer设计
 * +-------------------+------------------+------------------+
 * | prependable bytes |  readable bytes  |  writable bytes  |
 * |                   |     (CONTENT)    |                  |
 * +-------------------+------------------+------------------+
 */

class SocketBuffer
{
public:
    static const uint32_t DATA_CHUNK_SIZE = 64 * 1024;
    static const uint32_t DATA_HEAD_SIZE = sizeof(uint32_t);
    static const uint32_t SOCK_BUF_INIT_SIZE = 1024;

public:
    SocketBuffer(uint32_t datasize = SOCK_BUF_INIT_SIZE);

    uint32_t write(const char* data, uint32_t len);

    uint32_t read(char* data, uint32_t len);

private:
    uint32_t writableSize();

    int32_t getReadyPack();

    void moveSpace();

private:

    std::vector<char> m_buffer;
    uint32_t m_maxSize = 0;
    uint32_t m_readIndex = 0;
    uint32_t m_writeIndex = 0;
};

}}

#endif

