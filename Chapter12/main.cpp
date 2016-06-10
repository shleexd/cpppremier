#include <iostream>
#include "strblob.h"

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
