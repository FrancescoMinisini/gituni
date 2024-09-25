
//name -> raw === (*name.raw)
#include<iostream>
using namespace std;
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
#include "/home/francesco/programmazione/gituni/librerie/random/random.h"
int ricerca (my_array_int, int);
void generate_array ( my_array_int dati, int n_dati);
void print_array_int (my_array_int valori, int num_elementi);

int main () {
    imposta_seed();
    int chiave, position; 
    my_array_int dati; 
    dati.used = 10;
    dati.size = 10;
    dati.raw = new int [dati.size];
    generate_array ( dati , dati.size);
    print_array_int( dati , dati.size);
    cout << "intero da individuare :";
    cin >> chiave ;
    cout << endl; 
    position = ricerca(dati , chiave); 
    cout << "posizione : " << position << endl; 
    delete [] dati.raw;
    return 0; 
}


int ricerca (my_array_int v , int chiave) {
    int pos = -1; 
    for (int i = 0 ; i < v.used  ; i++)
    {
        if ( v.raw[i] == chiave){
            pos = i;
            break;
        }
    }
    return pos;
}

void print_array_int (my_array_int valori, int num_elementi) {

    cout << "{ " ;
    for (int i = 0; i < num_elementi-1; i++) {
         cout << valori.raw[i] << " , " ;
    }
    cout << valori.raw [num_elementi-1] << " }" << endl ;
}

void generate_array ( my_array_int dati, int n_dati) {
    int appo ; 
    for (int i= 0 ; i < n_dati ; i++){
        appo = (int)rand_uniforme(0,10);
        dati.raw[i]= appo;
    }

}




