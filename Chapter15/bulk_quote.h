#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "disc_quote.h"
#include "quote.h"


class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote( const std::string &book, double sales_price,
                std::size_t qty, double disc) :
        Disc_quote(book, sales_price, qty, disc){ }
    double net_price(std::size_t n) const override;
};

#endif // BULK_QUOTE_H
