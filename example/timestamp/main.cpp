#include "../../base/timestamp.h"
#include <iostream>

using namespace walle::base;
using namespace std;

int main()
{
    cout << "now sec:" << Timestamp::now().sec() << endl;
    cout << "now msec:" << Timestamp::now().micro_sec() << endl;
}
