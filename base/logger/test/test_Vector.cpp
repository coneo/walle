#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(2);
    cout << "size=" << v.size() << "capacity=" << v.capacity() << endl;
    v.push_back(3);
    cout << "ele[size-1]=" << v[1] << "capacity=" << v.capacity() << endl;
    cout << "ele[0]=" << v[0] << "capacity=" << v.capacity() << endl;
    v.pop_back();
    cout << "ele[0]=" << v[0] << "capacity=" << v.capacity() << endl;
    cout << "size=" << v.size() << "capacity=" << v.capacity() << endl;
}
