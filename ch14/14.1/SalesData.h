
#include <string>
#include <iostream>
class SalesData
{
    friend SalesData add(const SalesData &, const SalesData &);
    friend std::istream &read(std::istream &, SalesData &);
    friend std::ostream &print(std::ostream &, const SalesData &);
    friend std::ostream &operator<<(std::ostream &, const SalesData &);
    friend std::istream &operator>>(std::istream &, SalesData &);

public:
    SalesData() : SalesData("", 0, 0) {}
    SalesData(const std::string &s) : SalesData(s, 0, 0) {}
    SalesData(const std::string &s, unsigned soldNum, double price)
        : bookNo(s), unitsSold(soldNum), revenue(unitsSold * price)
    {
    }
    SalesData(std::istream &is);
    SalesData(int num) : SalesData()
    {
    }
    SalesData(const SalesData &); //拷贝构造函数
    std::string isbn() const
    {
        return bookNo;
    }
    SalesData &operator+(const SalesData &res);
    SalesData &combine(const SalesData &res);
    double avg_prices() const
    {
        return revenue / unitsSold;
    }

private:
    std::string bookNo;
    unsigned unitsSold = 0;
    double revenue = 0.0;
};

SalesData add(const SalesData &, const SalesData &);
std::ostream &print(std::ostream &, const SalesData &);
std::istream &read(std::istream &, const SalesData &);
std::ostream &operator<<(std::ostream &, const SalesData &);
std::istream &operator>>(std::istream &, SalesData &);
