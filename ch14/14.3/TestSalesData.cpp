#include"SalesData.h"
int main()
{
    SalesData sales;
    SalesData sale2("cpp",9,99);
    SalesData sale3("java");
    SalesData sale4(1);
    std::string s = "kobe";
    sale2.combine(std::cin);
    print(std::cout, sale2);
}