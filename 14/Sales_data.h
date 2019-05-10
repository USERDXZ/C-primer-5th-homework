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
    friend ostream& operator<<(ostream&, const Sales_data&);
    friend istream& operator>>(istream&, Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
public:
    Sales_data(string s,unsigned n,double p):
              bookNo(s),units_sold(n),revenue(p*n){cout<<"s,n,p"<<endl;}
    Sales_data(string s=" "):Sales_data(s,0,0){cout<<"s"<<endl;}
    Sales_data(istream &is):Sales_data(){read(is,*this);}
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator=(const string&);
    explicit operator string() const { return bookNo; }
    explicit operator double() const { return avg_price(); }

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

ostream& operator<<(ostream& os, const Sales_data& rhs){
    os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
    return os;
}

istream& operator>>(istream& is, Sales_data& rhs){
    double price;
    is>>rhs.bookNo>>rhs.units_sold>>price;
    if (is)
        rhs.revenue = price * rhs.units_sold;
    ekse
        rhs = Sales_data();
    return is;
}

Sales_data operator+(const Sales_data& rhs, const Sales_data& lhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data& item){
    this->combine(item);
    return *this;
}

Sales_data& Sales_data::operator=(const string& s){
    bookNo = s;
    return *this;
}
#endif