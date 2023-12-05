#include<iomanip>
#include <iostream> 
#include <fstream>
#include <cstring>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
using namespace std;

struct my_array_int 
{
    int* raw; 
    int n_dati;
    int used; 

};

my_array_int carica_interi_file (int& n_dati , string directory, int&);

int main () {
    string directory  = "interi.dat";
    int error_code = 0; 
    int& rerror_code = error_code ;
    my_array_int array;
    array =  carica_interi_file (array.n_dati  , directory, rerror_code);
    print_array_int (array.raw, array.n_dati);
    delete [] array.raw; 


    return 0;
}



my_array_int carica_interi_file (int& n_dati , string directory, int& error_code) {
    my_array_int vettore; 
     
    
    vettore.n_dati = conta_dati_file (directory);
    n_dati =vettore.n_dati;
    vettore.raw = new int [vettore.n_dati];
    if (vettore.raw == NULL) {
        error_code= -2;
        return vettore;
    }
    ifstream data ;
    
    //data.seekg(0,ios::beg); lo riporta all'inizio.
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
        error_code = -1; 
    } 

    for (int k = 0 ; k< vettore.n_dati ; k++){
    data >> vettore.raw[k];
    }

    data.close () ;
    vettore.used=vettore.n_dati;
    error_code = 0; 
    return vettore; 
}
