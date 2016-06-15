#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "quote.h"


class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    double net_price(std::size_t n) const override;
};

#endif // BULK_QUOTE_H
