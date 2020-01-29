#include<vector>
#include<iostream>
class Example
{
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static std::vector<double> vec;
private:
};
std::vector<double> Example::vec ;
int main()
{
    std::cout<< Example::vec.size();
}