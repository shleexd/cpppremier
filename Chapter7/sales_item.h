#include <string>
#ifndef SALES_ITEM_H
#define SALES_ITEM_H
#define NUM7_1
#ifdef NUM7_1
class Sales_item
{
public:
    Sales_item();

    std::string isbn() const { return bookNo; }
    Sales_item &combine(const Sales_item &item);
    double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

Sales_item add(const Sales_item &lhs, const Sales_item &rhs);
std::ostream &print(std::ostream &os, const Sales_item &item);
std::istream &read(std::istream&, Sales_item&);
#endif
#endif // SALES_ITEM_H
