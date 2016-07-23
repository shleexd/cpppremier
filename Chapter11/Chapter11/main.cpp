#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
void mapSetOrder(){
    map<string, size_t> word_count;
    set<string> exclude = {
        "the", "a" , "new"
    };
    string word;
    while( cin >> word){
        if(exclude.find(word) == exclude.end())
        ++ word_count[word];
    }
    for(const auto &s : word_count){
        cout << s.first << " occurs " << s.second
             << " times " << endl;
    }
}

void multi(void){
    vector<int> ivec;
    for(vector<int>::size_type i = 0; i <= 9; ++i){
        ivec.push_back(i);
        ivec.push_back(i);
    }
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> muiset(ivec.cbegin(), ivec.cend());

    cout << ivec.size() << endl;
    cout << iset.size() << endl;
    cout << muiset.size() << endl;
}

int main( )
{
//    mapSetOrder();
    multi();
    return 0;
}
