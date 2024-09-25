#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
#include"librerie/funzioni/funzioni.h"

struct misura {
int t; // istante della misura in secondi
int mis; // 0 o 1 rilevato dagli strumenti
float temp; // temperatura del qubit in Kelvin
char stato; // nome della configurazione
};

struct my_array_misura {
    int size;
    int used;
    misura*raw;
};


misura* inizializza_misura (int& n_dati , string directory, int& error_code);
void print_array_misura (misura* dati , int n , int n_colpo) ;

void initialize(my_array_misura* dati , misura* vettore , int n_dati) ;
void remove (my_array_misura* dati , int pos);
void clean (my_array_misura* dati);
void print_array_tot (my_array_misura dati);

void merge_misura(misura data[], int i, int m, int f);
void merge_sort_misura(misura data[], int init, int final);

int conta_0 (my_array_misura dati);

int main(){

string directory = "dati.dat";
int n_dati , error_code = 0; 
misura* vettore ; 

//1
vettore = inizializza_misura ( n_dati , directory, error_code);
cout << endl << "il numero di misure lette: " << n_dati << endl;  
//print_array_misura ( vettore , 3 , n_dati) ;
//2
my_array_misura dati;
initialize(&dati , vettore , n_dati);
clean ( &dati);
print_array_tot(dati);
//3

merge_sort_misura( dati.raw , 0, dati.used);
//print_array_tot(dati);
print_array_misura ( dati.raw , 3 , dati.used) ;
//4



    return 0;
}

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

void print_array_misura (misura* dati , int n , int n_colpo) {


    for (int i = 0; i < n; i++) {
         cout  << "{ " << dati[i].t << " , " <<dati[i].mis << " , " <<dati[i].temp <<  " } "<< endl;
    }
     for (int i = n_colpo-1 ; i > n_colpo - n -1 ; i--) {
         cout << "{ " << dati[i].t << " , " <<dati[i].mis << " , " <<dati[i].temp <<   " } "<< endl;
    }

}

void clean (my_array_misura* dati) {
    for (int i = 0; i < dati->size; i++)
    {
        if (dati->raw[i].temp > 30) {
            remove(dati , i);
            i--;
        }
    }
} 

void remove (my_array_misura* dati , int pos) {
    for (int i = pos; i < dati->size -1; i++)
    {
        dati->raw[i] = dati->raw[i+1];
    }
    (dati->used)--;
}



void initialize(my_array_misura* dati , misura* vettore , int n_dati) {
    dati->size = n_dati; 
    dati->used= n_dati; 
    dati->raw =  vettore ; 
}


void print_array_tot (my_array_misura dati) {

    for (int i = 0; i < dati.used; i++) {
         cout  << "{ " << dati.raw[i].t << " , " <<dati.raw[i].mis << " , " <<dati.raw[i].temp <<  " } "<< endl;
    }
}


void merge_misura(misura data[], int i, int m, int f){
    int j, k, z;
    int* tmp = NULL; 
    tmp = new int[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j].t <= data[k].t) {
            tmp[z] = data[j].t;
            j++;
        } else {
            tmp[z] = data[k].t;
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++){
            tmp[z] = data[k].t;
            z++;
        }
    } else {
        for (j; j <= m; j++){
            tmp[z] = data[j].t;
            z++;
        }
    }

    //ricopia tmp in data
    z = 0;
    for (z; z < f-i+1; z++){
        data[i+z].t = tmp[z];
    }

    delete []tmp;
    tmp = NULL;
}


void merge_sort_misura(misura data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_misura(data, init, m);
        merge_sort_misura(data, m+1, final);
        merge_misura(data, init, m, final);
    }
}

int conta_0 (my_array_misura dati) {
    int conta = 0;
    for (int i = 0; i < dati.used; i++)
    {
     if ( dati.raw[i].mis == 0 ) {
        conta++;
     }
    }
    return conta;
}

