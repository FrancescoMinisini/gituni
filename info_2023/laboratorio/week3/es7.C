#include<iostream>
#include<cmath>
using namespace std ; 
void scambia (int , int ) ; 
void print_array (int, int) ;

void print_array (int valori[], int num_elementi) {
    cout << "{ " ;
    for (int i = 0; i < num_elementi-1; i++) {
         cout << valori [i] << " , " ;
    }
    cout << valori [num_elementi-1] << " }" << endl ;
}


void scambia (int valori[], int n, int pos1 , int pos2) {
   int appo ; 
   do { 
        cout << endl << "posizione 1 da scambiare: ";
    cin >> pos1 ;
    cout << endl << "posizione 2 da scambiare: ";
    cin >> pos2 ; 
   
    if (pos1>0 or pos2>0 or pos1<n or pos2<n) {
        cout << endl << "indici fuori range" << endl ;
    }
    
    }  while(pos1<0 or pos2<0 or pos1>n or pos2>n) ;
    
    pos1 = pos1 -1 ;
    pos2 = pos2 -1 ;
    appo = valori [pos1] ; 
    valori [pos1] = valori [pos2];
    valori [pos2] = appo ;
}


int main () {
    int n,v1,v2 ; 
    float m,dev ;
    cout << "dichiara qual'è il numero di voti: " << endl ; 
    cin >> n ;
    int voti [n] ;
    for (int i = 0; i < n ; i++) {
        cout << endl << "inserisci qua il valore "<< i + 1 << ": "<< endl ;
        cin >> voti [i] ; 
        cout << endl;
    }    
    
    
    scambia (voti, n, v1, v2) ;
    
    print_array (voti, n) ;
    
    
    return 0 ; 
}