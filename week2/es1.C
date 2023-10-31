#include<iostream> 
using namespace std ;

int main () {
float a,b ;
b = 0;
cout << "Scrivi il valore: ";
cin >> a;

if ( a < b )  {
    a= -1 * a;
} 
cout << endl << "il valore assoluto e': "<< a <<endl ;
    return 0 ;
}

/*oppure 
#include<math.h>

cout << fabs (a)*/