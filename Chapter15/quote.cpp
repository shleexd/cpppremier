#include "quote.h"

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.price * n;
    os << "ISBN : " << item.isbn() <<
          " # sold: " << n << " total due " << ret << std::endl;
    return ret;
}
