/*
 * Author: HongXiaoqiang  - cool.hxq@gmail.com
 *
 * Last modified: 2015-12-12 12:51 +0800
 *
 * Description: 封装一些安全接口
 */

#ifndef WALLE_SAFE_DEFINE_H
#define WALLE_SAFE_DEFINE_H

#define SAFE_DELETE(x) if (x) delete (x)
#define SAFE_DELETE_VEC(x) if (x) delete [] (x)

#endif
