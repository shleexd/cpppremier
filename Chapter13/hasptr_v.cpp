#include "hasptr_v.h"


void hasptr_v()
{
    HasPtr_v *hp = new HasPtr_v("Hello World");
    HasPtr_v hp1 = *hp;
    HasPtr_v hp2;
    hp2 = *hp;
    //std::cout << hp1.strNo() << std::endl;
    delete hp;
    std::cout << hp1.strNo() << std::endl;
    std::cout << hp2.strNo() << std::endl;

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

