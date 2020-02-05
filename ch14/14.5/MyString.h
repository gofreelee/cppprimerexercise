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
    char& operator[](std::size_t index)
    {
        return contentPtr[index];
    }
    const char& operator[](std::size_t index) const
    {
        return contentPtr[index];
    }
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