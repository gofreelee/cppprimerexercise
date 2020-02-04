#include <string>
#include <iostream>
class HasPtr
{
    friend void swap(HasPtr &lres, HasPtr &rres);

public:
    HasPtr(const std::string &str = std::string())
        : ps(new std::string(str)) {}
    HasPtr(const HasPtr &res);
    HasPtr &operator=(const HasPtr &res);
    HasPtr &operator=(HasPtr &&rref);
    void debug()
    {
        std::cout << *ps;
    }
    // HasPtr(HasPtr &&ref) : ps(ref.ps)
    // {
    //     ref.ps = nullptr;
    // }
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
    /* delete ps;
    i = res.i;
    ps = new std::string(*res.ps);
    return *this;//这个写法当自己给自己赋值时,会出问题
    */
    auto tmpPtr = new std::string(*res.ps);
    delete ps;
    ps = tmpPtr;
    i = res.i;
    return *this;
}

HasPtr &HasPtr::operator=(HasPtr &&rref)
{
    if (this != &rref)
    {
        delete ps;
        ps = rref.ps;
        i = rref.i;
        rref.ps = nullptr;
    }
    return *this;
}

inline void swap(HasPtr &lref, HasPtr &rref)
{
    using std::swap;
    swap(lref.ps, rref.ps);
    swap(lref.i, rref.i);
}

int main()
{
    HasPtr h1("h1"), h2("h2");
    h2 = HasPtr() = h1;
    HasPtr h3("h3");
    std::cout << &h1 << std::endl;
    std::cout << &h2 << std::endl;
    std::cout << &h3 << std::endl;

    h2.debug();
}
