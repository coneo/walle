#include "timestamp.h"

using namespace walle::base;

Timestamp Timestamp::now()
{
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    int64_t sec = tv.tv_sec;
    return Timestamp(sec * MicroSecondPerSecond + tv.tv_usec);
}
