#include "MyString.h"

std::allocator<char> MyString::alloc;

MyString::MyString(const char *str)
{
    //std::cout << "构造" << std::endl;
    const char *resPtr = str;
    while (*resPtr != '\0')
        ++resPtr;
    //str 与 resPtr 之间是内容
    length = resPtr - str;
    contentPtr = alloc.allocate(length + 1);
    char *usePtr = contentPtr;
    for (int i = 0; i < length; ++i)
        *usePtr++ = *str++;
    *usePtr = '\0';
}
MyString::MyString(MyString&& rref):contentPtr(rref.contentPtr),length(rref.length)
{
    rref.contentPtr = nullptr;
    std::cout << "移动构造" <<std::endl;
}

MyString &MyString::operator=(const MyString &str)
{
    std::cout << "拷贝赋值" << std::endl;

    //析构之前的内容.
    free();
    auto newPtr = alloc.allocate(str.length + 1); //分配新内存
    contentPtr = newPtr;
    auto resPtr = str.contentPtr;
    length = str.length;
    for (int i = 0; i <= length; ++i)
        *newPtr++ = *resPtr++;
}

MyString::MyString(const MyString &str)
{
    std::cout << "拷贝构造" << std::endl;
    auto newPtr = alloc.allocate(str.length + 1); //分配新内存
    contentPtr = newPtr;
    auto resPtr = str.contentPtr;
    length = str.length;
    for (int i = 0; i <= length; ++i)
        *newPtr++ = *resPtr++;
}

MyString& MyString::operator=(MyString&& rref)
{
    if(this != &rref)
    {
        free();
        contentPtr = rref.contentPtr;
        length = rref.length;
        rref.contentPtr = nullptr;
    }
    return *this;
}

void MyString::free()
{
    char *ptr = contentPtr;
    if (ptr != 0)
    {
        for (int i = 0; i < length; ++i)
            alloc.destroy(ptr++);
        alloc.deallocate(contentPtr, length);
    }
}

MyString::~MyString()
{
    free();
}