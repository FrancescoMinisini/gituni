#include<cstdlib>
#include<iostream>
using namespace std ; 
#include<cmath>
#include<strings.h>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"

struct puntoR2{ double x; double y; };

struct myArrayPuntoR2{ int size; int used; puntoR2 *raw; };

puntoR2* carica_coppie_array_file_int (int& , string);

int main (){
string directory = "rilevazioni.dat";
int error_code = 0;
int& rn = error_code ; 
carica_coppie_array_file_int ( rn, directory); 

    return 0;
}





puntoR2* carica_coppie_array_file_int (int& error_code , string directory) {
    puntoR2* dati;
    int n_dati = 0; 
    n_dati = conta_dati_file (directory); 
    dati = new puntoR2 [n_dati];
    myArrayPuntoR2 positions;
    positions.size = n_dati;
    positions.raw= dati; 
    positions.size = n_dati; 
    ifstream data ;
    

    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
        return NULL;
        error_code= -1; 
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> dati[k].x ;
    data >> dati[k].y ;    
    }

    data.close () ;
    return positions.raw; 
}
