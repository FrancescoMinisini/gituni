#include<iostream>
using namespace std ;


int main  () {
   int scores [10] ;
   int i , k = 0 ;
   while (i < 10 ) {
    cout << endl << "inserisci il valore " << i+ 1 << endl;
    cin >> scores [i];
    i++ ;
   }
   cout << endl << "[ " ;
    for (k; k<10 ; k++) { 
        cout << " " << scores [k] << " ";
    }
    cout << " ]" << endl ;
    return 0;
}