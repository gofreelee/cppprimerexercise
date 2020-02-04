#include <iostream>
#include "MyString.h"
using std::cout;
using std::endl;
int main()
{
    MyString s("helloworld");
    
    MyString s2;
    s2 = s;
    cout << s2.cStr();    
}