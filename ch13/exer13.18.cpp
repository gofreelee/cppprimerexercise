#include <string>
#include <iostream>
class Employee
{
public:
    Employee() : Id(staticId)
    {
        ++staticId;
    }
    Employee(std::string parm) : name(parm), Id(staticId)
    {
        ++staticId;
    }
    Employee(const Employee &res) = delete;
    Employee &operator=(const Employee &) = delete;
    std::string name;
    int Id;
    static int staticId;
};
int Employee::staticId = 0;

int main()
{
    Employee employee[10];
    for (int i = 0; i < 10; ++i)
        std::cout << employee[i].Id;
}