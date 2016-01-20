#include "log_file.h"

using namespace water;

int main()
{
    LogFile file("./test.file");

    char msg[32] = "hello logging";
    file.append(msg, sizeof(msg));
}
