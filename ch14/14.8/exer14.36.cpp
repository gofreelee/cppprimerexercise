#include <iostream>
#include <string>
#include <vector>
using std::vector;
class GetInput
{
public:
    GetInput() : os(std::cout), is(std::cin), str("")
    {
    }
    const std::string &operator()()
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
    vector<std::string> vec;
    GetInput getInput;
    for (int i = 0; i < 10; ++i)
        vec.push_back(getInput());
    for (int i = 0; i < 10; ++i)
    {
        std::cout << vec[i] << std::endl;
    }
}