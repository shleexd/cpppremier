#include "strblob.h"
#include "strblobptr.h"

StrBlob::StrBlob()
        : data(std::make_shared<std::vector<std::string>>())
{

}

StrBlob::StrBlob(std::initializer_list<std::string> i1)
      : data(std::make_shared<std::vector<std::string>>(i1)){

}

void StrBlob::pop_back()
{
   check(0, "pop on empty StrBlob.");
   data->pop_back();
}

 std::string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
 }

 std::__cxx11::string &StrBlob::front() const
 {
    check(0, "front on empty StrBlob");
    return data->front();
 }

 std::string &StrBlob::back()
{
    check(0, "back on empty StrBlob.");
    return data->back();
 }

 std::__cxx11::string &StrBlob::back() const
 {
    check(0, "back on empty StrBlob.");
    return data->back();
 }

 StrBlobPtr StrBlob::begin()
 {
     return StrBlobPtr(*this);
 }

 StrBlobPtr StrBlob::end()
 {
     auto ret = StrBlobPtr(*this, data->size());
     return ret;
 }

void StrBlob::check(StrBlob::size_type i, const std::string &msg) const
{
   if(i >= data->size())
       throw std::out_of_range(msg);
}
