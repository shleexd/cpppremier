#include <iostream>
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>
#include <strings.h>

class StrBlob
{
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
    size_type size() { return data->size();}

private:
    //a smart pointer pointing to a container that contains strings.
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};
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

void StrBlob::check(StrBlob::size_type i, const std::string &msg) const
{
   if(i >= data->size())
       throw std::out_of_range(msg);
}

/*
//class template Blob.
template <typename T> class Blob{
public:
    typedef typename std::vector<T>::size_type size_type;
    //constructors.
    Blob();
    Blob(std::initializer_list<T> i1);

    //data informations in Blob.
    size_type size(){ return data->size(); }
    bool empty() { return data->empty();}

    //add and remove elements.
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t){
        data->push_back(std::move(t));
    }
    void pop_back();

private:
    //holding elements in vector.
    std::shared_ptr<std::vector<T>> data;
};


template <typename T>
void Blob<T>::pop_back()
{

}
*/
int main(void){
#define NUM_12_1
#ifdef NUM_12_1
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        std::cout << b2.back() << std::endl;
    }
    //now b1 has 4 items, while b2 is distroyed.
#endif
    return 0;
}
