#include <iostream>

#include <cmath>
#include"funzioni.h"

using namespace std ;

int main  () {
   int scores [10] ;
   int i = 0 ; 
   int data ;
    float media, dev ;

   while (i < 10 ) {
        cout << endl << "inserisci il valore " << i+ 1 << endl;
        cin >> data ;
        
    if ( data == 0 ) { 
        break;
    }
    scores [i] = data ;
    i++ ;
   }
media = media_array (scores, i ) ;
dev = devstd (scores, i , media ) ;

    cout << "la tua media e': " << media << endl;
    cout << "la tua deviazione standard e': " << dev << endl;
return 0 ;
}

