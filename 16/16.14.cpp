#include <iostream>
#include "Screen.h"
using namespace std;
 
int main()
{
    Screen<5, 5> myScreen( 'X' );
    myScreen.move( 4, 0 ).set( '#' );
    cout << myScreen.get( 4, 0 ) << "\n";
    myScreen.display( cout );
    cout << "\n";
    cout << myScreen << endl;
    return 0;
}