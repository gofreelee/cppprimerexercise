#include "StrVec.h"
std::allocator<std::string> StrVec::alloc;
void StrVec::pushBack(const std::string &str)
{

    chkNAlloc();
    alloc.construct(firstFree++, str);
}

void StrVec::pushBack(std::string &&rref)
{
    chkNAlloc();
    alloc.construct(firstFree++, std::move(rref));
}
std::pair<std::string *, std::string *>
StrVec::allocNCopy(const std::string *begin, const std::string *end)
{
    auto data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
}

void StrVec::free()
{
    //先析构对象,再回收内存
    if (elements != nullptr)
    {
        for (auto ptr = elements; ptr != firstFree; ptr++)
            alloc.destroy(ptr);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &res)
{
    auto newMem = allocNCopy(res.begin(), res.end());
    elements = newMem.first;
    firstFree = cap = newMem.second;
}

StrVec &StrVec::operator=(const StrVec &res)
{
    free();
    auto newMem = allocNCopy(res.begin(), res.end());
    elements = newMem.first;
    firstFree = cap = newMem.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rref) noexcept
{
    if (this != &rref)
    {
        elements = rref.elements;
        firstFree = rref.firstFree;
        cap = rref.cap;
        rref.elements = rref.firstFree = rref.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec()
{
    free();
}

StrVec::StrVec(StrVec &&rref) noexcept : elements(rref.elements), firstFree(rref.firstFree), cap(rref.cap)
{
    rref.elements = nullptr;
    rref.firstFree = nullptr;
    rref.cap = nullptr;
}

void StrVec::reallocate()
{
    int newSize = size() != 0 ? 2 * size() : 1;
    auto newElement = alloc.allocate(newSize);
    for (auto elem = elements; elem != firstFree; ++elem)
        alloc.construct(newElement++, std::move(*elem));
    //构造完元素
    free();
    elements = newElement - (newSize / 2);
    firstFree = newElement;
    cap = elements + newSize;
}
