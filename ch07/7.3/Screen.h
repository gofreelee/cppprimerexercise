#include <string>
#include <iostream>
class Screen
{
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd, char c)
        : height(ht), width(wd), contents(ht * wd, c)
    {
    }
    char get() const
    {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen &set(char);
    Screen &set(pos x, pos y, char c);
    Screen &move(pos r, pos c);
    void someMember() const;
    Screen &display(std::ostream &os)
    {
        doDisplay(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t accessCtr;
    void doDisplay(std::ostream &os) const
    {
        os << contents;
    }
};

char Screen::get(pos ht, pos wd) const
{
    pos row = ht * width;
    row += wd;
    return contents[row];
}

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    this->cursor = row + c;
    return *this;
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos x, pos y, char c)
{
    pos index = x * width;
    index += y;
    contents[y] == c;
    return *this;
}