#include "sales_item.h"


Sales_item::Sales_item()
{
}

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
