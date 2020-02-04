#include <iostream>
#include <vector>
class X
{
public:
    X()
    {
        std::cout << "构造函数" << std::endl;
    }
    X(const X &)
    {
        std::cout << "拷贝函数" << std::endl;
    }
    void operator=(const X &x)
    {
        std::cout << "拷贝赋值" << std::endl;
    }
    ~X()
    {
        std::cout << "析构函数" << std::endl;
    }
    double db[4] = {0.0};
};
X func(X x)
{
    //传参的拷贝
    std::cout << "*****" << std::endl;
    X tmp; //拷贝
    return tmp; // tmp 和 x的析构
}

int main()
{
    X x; // 构造
    X res = func(x);
    std::cout << "*****" << std::endl;
    /*
    构造
    拷贝
    拷贝
    析构
    析构
    拷贝
    
     */
}