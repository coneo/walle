#include "net/socketserver.h"
#include "base/cmd_dispatcher.h"
#include "cmd/testcmd.h"
#include <iostream>


static const uint16_t SERVER_PORT = 9091;

//考虑用包含替换继承
class MyServer : public walle::net::SocketServer
{
public:
    MyServer() {}
    virtual ~MyServer() {}

    void regCmdCB(uint32_t cmdid, CmdDispatcher::CmdFunc func)
    {
        m_dispatcher.reg(cmdid, func);
    }

private:
    CmdDispatcher m_dispatcher;
};

bool on_client_test(const walle::base::BaseCmd* cmd, uint32_t len)
{
    printf("");
}

int main(int argc, char** argv)
{
    using namespace std::placeholders;

    MyServer server;

    server.init(SERVER_PORT);

    server.regCmdCB(cmd::MSG_clienttest_ID, std::bind(on_client_test, _1, _2));

    server.run();

    server.final();

    return 0;
}
