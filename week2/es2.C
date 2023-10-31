#include<iostream>
using namespace std ;

int main () {
    float a,b,min,max ;
    
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
    
    if (min>0) {
        cout << "il tuo intervallo positivo: ( "<< min << " , " << max << " )"<< endl;
    }
     
     if (max<0) {
        cout << endl << "il tuo intervallo negativo: ( "<< min << " , " << max << " )" << endl;
    }
    if (!(max<0 or min>0)) {
        cout << "l'intervallo iclude 0" << endl ;
    }

    return 0;
}