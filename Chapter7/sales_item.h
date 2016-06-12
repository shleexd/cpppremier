#include <string>
#ifndef SALES_ITEM_H
#define SALES_ITEM_H

struct sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

#endif // SALES_ITEM_H
