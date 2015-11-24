/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2014-11-26 02:07 +0800
 *
 * Description: 
 */

#ifndef WALLE_NET_CONNECTOR_H
#define WALLE_NET_CONNECTOR_H

#include "endpoint.h"
#include "socket.h"

namespace walle{
namespace net{

class Connection;

class Connector
{
public:
    Connector(uint16_t port);

    Connection* connect();

private:
    Endpoint m_endpoint;
};

}}

#endif //#define WALLE_NET_CONNECTOR_H
