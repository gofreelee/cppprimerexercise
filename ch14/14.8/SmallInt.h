class SmallInt
{
public:
    SmallInt() = default;
    SmallInt(int val):num(val){}
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

