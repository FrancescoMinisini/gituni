#include<iostream>
using namespace std ;


int main  () {
   int scores [10] ;
   int i = 0 ; 
   int data ;
   while (i < 10 ) {
        cout << endl << "inserisci il valore " << i+ 1 << endl;
        cin >> data ;
    if ( data == 0 ) { 
        break;
    }

    scores [i] = data ;
    i++ ;
   }
    cout << endl << "[ " ;
    for (int k = 0 ; k<i ; k++) { 
        cout << " " << scores [k] << " ";
    }
    cout << " ]" << endl << endl ;
    return 0;
}