#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findEx(){
    vector<int> vec{34, 43,234, 5343};
    int val = 43;
    //若找到，则返回结果指向它，否则返回结果为vex.cend()。
    auto result = find(vec.cbegin(), vec.cend(), val);
    cout << "the result" << ( (result == vec.cend())
            ? " is present" : " not present." )<< endl;
}

int main( )
{
    findEx();
    return 0;
}
