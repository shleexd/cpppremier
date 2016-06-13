#include <string>
#include <iostream>
#ifndef HASPTR_H
#define HASPTR_H


class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) { }
    //HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)),
    //                                i(rhs.i) {  }
    std::string strNo() { return *ps; }
    ~HasPtr(){ delete ps; }
private:
    std::string *ps;
    int i;
};

void hasptr();

#endif // HASPTR_H
