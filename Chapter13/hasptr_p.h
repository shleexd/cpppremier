#include <string>
#ifndef HASPTR_P_H
#define HASPTR_P_H


//class that act like pointer.
class HasPtr_p
{
public:
    HasPtr_p(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0), user(new std::size_t(1)) { }
    ~HasPtr_p(){
        if(--*user == 0){
            delete ps;
            delete user;
        }
    }

    //copy assigne operator.
    HasPtr_p(const HasPtr_p &rhs) :
                    ps(rhs.ps), i(rhs.i), user(rhs.user) { ++*user; }

    //assignement operator.
    HasPtr_p &operator= (const HasPtr_p &rhs);

    std::string strNo() { return *ps; }
    std::size_t getUser() const;

private:
    std::string *ps;
    int i;
    std::size_t *user;
};

void hasPtr_p();
#endif // HASPTR_P_H
