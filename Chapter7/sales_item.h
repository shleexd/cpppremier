#include <iostream>
#include <string>
#ifndef SALES_ITEM_H
#define SALES_ITEM_H

class Sales_item
{

friend Sales_item add(const Sales_item &lhs, const Sales_item &rhs);
friend std::ostream &print(std::ostream &os, const Sales_item &item);
friend std::istream &read(std::istream &is, Sales_item &item);
friend std::ostream &operator << (std::ostream &os, const Sales_item &item);
friend std::istream &operator >> (std::istream &is, Sales_item &item);
friend Sales_item operator+ (const Sales_item &lhs, const Sales_item &rhs);

public:
    Sales_item() = default;
    explicit Sales_item(const std::string &str) : bookNo(str) { }
    Sales_item(const std::string &str, unsigned n, double(p)) :
            bookNo(str), units_sold(n), revenue(n * p) { }
    explicit Sales_item(std::istream &is);

    std::string isbn() const { return bookNo; }
    Sales_item &combine(const Sales_item &item);
    //overload operator += to act like function combine.
    Sales_item &operator+= (const Sales_item &rhs);
    double avg_price() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

Sales_item add(const Sales_item &lhs, const Sales_item &rhs);
//overload operator + to act like function add.
Sales_item operator+ (const Sales_item &lhs, const Sales_item &rhs);

std::ostream &print(std::ostream &os, const Sales_item &item);
//overload operator << to act like function print.
std::ostream &operator << (std::ostream &os, const Sales_item &item);

std::istream &read(std::istream &is, Sales_item &item);
//overload operator >> to act like function read.
std::istream &operator >> (std::istream &is, Sales_item &item);

void sales_item_test();

#endif // SALES_ITEM_H
