#include <iostream>
#include "MovieRentalSystem.h"
using namespace std;
int main( ) {
MovieRentalSystem MRS( "movies.txt", "subs.txt" );
cout << endl;
MRS.showAllSubscribers();
cout << endl;
return 0;
}