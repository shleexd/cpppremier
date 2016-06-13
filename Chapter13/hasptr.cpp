#include "hasptr.h"



void hasptr()
{
    HasPtr *hp = new HasPtr("Hello World");
    HasPtr hp1 = *hp;
    HasPtr hp2;
    hp2 = *hp;
    std::cout << hp1.strNo() << std::endl;
    delete hp;
    std::cout << hp1.strNo() << std::endl;
    std::cout << hp2.strNo() << std::endl;

}
