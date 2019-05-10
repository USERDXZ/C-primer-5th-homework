#include<iostream>
#include<string>
#include"Vec.h"
 
using namespace std;
 
int main()
{
    Vec<string> svec;
    Vec<int> ivec( { 0, 1, 2, 3 } );
    Vec<int> ivec2( 0, 10 );
 
    Vec<int> useless = Vec<int>( { 6, 6, 6 } );
    Vec<int> ivec3( ivec2 );
    Vec<int> ivec4( std::move( useless ) );
 
    string tmp = "you";
    svec.push_back( "shit" );
    svec.push_back( tmp );
 
    ivec.pop_back();
 
    for( size_t i = 0; i != ivec2.size(); ++i )
        cout << ivec2[i] << " ";
    cout << endl;
 
    for( const auto &s : svec )
        cout << s << " ";
    cout << endl;
 
    for( const auto i : ivec )
        cout << i << " ";
    cout << endl;
    for( const auto i : ivec3 )
        cout << i << " ";
    cout << endl;
    for( const auto i : ivec4 )
        cout << i << " ";
    cout << endl;
 
    return 0;
}