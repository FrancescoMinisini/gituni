#include<iostream>
using namespace std ; 
#include<cmath>


float media (int valori[], int N) {
    int somma = 0 ;
    float res ;
    for (int i = 0; i < N; i++)
    {
     somma = somma + valori [i] ;
    }
    res = (float)somma / N ;

    return res ; 
} 

float stnd (int valori[], int N, float m) {
    float sum_scarto = 0 ; 
    float res ;
    for (int i = 0; i < N; i++)
    {
     sum_scarto = pow(valori [i] - m,2) + sum_scarto ;
    }
    res = sqrt(sum_scarto / (-1)) ;
    return res ;
}

bool isOutlier (int valore, float m,float stnd) {

    float abs, c ; 
    abs = fabs(valore - m) ; 
    c = 3*stnd ;

    return abs > c ;

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

void print_array (int valori[], int num_elementi) {

    cout << "{ " ;
    for (int i = 0; i < num_elementi-1; i++) {
         cout << valori [i] << " , " ;
    }
    cout << valori [num_elementi-1] << " }" << endl ;
}

void define_array (int voti[],int n) {
    for (int i = 0; i < n ; i++) {
        cout << endl << "inserisci qua il valore "<< i + 1 << ": "<< endl ;
        cin >> voti [i] ; 
        cout << endl;
    }    
}

int resto (int Num, int Den) {
    int q, r ;
    q =  Num/Den ; 
    r = Num - q*Den ;
    return r ; 

}

int MCD ( int p , int q) {
    int mcd, r ;
    do {
        r = resto (p,q) ;
        p = q ; 
        q = r ; 
    } while (q != 0) ; 
    return p ; 
} 
