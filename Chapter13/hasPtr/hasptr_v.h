#include <string>
#include <iostream>
#ifndef HASPTR_H
#define HASPTR_H


//class that act like values.
class HasPtr_v
{
friend void swap(HasPtr_v &lhs, HasPtr_v &rhs);
public:
    HasPtr_v(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) { }
    ~HasPtr_v(){ delete ps; }

    //assignement operator.
    HasPtr_v &operator= (const HasPtr_v &rhs);
    HasPtr_v(const HasPtr_v &rhs) : ps(new std::string(*rhs.ps)),
                                    i(rhs.i) {  }
    std::string strNo() { return *ps; }
private:
    std::string *ps;
    int i;
};

void hasptr_v();
void swap(HasPtr_v &lhs, HasPtr_v &rhs);

#endif // HASPTR_H
