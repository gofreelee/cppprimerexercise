#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Foo
{
private:
    vector<int> vec;
public:
    Foo() = default;
    ~Foo() = default;
    Foo sorted() &&
    {
        sort(vec.begin(),vec.end());
        return *this;
    }
    Foo sorted() &
    {
        cout<<1;
        Foo tmp(*this);
        sort(tmp.vec.begin(),tmp.vec.end());
        return tmp;
    }
};

Foo f()
{
    return Foo();
}

