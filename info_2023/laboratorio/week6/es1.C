/*Scrivere una funzione __void scambia (int *p1, int *p2)__ che scambi 
il contenuto delle variabili "passate"  alla funzione. Scrivere anche una versione 
per __float__ (__void scambia(float *p1, float *p2)__) e modificale la funzione di ordinamento __selsort()__ usata nella soluzione 
dell'Esercizio 1, settimana 6, in modo tale che usi questa funzione di scambio
 invece di __void scambia(float v[], int pos1, int pos2)__.*/

#include<iomanip>
#include <iostream> 
#include <fstream>
#include <cstring>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
using namespace std;
void scambia_int (int* , int* );
void scambia_float (int* , int*);

int main () {
    int i = 0, k = 1  ; 
    float t = 5.3 , z = 6.4 ; 
    scambia_int (&i, &k); 
    
    cout<< i << k ; 
    cout<< t << z; 
    return 0;
}



void scambia_int (int* a, int* b) {
    int appo ; 
    appo = *a ;
    *a = *b ; 
    *b = appo; 
}

void scambia_float (float* a, float* b) {
    float appo ; 
    appo = *a ; 
    *a = *b ; 
    *b = appo ;
}



