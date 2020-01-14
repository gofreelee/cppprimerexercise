#include <iostream>
#include <string>
void readWord(std::string &str)
{
    std::cin >> str;
}

void readLine(std::string &str)
{
    getline(std::cin, str);
}

int main()
{
    std::string str;
    readWord(str);
    std::cout<<str<<std::endl;
    std::cout<<"*****";
     
    std::string strLine;
    readLine(strLine);
    std::cout<<strLine<<std::endl;
    
}