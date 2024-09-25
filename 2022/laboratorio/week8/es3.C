#include<iomanip>
#include <iostream> 
#include <fstream>
#include <cstring>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
using namespace std;



struct sfere
{
    float diam; 
    char colore;
};

void define_array_file_sfere (sfere dati[] , int n_dati , string directory);
void print_array_sfere(sfere valori[], int num_elementi);

int main ( ) {
    string directory= "sfere.dat"; 
    int n_dati; 
    sfere* sfera;
    n_dati =  conta_coppiedati_file (directory); 
    sfera = new sfere [n_dati];
    define_array_file_sfere (sfera , n_dati , directory);
    print_array_sfere ( sfera , n_dati); 
    
    delete [] sfera ;
    return 0; 
}

void define_array_file_sfere (sfere dati[] , int n_dati , string directory) {

    ifstream data ;
    
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> dati[k].diam ;
    data >> dati[k].colore ;   
    }

    data.close () ;
}

void print_array_sfere(sfere valori[], int num_elementi) {

    
    for (int i = 0; i < num_elementi; i++) {
         cout << "{ "<< valori [i].diam << " , " << valori[i].colore << " }" << endl ;
    }
    
}
