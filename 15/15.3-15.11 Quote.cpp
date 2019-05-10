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

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote( const string& book, double p, size_t qty, double disc) : 
                Quote(book, p), min_qty(qty), discount(disc) {}
    double net_price(size_t) const override;
    void debug() const override;
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

class Limited_quote : public Quote {
public:
    Limited_quote() = default;
    Limited_quote( const string& book, double p, size_t qty, double disc) :
                   Quote(book, p), max_qty(qty), discount(disc) {}
    double net_price(size_t) const override;
private:
    size_t max_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(size_t n) const
{
    if(n >= min_qty)
        return n * (1 - discount) * price;
    else
        return n * price;
}

double Limited_quote::net_price(size_t n) const 
{
    if(n <= max_qty)
        return n * (1 - discount) * price;
    else
        return max_qty * (1 - discount) * price + (n - max_qty) * price;
    
}

void Quote::debug() const
{
    cout << "bookNo: " << bookNo << " price= " << price << endl;
}

void Bulk_quote::debug() const
{
    Quote::debug();
    cout << " min_qty= " << min_qty <<" discount= " << discount << endl;
}

double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main()
{
    Quote b1( "978-7-121-15535-2", 128.0 );
    Bulk_quote b2( "978-7-121-25229-7", 89.0, 10, 0.2 );
 
    print_total( cout, b1, 2 );
    print_total( cout, b2, 5 );
    print_total( cout, b2, 10 );
    return 0;
}