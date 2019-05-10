#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <iostream>
using namespace std;

class Quote{
public:
    Quote() = default;
    Quote(const string& book, double sales_price):bookNo(book), price(sales_price){cout << "Quote's constructor" << endl;}
    Quote(const Quote& qt):bookNo(qt.bookNo), price(qt.price){cout << "Quote's copy constructor" << endl;}
    Quote& operator=(const Quote& qt){
        cout << "Quote's copy operator=" << endl;
        bookNo = qt.bookNo;
        price = qt.price;
        return *this;
    }

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() const;
    virtual Quote* clone() const & {return new Quote(*this);}
    virtual Quote* clone() && {return new Quote(move(*this));}
    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote( const string& book, double price, size_t qty, double disc):
                Quote(book, price), quantity(price), discount(disc) {cout << "Disc_quote's constructor" << endl;}
    Disc_quote(const Disc_quote& dq):Quote(dq), quantity(dq.quantity), discount(dq.discount){cout << "Disc_quote's copy constructor" << endl;}
    Disc_quote& operator=(const Disc_quote& dq){
        cout << "Disc_quote's copy operator=" << endl;
        Quote::operator=(dq);
        quantity = dq.quantity;
        discount = dq.discount;
        return *this;
    }
    double net_price(size_t) const = 0;
protected:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote( const string& book, double p, size_t qty, double disc) : 
                Disc_quote(book, p, qty, disc) {cout << "Bulk_quote's constructor" << endl;}
    Bulk_quote(const Bulk_quote& bq):Disc_quote(bq){cout << "Bulk_quote's copy constructor" << endl;}
    Bulk_quote& operator=(const Bulk_quote& bq){
        cout << "Bulk_quote's copy operator=" << endl;
        Disc_quote::operator=(bq);
        return *this;
    }
    double net_price(size_t) const override;
    void debug() const override;
    Bulk_quote* clone() const & {return new Bulk_quote(*this);}
    Bulk_quote* clone() && {return new Bulk_quote(move(*this));}
};

double Bulk_quote::net_price(size_t n) const
{
    if(n >= quantity)
        return n * (1 - discount) * price;
    else
        return n * price;
}

void Quote::debug() const
{
    cout << "bookNo: " << bookNo << " price= " << price << endl;
}

void Bulk_quote::debug() const
{
    Quote::debug();
    cout << " quantity= " << quantity <<" discount= " << discount << endl;
}
#endif