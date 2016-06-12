#include "sales_data.h"
//exercise 7.1
//read data from input formated as "bookNo units_sold price"
std::istream &read(std::istream &is, sales_data &data){
    double price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = price * data.units_sold;
    return is;
}
//combine rhs to lhs.
void combine(sales_data &lhs, const sales_data &rhs){
    lhs.units_sold += rhs.units_sold;
    lhs.revenue += rhs.revenue;
}

//print current item.
std::ostream &print(std::ostream &os, const sales_data &data){
    std::cout << " ISBN: " << data.bookNo
              << " units_sold: " << data.units_sold
              << " revenue: " << data.revenue << std::endl;
    return os;
}

//define a viarible total to hold the next transaction.
//then input transacion informations,if the isbn is the same
//as total's, update total. otherwise print total information
//and replacr current book as total.
void trans_pro(){
    sales_data total;
    if(read(std::cin, total)){
        sales_data tran;
        while(read(std::cin, tran)){
            if(total.bookNo == tran.bookNo){
                combine(total, tran);
            }
            else{
                print(std::cout, total);
                total = tran;
            }
        }
    }
    else{
        std::cout << "No data?" << std::endl;
    }
}  // exercise 7.1
