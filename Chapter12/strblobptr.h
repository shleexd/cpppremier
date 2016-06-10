#include <memory>
#include "strblob.h"
#include <vector>
#include <string>
#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

class StrBlob;
class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, std::size_t sz = 0) :
                wptr(a.data), curr(sz){ }

    std::string deref() const; //get current element.
    StrBlobPtr& incr();        //increase current position within the attay.
private:
    //check returns a shared_ptr to the vector if check succeeds.
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t i, const std::string&msg) const;

    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;          //current position within the array.
};

#endif // STRBLOBPTR_H
