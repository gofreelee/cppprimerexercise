#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
class HasPtr
{
    friend void swap(HasPtr &lres, HasPtr &rres);
    friend bool operator<(const HasPtr &lres, const HasPtr &rres);

public:
    HasPtr(const std::string &str = std::string())
        : ps(new std::string(str))
    {
    }
    HasPtr(const HasPtr &res);
    HasPtr &operator=(HasPtr res);

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

HasPtr &HasPtr::operator=(HasPtr res)
{
    /* delete ps;
    i = res.i;
    ps = new std::string(*res.ps);
    return *this;//这个写法当自己给自己赋值时,会出问题
    */
   
    swap(*this, res);
    return *this;
}

inline void swap(HasPtr &lref, HasPtr &rref)
{
    using std::swap;
    swap(lref.ps, rref.ps);
    swap(lref.i, rref.i);
    std::cout << "swap" << std::endl;
}

bool operator<(const HasPtr &lres, const HasPtr &rres)
{
    *lres.ps < *rres.ps;
}

int main()
{
    HasPtr a = {"cpp"}, b = {"java"}, c = {"python"};
    vector<HasPtr> vec = {a, b, c};
    std::sort(vec.begin(), vec.end());
}