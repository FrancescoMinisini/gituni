#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
#include"librerie/funzioni/funzioni.h"

struct netpacket{
int time; // timestamp del pacchetto
double db; // qualita' del pacchetto
char dato; // carattere del messaggio
};

struct my_array_netpacket {
    int size;
    int used;
    netpacket*raw;
};

netpacket* inizializza_netpacket (int& n_dati , string directory, int& error_code);
void stampa_ko ( netpacket* dati , int n_dati);
void stampa_ok ( netpacket* dati , int n_dati);

void clean (my_array_netpacket* dati);
void remove (my_array_netpacket* dati , int pos);
void stampa ( my_array_netpacket dati  );


void merge_netpacket (netpacket data[], int i, int m, int f);
void merge_sort_netpacket(netpacket data[], int init, int final);
void print_array_netpacket (netpacket* dati , int n , int used);

void codifica (my_array_netpacket dati);

int main(){
    int n_dati = 0, error_code = 0 ; 
    string directory = "dati.dat";
    netpacket* data ;
    //1
    data = inizializza_netpacket ( n_dati , directory , error_code);
    //stampa_ok ( data ,n_dati); 
    //stampa_ko ( data , n_dati);
    //cout << n_dati;
    //2
    my_array_netpacket vettore;
    vettore.size = n_dati;
    vettore.used = n_dati;
    vettore.raw = data ; 
    clean (&vettore);
    //stampa (vettore);
    //3
    merge_sort_netpacket (vettore.raw , 0 , vettore.used);
    //stampa (vettore) ; 
    //print_array_netpacket ( vettore.raw , 5 , vettore.used);
    //4
    codifica ( vettore);

    return 0;
}


netpacket* inizializza_netpacket (int& n_dati , string directory, int& error_code) {
    netpacket* vettore; 
    ifstream data ;
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
    }
    
    int time; // timestamp del pacchetto
    double db; // qualita' del pacchetto
    char dato;

    n_dati = 0 ; 
    data >> time >> db >> dato ;
    
    while (!data.eof()) {
        n_dati++ ;
        data >> time >> db >> dato ;
    }
     data.close () ;

    vettore = new netpacket [n_dati];
    
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
    data >> vettore[k].time;
    data >> vettore[k].db;
    data >> vettore[k].dato;
    //data >> vettore[k].stato;
    }

    data.close () ;

    error_code = 0; 
    return vettore; 
}

void stampa_ok ( netpacket* dati , int n_dati){
    for (int i = 0; i < n_dati; i++)
    {
        if (dati[i].db >= 90 ){
         cout  << "{ " << dati[i].time << " , " <<dati[i].db << " , " <<dati[i].dato <<  " } "<< endl;
        }
    }
    
}

void stampa_ko ( netpacket* dati , int n_dati){

    for (int i = 0; i < n_dati; i++)
    {
        if (!(dati[i].db >= 90) ){
         cout  << "{ " << dati[i].time << " , " <<dati[i].db << " , " <<dati[i].dato <<  " } "<< endl;
        }
    }
    
}
 
void stampa ( my_array_netpacket dati  ){
    for (int i = 0; i < dati.used; i++)
    {
         cout  << "{ " << dati.raw[i].time << " , " <<dati.raw[i].db << " , " <<dati.raw[i].dato <<  " } "<< endl;
    }
    }

void clean (my_array_netpacket* dati) {
    for (int i = 0; i < dati->used; i++)
    {
        if (dati->raw[i].db < 90) {
            remove(dati , i);
            i--; 
        }
    }
} 

void remove (my_array_netpacket* dati , int pos) {

    for (int i = pos; i < dati->size -1; i++)
    {
        dati->raw[i] = dati->raw[i+1];
    }
    (dati->used)--;
}



void merge_netpacket (netpacket data[], int i, int m, int f){
    int j, k, z;
    netpacket* tmp ;//= NULL; 
    tmp = new netpacket[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j].time <= data[k].time) {
            tmp[z] = data[j];
            j++;
        } else {
            tmp[z] = data[k];
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++){
            tmp[z] = data[k];
            z++;
        }
    } else {
        for (j; j <= m; j++){
            tmp[z] = data[j];
            z++;
        }
    }

    //ricopia tmp in data
    z = 0;
    for (z; z < f-i+1; z++){
        data[i+z] = tmp[z];
    }

    delete []tmp;
    tmp = NULL;
}


void merge_sort_netpacket (netpacket data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_netpacket(data, init, m);
        merge_sort_netpacket(data, m+1, final);
        merge_netpacket(data, init, m, final);
    }
}

void print_array_netpacket (netpacket* dati , int n , int used) {

    for (int i = 0; i < n; i++) {
         cout  << "{ " << dati[i].time << " , " <<dati[i].db << " , " <<dati[i].dato <<  " } "<< endl;
    }
     for (int i = used-1 ; i > used - n -1 ; i--) {
         cout  << "{ " << dati[i].time << " , " <<dati[i].db << " , " <<dati[i].dato <<  " } "<< endl;
    }

}

void codifica (my_array_netpacket dati) {
    char boh[] = "#?" ;
    for (int i = 0; i < dati.used ; i++)
    {
        if ( dati.raw[i].dato == boh[0]){
            cout << " " ;
            
        }
        else if ( dati.raw[i].dato == boh[1]){
            cout << endl ;
            }
        else cout << dati.raw[i].dato ; 
    
    }}



