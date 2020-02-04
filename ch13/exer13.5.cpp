#include <string>
#include <iostream>
class HasPtr
{
public:
    HasPtr(const std::string &str = std::string())
        : ps(new std::string(str)) {}
    HasPtr(const HasPtr &res);
    HasPtr &operator=(const HasPtr &res);
    std::string &getContent() const
    {
        return *ps;
    }
    ~HasPtr()
    {
        delete ps;
    }

private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &res) : i(res.i)
{
    ps = new std::string(*res.ps);
}

HasPtr &HasPtr::operator=(const HasPtr &res)
{
    i = res.i;
    ps = new std::string(*res.ps);
}

int main()
{
    HasPtr hasPtr("cpp");
    HasPtr hasPtr2 = hasPtr; //应该是使用拷贝构造函数
    HasPtr hasPtr3;
    hasPtr3 = hasPtr;
    std::cout << hasPtr3.getContent();
}