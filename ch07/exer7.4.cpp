#include <string>
class Person
{
public:
    std::string salary;
    std::string address;
    Person(const std::string &salary_, const std::string address_)
        : salary(salary_), address(address_) {}
    std::string getSalary() const
    {
        return salary;
    }
    std::string getAddress() const
    {
        return address;
    }
};