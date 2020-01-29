#include<iostream>
class NoDefault
{
public:
    NoDefault(int n) : num(n){}
    int num;
};
class C
{
public:
    C():elem(12)
    {

    }
    NoDefault elem;
};
int main()
{
    C c;
    std::cout<< c.elem.num;
}