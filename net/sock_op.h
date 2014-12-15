/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2014-11-26 03:57 +0800
 *
 * Description: 
 */
#ifndef WALLE_NET_SOCK_OP_H
#define WALLE_NET_SOCK_OP_H

#include <stdint.h>
#include "endpoint.h"

namespace walle{
namespace net{
namespace sock_op{

//class sockaddr_in;
//class Endpoint;

int32_t create_socket();

int32_t bind_ex(int32_t sockfd, const Endpoint& endpoint);

int32_t listen_ex(int32_t sockfd);

int32_t accept_ex(int32_t sockfd, Endpoint* cliendpoint);

int32_t connect_ex(int32_t sockfd, Endpoint* serendpoint);

void fromIp(const char* ip, struct sockaddr_in* addr);

void toIp(char* buf, size_t size, const struct sockaddr_in& addr);

}}}
#endif //#define WALLE_NET_SOCK_OP_H
