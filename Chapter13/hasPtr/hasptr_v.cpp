#include "hasptr_v.h"
#include <iostream>

void hasptr_v()
{
    HasPtr_v v1("I am v1.");
    HasPtr_v v2("I am v2.");
    std::cout << "v1: " << v1.strNo() << std::endl;
    std::cout << "v2: " << v2.strNo() << std::endl;
    swap(v1, v2);
    std::cout << "v1: " << v1.strNo() << std::endl;
    std::cout << "v2: " << v2.strNo() << std::endl;
}

HasPtr_v &HasPtr_v::operator=(const HasPtr_v &rhs)
{
    //handle assignment to itself.
    std::string *pOrig = ps;
    ps = new std::string(*rhs.ps);
    delete pOrig;

    i = rhs.i;
    return *this;
}


void swap(HasPtr_v &lhs, HasPtr_v &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}
