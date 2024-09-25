#include<iomanip>
#include <iostream> 
#include <fstream>
#include <cstring>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
using namespace std;
void calcolaStats (float dati [], int n_dati , float* pmin, float*pmax, float* pmediana, float* pmedia, float*pstddev);

    int main () {
    string directory = "/home/francesco/programmazione/LabInfo_2023_24/Lab07/data.dat"; 
    int n_dati = conta_dati_file ( directory ) ;
    float* dati;
    dati = new float[n_dati];
    float min,max, mediana, media, stnd; 
    define_array_file (dati , n_dati, directory); 
    ordcrescente_float ( dati , n_dati);
    calcolaStats ( dati , n_dati , &min, &max, &mediana, &media, &stnd);
    
    fstream results;
    results.open ("risultati.dat") ; 
    for (int i = 0; i < 3; i++) {
        results <<" " << dati[i] ;
    } for (int i = 0; i < 3; i++) {
        results <<" " << dati [n_dati - 3 + i] ; 
    }
    results << endl <<"min: " <<  min <<endl <<" max: " << max <<endl <<" mediana: " << mediana<< endl <<  "media: "<< media << endl <<"stnd: " << stnd ; 
    delete []dati ; 
    return 0; 
}

