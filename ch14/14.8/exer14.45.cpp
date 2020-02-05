
#include <string>
#include <iostream>
class SalesData
{
    friend SalesData add(const SalesData &, const SalesData &);
    friend std::istream &read(std::istream &, SalesData &);
    friend std::ostream &print(std::ostream &, const SalesData &);

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
    SalesData &combine(const SalesData &res);
    double avg_prices() const
    {
        return revenue / unitsSold;
    }
    explicit operator std::string() const
    {
        return bookNo;
    }
    operator double() const
    {
        return revenue;
    }

private:
    std::string bookNo;
    unsigned unitsSold = 0;
    double revenue = 0.0;
};

SalesData add(const SalesData &, const SalesData &);
std::ostream &print(std::ostream &, const SalesData &);
std::istream &read(std::istream &, const SalesData &);

SalesData::SalesData(std::istream &is) : SalesData()
{
    read(is, *this);
}

SalesData::SalesData(const SalesData &res) : bookNo(res.bookNo), unitsSold(res.unitsSold), revenue(res.revenue)
{
}

SalesData &SalesData::combine(const SalesData &ref)
{
    unitsSold += ref.unitsSold;
    revenue += ref.revenue;
    return *this;
}

std::istream &read(std::istream &is, SalesData &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.unitsSold >> price;
    item.revenue = item.unitsSold * price;
    return is;
}

std::ostream &print(std::ostream &os, const SalesData &item)
{
    os << item.isbn() << " " << item.unitsSold << " "
       << item.revenue << " " << item.avg_prices();
    return os;
}

SalesData add(const SalesData &lref, const SalesData &rref)
{
    SalesData sum = lref;
    sum.combine(rref);
    return sum;
}

int main()
{
    SalesData sale;
    int a = sale;
    std::string str = static_cast<std::string>(sale); //可以转换
}