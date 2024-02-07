#include<fstream>
#include<iostream>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
#include "/home/francesco/programmazione/gituni/librerie/random/random.h"
using namespace std;
//int ricerca_binaria (my_array_int dati, int inizio , int fine , int chiave) ;

int main (){
my_array_int dati; 
dati.size = 10; 
dati.raw = new int [dati.size];
dati.used = 0; 
define_array (dati.raw , 10 );
cout << endl << ricerca (dati, 7) << endl;
cout << endl << ricerca_binaria( dati, 0 , dati.size , 7) << endl;
    return 0; 
}

/*int ricerca_binaria (my_array_int dati, int inizio , int fine , int chiave) {
int m = (inizio + fine)/2 ;
if (dati.raw[m] == chiave) {
    return m; 
}
else if ( dati.raw[m] > fine ){
    cout << endl <<"qualcosa è andato storto nella ricerca" << endl; 
    return -1;
}
else {
    if ( dati.raw[m] > chiave) {
        return ricerca_binaria (dati , inizio , m-1 , chiave );
    }
    else {
        return ricerca_binaria ( dati , m+1 , fine, chiave);
    }
    } 
}


*/