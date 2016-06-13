#include <iostream>
#include "hasptr_p.h"

HasPtr_p &HasPtr_p::operator=(const HasPtr_p &rhs)
{
    ++*rhs.user;

    //handle self-assignment.
    if(--*user == 0){
        delete ps;
        delete user;
    }

    ps = rhs.ps;
    i = rhs.i;
    user = rhs.user;
    return *this;
}

std::size_t HasPtr_p::getUser() const
{
    return *user;
}

void hasPtr_p()
{
    HasPtr_p p1("hello.");
    std::cout << p1.getUser() << std::endl;
    HasPtr_p p2 = p1;
    std::cout << p1.getUser() << std::endl;
}
