#include<iostream>
#include<math.h>
using namespace std ;

int main () {
    int64_t a,b,min,max,c ,dmin,dmax, diam , elementi ;
    
    cout << endl << "scrivi qua il primo numero: ";
    cin >> a ; 

    cout << endl << "scrivi qua il secondo numero: ";
    cin >> b ;

    if (a>b) {
        max = a ;
        min = b ;
    }
    else { 
        max = b ;
        min = a ;
    }
    
    diam = fabs (max-min) ;
    if (min>0) {
        cout << "il tuo intervallo  ( "<< min << " , " << max << " )"<< endl << "oppure { " ;
        
        for (int i=0 ; i < diam + 1 ; i++){
            elementi = min + i ;

            cout << elementi<< " , " ;
        }
        cout << " }" << endl ;
    }
     
     if (max<0) {
        cout << endl << "il tuo intervallo ( "<< min << " , " << max << " )" << endl << "oppure { ";
        for (int i=0 ; i < diam +  1 ; i++){
            elementi = min + i ;
            
            cout << elementi<< " , " ;
        }
        cout << " }" << endl ;
    }
    
    cout << endl <<" dammi un valore: "<< endl ;
    cin >> c ;
    dmin = fabs (c-min);
    dmax = fabs (c-max);
    
    if (c <= max and c >= min) {
    cout <<endl<< "la tua distanza dal min: "<< dmin<< endl ;
    cout <<endl<< "la tua distanza dal max: "<< dmax<< endl ;
    }
    else {
        cout << "il valore inserito non appartiene all'intervallo." << endl ;
    }
    
    return 0;
}