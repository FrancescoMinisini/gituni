#include<iomanip>
#include <iostream> 
#include <fstream>
#include <cstring>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
using namespace std;


int* carica_array_file_int (int& n_dati , string directory) {
    int* dati;
    
    
    n_dati = conta_dati_file (directory); 
   dati = new int [n_dati]; 
    ifstream data ;
    

    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
        return NULL;
        n_dati = -1; 
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> dati [k];
    }

    data.close () ;


    return dati; 
}


int main () {
    int n_dati; 
    int& rn_dati = n_dati; 
    int* dati;  
    string directory = "interi.dat"; 
    dati = carica_array_file_int (rn_dati, directory); 
    print_array_int( dati , rn_dati) ;
    delete [] dati; 

    return 0 ; 
}