#include "SalesData.h"

SalesData::SalesData(std::istream &is) : SalesData()
{
    read(is, *this);
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