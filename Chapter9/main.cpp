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
    vec_dbl.emplace_back(32);
    //it would be slow to insert to any place expect end of a vector.
    vec_dbl.insert(vec_dbl.begin(), 22);
    vec_dbl.insert(vec_dbl.end(), 43, 6);
    vec_dbl.erase(vec_dbl.begin() + 3, vec_dbl.end());
    string::size_type cap = vec_dbl.capacity();

    for(auto &i : vec_dbl){
        cout << i << " ";
    }
    cout << endl;
    cout << "capacity:" << cap << endl;
}

int main(void)
{
    exc_9_13();
    return 0;
}
