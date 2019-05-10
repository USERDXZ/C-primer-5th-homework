#include <string>
#include <iostream>
using namespace std;

class Quote{
public:
    Quote() = default;
    Quote(const string& book, double sales_price):bookNo(book), price(sales_price){}
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() const;
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
                Quote(book, price), quantity(price), discount(disc) {}
    double net_price(size_t) const = 0;
protected:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote( const string& book, double p, size_t qty, double disc) : 
                Disc_quote(book, p, qty, disc) {}
    double net_price(size_t) const override;
    void debug() const override;
};

class Limited_quote : public Disc_quote {
public:
    Limited_quote() = default;
    Limited_quote( const string& book, double p, size_t qty, double disc) :
                   Disc_quote(book, p, qty, disc) {}
    double net_price(size_t) const override;
};

double Bulk_quote::net_price(size_t n) const
{
    if(n >= quantity)
        return n * (1 - discount) * price;
    else
        return n * price;
}

double Limited_quote::net_price(size_t n) const 
{
    if(n <= quantity)
        return n * (1 - discount) * price;
    else
        return quantity * (1 - discount) * price + (n - quantity) * price;
    
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