
#include <initializer_list>
#include <string>
#include <memory>
#include <vector>
//#include "strblobptr.h"

#ifndef STRBLOB_H
#define STRBLOB_H

class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    //constructor
    StrBlob();
    StrBlob(std::initializer_list<std::string> i1);

    //add and remove elements.
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    //get elements and size.
    std::string& front();
    std::string& front() const;
    std::string& back();
    std::string& back() const;
    //return StrBlibPtr to the first and the last element.
    inline StrBlobPtr begin();
    inline StrBlobPtr end();
    size_type size() { return data->size();}

private:
    //a smart pointer pointing to a container that contains strings.
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

#endif // STRBLOB_H
