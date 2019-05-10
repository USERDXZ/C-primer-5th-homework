#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>
using namespace std;

struct Sales_data
{
    friend Sales_data add(const Sales_data&,const Sales_data&);
    friend ostream &print(std::ostream&,const Sales_data&);
    friend istream &read(std::istream&,Sales_data&);
public:
    Sales_data(string s,unsigned n,double p):
              bookNo(s),units_sold(n),revenue(p*n){cout<<"s,n,p"<<endl;}
    Sales_data(string s=" "):Sales_data(s,0,0){cout<<"s"<<endl;}
    Sales_data(istream &is):Sales_data(){read(is,*this);}

    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
private:
    double avg_price() const{return units_sold?revenue/units_sold:0;}
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold+=rhs.units_sold;
    revenue+=rhs.revenue;
    return *this;
}

ostream &print(ostream &os,const Sales_data &item)
{
    os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
    return os;
}

istream &read(istream &is,Sales_data &item)
{
    double price;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue = price*item.units_sold;
    return is;
}

Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
#endif