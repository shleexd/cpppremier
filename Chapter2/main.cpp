#include <iostream>
#include "chapter2.h"

//2.12. Typeconversions.
int exti = 3;
void build_in_types(){
//nonbool to bool
bool b = 42;    		 //b is true.
//bool to nonbool
int i = b;	     		//i has value 1.
//floating-point to integral. the value is truncated.
int intj = 3.14;    	//j has value 3.
//integral to floating-point,the fractional part is zero.
double dbd = 3;    		//dbd has value 3.
double dbj = 0xffffffff;//Precision would be lost.

//Assigning out-of-range value.
//To an unsigned object.
unsigned char uchara = -1;//(int ) uchara has value 255.
//to a signed object
char schara = 130;        //It works, but produce a garbage value.


//2.2.  variables
//initialization.
int unit_sold = 1;
int unit_sold1 = {1};
int unit_sold2{1};        //list initialization/
int unit_sold3(1);
long double ld = 3.14159;
int ald{ld},bld = {ld};    //error:narrowing convertion not allow.
}


//2.3. Compound Types.
void compound_types_ref(void){
#ifdef NUM1
    int ival = 210;
    int &refVal = ival;      //refVal refers(is another name of ival.
    //int &refVal2;          // error: refenrence must be initial.
    refVal = 2; 			 // ival now is 2./
    //reference initializer must be an object,not a literal,
    //and match exactly.
    //int &refVal = 2;
    //double dval = 3.14;     //error
    //int &refVal = dval;	  //error
#endif

    //exercises
#ifdef NUM2_15
    //2.15
    int ival = 1.01;		//valid, defination of object.
    //int &rval1 = 1.01;    //invalid, reference to a literal.
    int &refVal = ival;		//valid, reference to ival.
    //int &refVal3;			//invalid, a reference must be initializer.
#endif

    //2.16
#ifdef NUM2_16
    int i = 0,&r1 = i; double d = 0, &r2 = d;
    r2 = 3.14;				//valid, assign 3.14 to d.
    r2 = r1;				//valid, assign r1 to r2.
    i = r2;					//valid, assign r2 to i.
    r1 = d;					//the same as i = r2.
#endif

    //2.17
#ifdef NUM2_17
    int i, &ri = i;
    i = 5; ri = 10;
    std::cout << i << " " << ri << std::endl;
#endif

}

//2.4.const qualifier.
void const_qualifier(){
    const int buffSize = 512;
    //buffSizei = 51;       //error: attemp to write to const object

    const int ci = 1024;
    const int &ri = ci;
    //ri = 41;     //error: ri is a reference to const.
    //int &r2 = ci;//error: r2 is a non const to a const object.

    //we can initialize a reference to const from any expressions
    //that can be converted to a nonconst object, a literal or a gen
    //eral expression.
    int i = 42;
    const int &r1 = i; //const reference to i;
    const int &r2 = 42;//OK: 42 can be convert to int.
    //int &r4 = i * 2;   //error: r4 is a plain, non const reference.

    //2.4.2 Pointers and const.

    //pointer to const.
    const double pi = 3.1415;
    //double *ptr = &pi; //error:ptr is a plain pointer.
    const double *ptr1 = &pi; //OK.
    //*ptr1 = 32;      //*ptr is const.
    double dval = 2;
    ptr1 = &dval;      //OK,a pointer to const to point to a noncons//t
    //const poiter.
    //*putting the const after *.
    int errNumb = 0;
    int *const curErr = &errNumb; //curErr always point to errNu.
    //const double *const cpi = 3.1314;
    const double *const pip = &pi;
}

void dealing_with_types(){
    typedef double wages;         //wages is a synonym for double.
    typedef wages base, *p; //base for double, p for double*.

    using SI = double;

    typedef char *pstring;   //pstring for char*.
    const pstring cstr = 0;  //cstr is a constant pointer to char.
    const pstring *ps;       //ps is a pointer to const pointer .
                            // not a pointer to const char.
    //2.5.2 the auto type specifier.
    //must have an initializer.

    //2.5.3 The decltype type specifier.
}

//2.6 Defining our own data structures.
void define_data_structures(){

    struct Sales_data {
        std::string boolNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    } *Salesptr;
    std::cout << Salesptr->units_sold << std::endl;
}

int main(void){
    define_data_structures();
    return 0;
}
