#include <iostream>
#include <string>
class GetInput
{
public:
    GetInput():os(std::cout),is(std::cin),str("")
    {

    }
    const std::string& operator()()
    {
        is >> str;
        os << str;
        return str;
    }
private:
    std::ostream &os;
    std::istream &is;
    std::string str;
};

int main()
{
    GetInput getInput;
    getInput();
}