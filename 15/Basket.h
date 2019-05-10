#ifndef BASKET_H
#define BASKET_H
#include <iostream>
#include <memory>
#include <set>
#include "Quote.h"
using namespace std;

class Basket{
public:
    void add_item(const Quote& sale) { items.insert(shared_ptr<Quote>(sale.clone()));}
    void add_item(Quote&& sale) {items.insert(shared_ptr<Quote>(move(sale).clone()));}
    double total_receipt(ostream& ) const;
private:
    static bool compare(const shared_ptr<Quote>& lhs,
                        const shared_ptr<Quote>& rhs) { return lhs->isbn() < rhs->isbn(); }
    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

double Basket::total_receipt(ostream& os) const{
    double sum = 0.0;
    for(auto iter = items.cbegin();iter != items.cend();iter = items.upper_bound(*iter)){
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << endl;
    return sum;
}
#endif