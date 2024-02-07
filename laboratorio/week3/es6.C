#include<iostream>
#include<cmath>
using namespace std ; 
float stnd (int, int, float) ; 
float media (int, int) ; 
bool isOutlier (int,int ,float, float) ;
void scambia (int , int , int , int ) ;



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


int main () {
    int n ; 
    float m,dev ;
    cout << "dichiara qual'è il numero di voti: " << endl ; 
    cin >> n ;
    int voti [n];
    for (int i = 0; i < n ; i++) {
        cout << endl << "inserisci qua il valore "<< i + 1 << ": "<< endl ;
        cin >> voti [i] ; 
        cout << endl;
    }    
    m =  media (voti , n ) ;
    dev = stnd ( voti , n , m ) ;
    cout << endl << "la tua media è: "<< m << endl;
    cout << endl << "la tua deviazione standard è: "<< dev << endl;
    return 0 ; 
}