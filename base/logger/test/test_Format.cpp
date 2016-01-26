#include "../../format.h"
#include <iostream>
#include <string>

using namespace walle::base;
using namespace std;

void formatStr()
{
    const char name[] = "hello shok";
    string str = format("{name} write {how many} code today \n", name, 20,"hello");
    cout << str;
}

void formatClass()
{
    struct stFoo /*: public IFormartAble*/
    {
        std::string str{"hello shok"};

        void appendToString(std::string* str) const /*override*/
        {
            str->append(this->str);
        }
    };

    stFoo foo;
    string str = format("stFoo data is {}\n", foo);
    cout << str;
}

int main()
{
    formatStr();
    formatClass();
}
