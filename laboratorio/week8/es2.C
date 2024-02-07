#include<iomanip>
#include <iostream> 
#include <fstream>
#include <cstring>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
using namespace std;
    int*seleziona_primi (int dati[], int n_dati, int& nprimi);
    int conta_primi(int dati [], int n_dati ); 

int main () {
    string directory = "interi.dat"; 
    int n_dati, n_primi = 0; 
    int& rn_primi = n_primi ; 
    int& rn_dati = n_dati; 
    int*dati;
    int*primi; 
    dati = carica_array_file_int  ( rn_dati, directory); 
    primi = seleziona_primi ( dati, n_dati, rn_primi );
    print_array_int (primi, n_primi); 
    return 0; 
}

    int conta_primi(int dati [], int n_dati ) {
        int n_primi = 0; 

    for (int i = 0; i < n_dati; i++)
        {
            if ( is_prime (dati [i])) {
                n_primi++ ;
            }
        }

        return n_primi; 
    }



    int*seleziona_primi (int dati[], int n_dati, int& n_primi) {
        int* primi;
        n_primi = conta_primi ( dati , n_dati );
        primi = new int [n_primi]; 
        int k= 0 ; 
        for (int i = 0; i < n_dati; i++)
        {
            if ( is_prime (dati [i])) {
                primi [k] = dati[i];  
                k++; 
            }
        }
        return primi; 
    }
