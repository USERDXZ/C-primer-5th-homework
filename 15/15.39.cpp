#include "Query.h"
#include "TextQuery.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    ifstream file;
    file.open("storyDataFile.txt");
    if(!file){
        cerr << "cant open file!";
        return -1;
    }
    TextQuery text(file);
    auto q = Query( "fiery" ) & Query( "bird" ) | Query( "wind" );
    auto result = q.eval(text);
    print(cout, result);
    return 0;
}
