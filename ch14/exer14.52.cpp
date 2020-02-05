class SmallInt
{
public:
    SmallInt() = default;
    SmallInt(int val) : num(val) {}
    operator int() const
    {
        if (num < 256)
            return num;
        else
            return 999;
    }

private:
    int num;
};

struct LongDouble
{
    LongDouble(double = 0.0);
    operator double();
    //operator float();
    LongDouble operator+(const SmallInt &ref);
};
LongDouble operator+(const LongDouble&,double);
int main()
{
    SmallInt si;
    LongDouble ld;
    ld =  si + ld ;
}