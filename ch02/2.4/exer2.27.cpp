int main()
{
    //int i = -1, &r = 0;  引用必须与一个变量绑定,而不是字面量
    int i2 = 11;
    int *const p2 = &i2;
    const int i = -1,&r = 0; //const 引用可以绑定一个字面量
    const int *const p3 = &i2;
    const int *p1 = &i2;
    //const int *const r2;  要初始化
    const int i2 = i, &r = i;
}