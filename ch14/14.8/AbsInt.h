struct AbsInt
{
    int operator()(int num)
    {
        return num > 0 ? num : -num;
    }
};
