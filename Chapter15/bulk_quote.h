#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "quote.h"


class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote( const std::string &book, double sales_price,
                std::size_t qty, double disc) :
        Quote(book, sales_price), min_qty(qty), discount(disc) { }
    double net_price(std::size_t n) const override;
private:
    std::size_t min_qty;
    double discount;
};

#endif // BULK_QUOTE_H
