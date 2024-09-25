#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
#include"librerie/funzioni/funzioni.h"

int main(){
    int n_dati = 0, error_code = 0 ; 
    string directory = "";
    string directory = "";
    struct* dati ; 
    
        if( !(error_code == 0)) {
        cout << endl << "we ce sta un problema" << endl;
    }
    return 0;
}
/*
void stampa ( struct* dati , int d ){

    for (int i = 0; i < d; i++)
    {
                 cout  << "{ " << dati[i].time << " , " <<dati[i].db << " , " <<dati[i].dato <<  " } "<< endl;
    }}
    
}*/

/*
misura* inizializza_misura (int& n_dati , string directory, int& error_code) {
    misura* vettore; 
    ifstream data ;
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
    }
    
    int t; 
    int mis; 
    float temp; 
    char stato;

    n_dati = 1 ; 
    data >> t >> mis >> temp ;
    
    while (!data.eof()) {
        n_dati++ ;
        data >> t >> mis >> temp ;
    }
     data.close () ;

    vettore = new misura [n_dati];
    
    if (vettore == NULL) {
        error_code= -2;
        return vettore;
    }
    
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
        error_code = -1; 
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> vettore[k].t;
    data >> vettore[k].mis;
    data >> vettore[k].temp;
    //data >> vettore[k].stato;
    }

    data.close () ;

    error_code = 0; 
    return vettore; 
}
*/