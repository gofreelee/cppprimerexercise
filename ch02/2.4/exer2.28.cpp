int main()
{
    //int i, *const cp;  cp要初始化
    //int *p1,*const p2;    p2要初始化
    //const int ic, &r = ic; ic 是常量,需要初始化
    //const int *const p3; 初始化
    int const a = 12;
    const int *p = nullptr;
    constexpr int *p = nullptr;
    constexpr int i = 0;
    constexpr int null = 0,*p = null;
    typedef int *ptr;
    int aaa = 90;
    const ptr pp= &aaa;
    const int* ppp = &a;
    int &const sss = aaa;
    
   
   // int* pp = p;
}