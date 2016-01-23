/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2016-01-23 14:18 +0800
 *
 * Description: 时间戳模块
 */

#ifndef WALLE_BASE_TIMESTAMP_H
#define WALLE_BASE_TIMESTAMP_H

#include "type.h"
#include <sys/time.h>

namespace walle{
namespace base{

class Timestamp
{
public:
    Timestamp() : m_microSecOfEpoch(0){}
    explicit Timestamp(int64_t micro_sec) : m_microSecOfEpoch(micro_sec){}

    static Timestamp now();

    int64_t micro_sec() { return m_microSecOfEpoch; }

    time_t sec() { return static_cast<time_t>(getSec()); }

    //一秒 == 1000 * 1000 微秒
    static const int64_t MicroSecondPerSecond = 1000 * 1000;

private:
    int64_t getSec() { return m_microSecOfEpoch / MicroSecondPerSecond; }

private:
    //微秒
    int64_t m_microSecOfEpoch;
};

}}
#endif
