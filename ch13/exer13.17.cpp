#include <string>
#include <iostream>
class HasPtr
{
public:
    HasPtr(const std::string &str = std::string())
        : ps(new std::string(str)), counter(new std::size_t(1)) {}
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
    std::size_t *counter;
};

HasPtr::HasPtr(const HasPtr &res) : i(res.i), counter(res.counter)
{
    ps = res.ps;
    --*counter;
}

HasPtr &HasPtr::operator=(const HasPtr &res)
{
    ++*(res.counter);
    if (--*counter == 0)
    {
        delete ps;
        delete counter;
    }
    ps = res.ps;
    counter = res.counter;
    i = res.i;
    return *this;
}