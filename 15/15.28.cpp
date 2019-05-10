#include<iostream>
#include<memory>
#include<vector>
#include "Quote.h"
using namespace std;
 
int main()
{
    vector<shared_ptr<Quote>> basket;
    double sum = 0.0;
    for( size_t i = 0; i != 10; ++i )
        basket.push_back( make_shared<Bulk_quote>( "C++Primer", 6, 5, 0.5 ) );
    for( const auto& bq: basket )
        sum += bq->net_price( 10 );
    cout << sum << endl;
    return 0;
}
