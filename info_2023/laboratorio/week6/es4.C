#include <iostream> 
#include <fstream>
#include <cstring>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
using namespace std;


int main () {
int*pointer;
string directory = "/home/francesco/programmazione/LabInfo_2023_24/Lab06/sfere.dat";
int n_dati = conta_dati_file (directory);
float* pointer; 
carica_dati_file (directory, &n_dati);

    return 0; 
}



float* carica_dati_file (string directory , int* n_dati) {
    float*dati;
    dati = new float [*n_dati];
   
    ifstream data; 
    data.open(directory) ;
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close() ; 
    } 

    for (int k = 0 ; k<*n_dati ; k++){
    data >> dati[k];
    }

    data.close () ;

    return dati;
}

