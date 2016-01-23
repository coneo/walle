#ifndef WALLE_NONCOPYABLE_H
#define WALLE_NONCOPYABLE_H

namespace walle{
namespace base{

class noncopyable
{
protected:
    noncopyable() = default;
    ~noncopyable() = default;

    noncopyable(const noncopyable&) = delete;
    noncopyable& operator=(const noncopyable&) = delete;
};

}}
#endif
