#include<string>
using namespace std;
using strArray = string[10];
string str[10];
strArray& func();
decltype(str)& func();
auto func() -> string(&)[10];