/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2016-01-23 20:33 +0800
 *
 * Description: 单例模式
 */

#ifndef WALLE_BASE_SINGLETON_H
#define WALLE_BASE_SINGLETON_H

#include "noncopyable.h"

namespace walle{
namespace base{

template<typename T>
class Singleton : noncopyable
{
public:
    static T& getme()
    {
        static T instance;
        return instance;
    }
};

}}
#endif
