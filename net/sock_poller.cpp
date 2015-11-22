#include "sock_poller.h"
#include <stdio.h>

using namespace walle::net;

bool Poller::init()
{
    m_pollfd = sp_create();
    if (sp_invalid(m_pollfd))
    {
        fprintf(stderr, "create poll event pool failed.\n");
        return false;
    }
    return true;
}
