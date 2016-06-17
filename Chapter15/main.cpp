#include <iostream>
#include "bulk_quote.h"
#include "quote.h"

using namespace std;

int main()
{
    Quote book("9777-4555-1222", 34);
    Bulk_quote book_bulk("1223-4244-2333", 34, 4, 0.1);
    print_total(cout, book, 5);
    print_total(cout, book_bulk, 5);
    return 0;
}
