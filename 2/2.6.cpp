#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    double price = 0.0;
    Sales_data data1,data2;
    std::cin>>data1.bookNo>>data1.units_sold>>price;
    data1.revenue = data1.units_sold * price;
    std::cin>>data2.bookNo>>data2.units_sold>>price;
    data1.revenue = data2.units_sold * price;
    if(data1.bookNo == data2.bookNo){
        unsigned totalCnt = data1.units_sold+data2.units_sold;
        double totalRevenue = data1.revenue+data2.revenue;
        std::cout<<data1.bookNo<<" "<<totalCnt
                 <<" "<<totalRevenue<<std::endl;
        if(totalCnt!=0)
            std::cout<<totalRevenue/totalCnt<<std::endl;
        else
            std::cout<<" 0 sales "<<std::endl;
        return 0;
    }
    else{
        std::cerr<<" data must  refer to the same ISBN"<<std::endl;
        return -1;
    }
}