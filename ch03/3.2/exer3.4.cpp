#include <iostream>
#include <string>

std::string bigStr(std::string str1, std::string str2)
{
    return str1 > str2 ? str1 : str2;
}

std::string bigLength(std::string str1, std::string str2)
{
    return str1.size() > str2.size() ? str1 : str2;
}

int main()
{
    std::string str1, str2;
    std::cout << "str1: ";
    std::cin >> str1;
    std::cout << "str2: ";
    std::cin >> str2;
    std::cout << "*******************\n";
    std::cout << bigStr(str1, str2)<<std::endl;
    std::cout << bigLength(str1,str2)<<std::endl;

}