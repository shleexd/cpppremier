#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//只读算法包括find, count, accumulate, equal。

//find算法接受三个参数。前两个表示迭代范围，第三个为要找的值。
void findEx(){
    vector<int> vec{34, 43,234, 5343};
    int val = 43;
    //若找到，则返回结果指向它，否则返回结果为vex.cend()。
    auto result = find(vec.cbegin(), vec.cend(), val);
    cout << "the result" << ( (result == vec.cend())
            ? " is present" : " not present." )<< endl;
    auto cnt = count(vec.cbegin(), vec.cend(), val);
    cout <<  "the valut" << val << " present " << cnt << " time(s)" << endl;
}


 //对目标范围求和，初始值是0。
void acc(){
    vector<int> vec{34, 43,234, 5343};
    //对目标范围求和，初始值是0。
    int result = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << "the result is " << result << endl;
}

//qual 把第一个容器制定范围的数与第二个容器指定起点往后的元素进行比较。
//重要前提：指定了第二个序列至少与第一个一样长。
void eql(){
    vector<int> vec1{34, 43,345, 5343};
    vector<int> vec2{34, 43,345, 5343, 3333};

    auto eq = equal(vec1.cbegin(), vec1.cend(), vec2.cbegin());
    cout << "vec1 " << (eq ? "is" : " is not ") << "equal to vec2" << endl;

}


//写算法。
//包括fill,back_inseter,fill_n,copy,replace,
//注意，由于泛型算法本身不执行容器操作，所以写入的数目确保不大于容器的容量。

//以指定的值填满指定范围,本质上是不危险的。但是fill_n需要自身确保写入的数量小于
//指定范围所能装下的数量k。
void fillEx(){
    vector<int> vec1{34, 43,345, 5343};
    fill(vec1.begin(), vec1.end(), 0);
    for(auto &i : vec1)
        cout << i << " " ;
}

//back_inserter.会调用push_back在尾后插入一个值。
void bkInserter(){
    vector<int> vec1{34, 43,345, 5343};
    auto it = back_inserter(vec1);//这一步已经push了进去，并返回一个迭代器引用。
    *it = 344;					  //指定该元素的值。
    for(auto &i : vec1)
        cout << i << " " ;
}

//copy算法，接受三个迭代器。
//注意：目的序列至少包含与输入序列一样多的元素。
void cp(){
   int a1[]  = {3,4,5,6,7,8,9,11};
   int a2[sizeof(a1) / sizeof(*a1)];//a2 与a1一样大小。

   auto ret = copy(begin(a1), end(a1), a2);//把a1拷贝给a2.。.
}

//replace算法。搜索容器中所有与给定值相等的元素并置换成新值。
void rpl(){
    vector<int> vec1{34, 43,345, 5343};
    replace(vec1.begin(), vec1.end(), 43, 33);
    for(auto &i : vec1)
        cout << i << " " ;
}
//replace_copy算法，原理同上，但是不改变原有的值，
//而是会复制一份副本。
void rpl_copy(){
    vector<int> vec1{34, 43,345, 5343};
    vector<int> vec2;
    replace_copy(vec1.begin(), vec1.end(), back_inserter(vec2), 34, 33);
    for(auto &i : vec2)
        cout << i << " " ;
}



//重排元素的算法。

int main( )
{
//    findEx()r
//    acc();
//    eql();
//    fillEx();
//    bkInserter();
//    rpl();
    rpl_copy();
    return 0;
}
