class Debug
{
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(b) {}

private:
    bool hw;
    bool io;
    bool other;
};