/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2015-12-08 23:09 +0800
 *
 * Description: 消息分发器
 */

#ifndef BASE_CMD_DISPATCHER_H
#define BASE_CMD_DISPATCHER_H

#include "basecmd.h"

namespace walle{
namespace base{

class CmdDispatcher
{
public:
    typedef std::function<bool (const BaseCmd*, uint32_t)> CmdFunc;

    void reg(uint32_t cmdid, CmdFunc fun)
    {
        m_handlers[cmdid] = fun;
    }

    void dispatch(const BaseCmd* cmd, uint32_t len)
    {
        if (!cmd) return ;
        auto findit = m_handlers.find(cmd->baseid);
        if (findit != m_handlers.end())
        {
            findit->second(cmd, len);
        }
    }

private:
    std::map<uint32_t, CmdFunc> m_handlers;

};

}}
#endif

