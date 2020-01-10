int main()
{
    int num = 99;
    int *ptr = &num;
    *ptr = 100;
    int num2 = 101;
    ptr = &num2;
}