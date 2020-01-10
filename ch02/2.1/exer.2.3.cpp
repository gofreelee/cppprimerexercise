#include <iostream>
using namespace std;
int main()
{
    unsigned u = 10, u2 = 42;
    std::cout << u - u2 << std::endl;//-32转成无符号数.
    std::cout << u2 - u << std::endl;
}