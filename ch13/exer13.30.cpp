#include <string>
#include <iostream>
class HasPtr
{
    friend void swap(HasPtr &lres, HasPtr &rres);

public:
    HasPtr(const std::string &str = std::string())
        : ps(new std::string(str)) {}
    HasPtr(const HasPtr &res);
    //HasPtr &operator=(const HasPtr &res);
    //HasPtr &operator=(HasPtr &&rref);
    HasPtr &operator=(HasPtr res)
    {
        swap(*this, res);
        return *this;
    }
    HasPtr(HasPtr &&ref) : ps(ref.ps)
    {
        ref.ps = nullptr;
    }
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

// HasPtr &HasPtr::operator=(const HasPtr &res)
// {
//     /* delete ps;
//     i = res.i;
//     ps = new std::string(*res.ps);
//     return *this;//这个写法当自己给自己赋值时,会出问题
//     */
//     auto tmpPtr = new std::string(*res.ps);
//     delete ps;
//     ps = tmpPtr;
//     i = res.i;
//     return *this;
// }


inline void swap(HasPtr &lref, HasPtr &rref)
{
    using std::swap;
    swap(lref.ps, rref.ps);
    swap(lref.i, rref.i);
}


