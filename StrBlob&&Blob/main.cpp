#include <iostream>
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>
#include <strings.h>

using namespace std;
class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> i1);

    size_type size() { return data->size();}
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();

    string& front();
    string& back();

private:
    //a smart pointer pointing to a container that contains strings.
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg);
};
StrBlob::StrBlob()
        : data(make_shared<vector<string>>())
{

}

StrBlob::StrBlob(initializer_list<string> i1)
      : data(make_shared<vector<string>>(i1)){

}

void StrBlob::pop_back()
{
   check(0, "pop on empty StrBlob.");
   data->pop_back();
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob.");
    return data->back();
}

void StrBlob::check(StrBlob::size_type i, const string &msg)
{
   if(i >= size())
       throw out_of_range(msg);
}

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

int main(void){
#ifdef STRBLOB
    StrBlob *blob = new StrBlob({"hello,world."});
    blob->push_back("new");
    cout << blob->size() << endl;
#endif
    return 0;
}
