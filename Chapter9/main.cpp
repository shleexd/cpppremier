#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

void exc_9_13(void){
    list<int> ls_int = { 32, 43, 53, 32, 43};

    //vector<double> vec_dbl(ls_int.cbegin(), ls_int.cend());
    vector<double> vec_dbl;
    vec_dbl.assign(ls_int.cbegin(), ls_int.cend() );

    for(auto &i : vec_dbl){
        cout << i << " ";
    }
    cout << endl;
}

int main(void)
{
    exc_9_13();
    return 0;
}
