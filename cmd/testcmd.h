#ifndef WALLE_CMD_TESTCMD_H
#define WALLE_CMD_TESTCMD_H

#include "base/basecmd.h"
#include "base/type.h"

using namespace walle::base;

namespace cmd{

const uint16_t MSG_clienttest_ID = 1;
struct MSG_clienttest : public BaseCmd
{
    uint32_t time = 0;
    char name[128] = {0};

    MSG_clienttest() : BaseCmd(MSG_clienttest_ID)
    {
    }
};

}
#endif
