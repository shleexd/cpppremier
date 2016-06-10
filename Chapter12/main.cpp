#include <iostream>
#include "strblob.h"
#include "strblobptr.h"

int main(void){
    StrBlob text;
    std::string word;
    while(std::cin >> word )
        text.push_back(word);
    StrBlobPtr text_ptr(text);
    while(1){
        try{
            std::cout << text_ptr.deref() << std::endl;
            text_ptr.incr();
        } catch(std::out_of_range err){
            break;
        }
    }
    return 0;

}
