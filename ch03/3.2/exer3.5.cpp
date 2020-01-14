#include<iostream>
#include<string>
int main()
{
    std::string tmp;
    std::string longStr;
    while(std::cin >> tmp)
    {
        longStr.append(tmp);
    }
    std::cout<< longStr;
}