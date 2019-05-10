#include<iostream>
#include"Basket.h"
 
using namespace std;
 
int main()
{
    Basket bsk;
    Quote b1( "978-7-121-15535-2", 128.0 );
    Bulk_quote b2( "978-7-121-25229-7", 89.0, 2, 0.2 );
    Bulk_quote b3( "978-7-121-25229-7", 89.0, 2, 0.2 );
 
    bsk.add_item( b1 );
    bsk.add_item( b2 );
    bsk.add_item( b3 );
 
    bsk.total_receipt( cout );
 
    return 0;
}