#include<iostream>
using namespace std ;
int main() {
    double media ;
    int a ;
    int i,somma =0 ;

    cout<<endl << "valore: " ;
    cin >> a ;
    somma = a ;


while ( a != 0) {
    cout<<endl << "valore: " ;
    cin >> a ;
    somma = somma + a ;
    i++ ;
    cout << endl ;
}
    media = (double) somma / i ;
    cout << endl << "la tua somma e': "<< somma << endl ;
    cout << endl << "la tua media e': "<< media << endl << endl;

    return 0;
}