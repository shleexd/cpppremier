#include "strblobptr.h"


std::__cxx11::string StrBlobPtr::deref() const
{
    auto p = check(curr, "derefence past end.");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increaement past end of strblobptr.");
    ++curr;
    return *this;
}

std::shared_ptr<std::vector<std::__cxx11::string> >
        StrBlobPtr::check(std::size_t i, const std::__cxx11::string &msg) const
{
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr.");
    if(i >= ret->size())
        throw std::out_of_range(msg);
    return ret;

}
