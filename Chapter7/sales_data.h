#include <string>
#include <iostream>
#ifndef SALES_DATA_H
#define SALES_DATA_H

struct sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

std::istream &read(std::istream &is, sales_data &data);
void combine(sales_data &lhs, const sales_data &rhs);
std::ostream &print(std::ostream &os, const sales_data &data);
void trans_pro();
#endif // SALES_ITEM_H
