#include "log_buffer.h"
#include <stdio.h>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

using namespace water;

int main()
{
    typedef LogBuffer<BIG_BUFFER_SIZE> Buffer;
    typedef std::unique_ptr<Buffer> BufferPtr;
    typedef std::vector<BufferPtr> BufferVec;
    BufferVec buffers;
    buffers.resize(15);
    for (unsigned int i = 0; i < buffers.size(); ++i)
    {
        buffers[i].reset(new Buffer);
    }
    cout << "buffers.size=" << buffers.size() << " buffers.capacity=" << buffers.capacity() << endl;

    char msg1[32] = "hello shok";
    BufferPtr buffer = std::move(buffers.back());
    cout << "buffers.size=" << buffers.size() << " buffers.capacity=" << buffers.capacity() << endl;
    buffers.pop_back();
    buffer->put(msg1, sizeof(msg1));
    printf("str=%s,len=%u\n", buffer->data(), buffer->length());
    cout << "buffers.size=" << buffers.size() << " buffers.capacity=" << buffers.capacity() << endl;

    /*
    LogBuffer<BIG_BUFFER_SIZE> buffer;
    char msg1[32] = "hello shok";
    buffer.put(msg1, sizeof(msg1));
    printf("str=%s,len=%u\n", buffer.data(), buffer.length());
    */
}
