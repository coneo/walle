#include "../singleton.h"
#include <iostream>

using namespace walle::base;
using namespace std;

class mysingleton : public Singleton<mysingleton>
{
public:
    void func()
    {
        cout << "mysingleton func" << endl;
    }
};

int main()
{
    cout << "singleton test" << endl;
    mysingleton::getme().func();
}
