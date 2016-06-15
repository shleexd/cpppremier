#include <iostream>
#include "bulk_quote.h"
#include "quote.h"

using namespace std;

int main()
{
    Quote book("9777-4555", 34);
    print_total(cout, book, 4);
    return 0;
}
