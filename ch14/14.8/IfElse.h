struct IfElse
{
    int operator()(bool flag, int one, int theOther)
    {
        return flag ? one : theOther;
    }
};