/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2015-12-08 23:28 +0800
 *
 * Description:消息基
 */

#ifndef BASE_BASECMD_H
#define BASE_BASECMD_H

namespace walle{
namespace base{

struct BaseCmd
{
    uint32_t baseid = 0;

    BaseCmd(uint32_t _id) : baseid(_id)
    {
    }
};

}}

#endif
