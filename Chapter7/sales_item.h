#include <iostream>
#include <string>
#ifndef SALES_ITEM_H
#define SALES_ITEM_H

class Sales_item
{

friend Sales_item add(const Sales_item &lhs, const Sales_item &rhs);
friend std::ostream &print(std::ostream &os, const Sales_item &item);
friend std::istream &read(std::istream &is, Sales_item &item);
public:
    Sales_item() = default;
    Sales_item(const std::string &str) : bookNo(str) { }
    Sales_item(const std::string &str, unsigned n, double(p)) :
            bookNo(str), units_sold(n), revenue(n * p) { }
    Sales_item(std::istream &is);

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
std::istream &read(std::istream &is, Sales_item &item);

void sales_item_test();

#endif // SALES_ITEM_H
