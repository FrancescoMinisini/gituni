#include<iomanip>
#include <iostream> 
#include <fstream>
#include <cstring>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
using namespace std;
int elimina (int valori [], int used, int pos);

int main () {
    bool* sqrt; 
    bool* primo; 
    string direcory = "interi.dat"; 
    int n_dati, k=1;    
    n_dati = conta_dati_file (direcory);
    int used = n_dati; 
    int* dati;
    dati = new int [n_dati];
    define_array_file_int(dati, n_dati, direcory);
    sqrt = new bool [n_dati];
    primo = new bool [n_dati];
    for (int i = 0; i < n_dati; i++)
    {
        sqrt[i] = true ;
        primo[i] = true ; 
    }
    
    for (int i = 0; i < n_dati; i++)
    {
        if (!is_perfect_square(dati[i])) {
                sqrt[i] = false ; 
        }
        if (!is_prime(dati[i])) {
                primo [i] = false ; 
        }
    }

    for (int i = 0; i < n_dati - k ; i++) {
        if ((sqrt [i] == false) and (primo [i] == false)) {
            while ((sqrt [n_dati - k] == false) and (primo[n_dati-k]== false))
            {
            used--;
            k++;
            
            }
            
            used = elimina(dati ,n_dati - k +1 , i); 
            k++;
            
        }
    }

    print_array_int (dati, used);
    return 0 ; 
}

int elimina (int valori [], int used, int pos){
    
    scambia (valori, pos, used -1 );

    used--; 

    return used; 
}