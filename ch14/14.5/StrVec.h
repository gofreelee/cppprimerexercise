#include <string>
#include <memory>
#include <map>
#include <algorithm>
#include <initializer_list>
class StrVec
{
public:
    StrVec() : elements(nullptr), firstFree(nullptr), cap(nullptr) {}
    StrVec(const std::initializer_list<std::string> &list)
    {
        auto dataPair = allocNCopy(list.begin(), list.end());
        elements = dataPair.first;
        firstFree = cap = dataPair.second;
    }
    StrVec(const StrVec &);
    StrVec(StrVec &&) noexcept;
    StrVec &operator=(const StrVec &);
    StrVec &operator=(StrVec &&) noexcept;
    const std::string &operator[](std::size_t index) const
    {
        return elements[index];
    }
    std::string &operator[](std::size_t index)
    {
        return elements[index];
    }
    ~StrVec();
    void pushBack(const std::string &);
    void pushBack(std::string &&);
    size_t size() const
    {
        return firstFree - elements; //已经分配了多少元素
    }
    size_t capacity() const
    {
        return cap - elements;
    }

    std::string *begin() const { return elements; }
    std::string *end() const { return firstFree; }

private:
    static std::allocator<std::string> alloc;
    void chkNAlloc()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<std::string *, std::string *> allocNCopy(const std::string *, const std::string *);
    void free();
    void reallocate();
    std::string *elements;
    std::string *firstFree;
    std::string *cap;
};