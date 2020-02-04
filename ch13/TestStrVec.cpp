#include "StrVec.h"
#include <iostream>
using std::cout;
using std::endl;
//隐式转换的测试
class Test
{
public:
    Test(int _num) : num(_num) {}
    int num;
};
void Testtt(const Test &res)
{
    cout << res.num;
}
int main()
{
    StrVec strVec;
    strVec.pushBack("cppp"); //string的隐式转换?
    strVec.pushBack("rust");
    strVec.pushBack("java");
    StrVec strings = {"c++", "java", "scala"};
    cout << strings.capacity();
}