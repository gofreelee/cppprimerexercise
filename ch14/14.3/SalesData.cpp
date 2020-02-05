#include "SalesData.h"

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

SalesData &SalesData::operator+=(const SalesData &ref)
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

std::ostream &operator<<(std::ostream &os, const SalesData &item)
{

    os << item.isbn() << " " << item.unitsSold << " "
       << item.revenue << " " << item.avg_prices();
    return os;
}

std::istream &operator>>(std::istream &is, SalesData &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.unitsSold >> price;
    item.revenue = item.unitsSold * price;
    return is;
}

SalesData operator+(const SalesData &lref,const SalesData &rref)
{
    SalesData newSale = lref;
    newSale+=rref;
    return newSale;

}