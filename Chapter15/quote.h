#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote
{
friend double print_total(std::ostream &os,
                          const Quote &item, std::size_t n);
public:
    Quote() = default;
    Quote( const std::string &book, double sales_price) :
            bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const
            { return n * price; }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

double print_total(std::ostream &os,const Quote &item, std::size_t n);

#endif // QUOTE_H
