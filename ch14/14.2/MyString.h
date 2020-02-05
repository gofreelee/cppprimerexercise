#include <memory>
#include <iostream>
using std::cout;

class MyString
{
public:
    MyString() : MyString("") {}
    MyString(const char *ptr);
    MyString(const MyString &str);
    MyString(MyString &&);
    MyString &operator=(const MyString &str);
    MyString &operator=(MyString &&str);

    ~MyString();
    void free();
    const char *cStr() const
    {
        return contentPtr;
    }

private:
    static std::allocator<char> alloc;
    char *contentPtr;
    int length;
};
std::ostream &operator<<(std::ostream &os, const MyString &ref);