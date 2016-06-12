#include "sales_item.h"
#include <iostream>

 //read a transaction fron is into this object.
Sales_item::Sales_item(std::istream &is)
{
   read(is, *this);
}

//combine another object into this object.
Sales_item &Sales_item::combine(const Sales_item &item)
{
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;
}

double Sales_item::avg_price() const
{
   if(units_sold)
       return revenue / units_sold;
   else
       return 0;
}

//add two objects an return a new object.
Sales_item add(const Sales_item &lhs, const Sales_item &rhs)
{
    Sales_item sum = lhs;
    sum.combine(rhs);
    return sum;
}

//read data from input formated as "bookNo units_sold price"
std::istream &read(std::istream &is, Sales_item &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_item &item)
{
    os << "bookNo : " << item.isbn() << " acount: " << item.units_sold << " total revenue: "
       << item.revenue << " avg_price: " << item.avg_price();
    return os;
}

void sales_item_test()
{
    Sales_item total;
    if(read(std::cin, total)){
        Sales_item tran;
        while(read(std::cin, tran)){
            if(total.isbn() == tran.isbn()){
                total.combine(tran);
            }
            else{
                print(std::cout, total);
                total = tran;
            }
        }
    }
    else{
        std::cout << "No data?" << std::endl;
    }
}
