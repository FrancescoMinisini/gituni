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




int main () {
    string directory = "sfere.dat"; 
    int n_dati=0 ;
    int rn_dati = n_dati;  

    return 0; 
}

sfere* define_array_file_sfere ( int& n_dati , string directory) {

    sfere* sfera;
    n_dati =  conta_coppiedati_file (directory); 
    sfera = new sfere [n_dati];

    ifstream data ;
    
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> sfera[k].diam ;
    data >> sfera[k].colore ;   
    }

    data.close () ;
    return sfera;
}