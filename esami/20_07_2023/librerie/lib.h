#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
#include"funzioni/funzioni.h"


struct misura {
double p[4]; // energia-momento (E, px, py, pz)
int carica; // carica elettrica
double eta; // rapidita'
};

struct my_array_misura {
    int size;
    int used;
    misura*raw;
};

misura* inizializza_misura (int& n_dati , string directory, int& error_code);
void stampa_pos ( misura* dati , int d );
void stampa_neut ( misura* dati , int d );
int conta_pos (my_array_misura dati) ;
int conta_neg (my_array_misura dati);

double calcola_eta (misura dato);
void inizzializa_eta ( my_array_misura dati );
void print_array_misura (misura* dati , int n , int used) ;

void merge_misura (misura* data, int i, int m, int f);
void merge_sort_misura(misura* data, int init, int final);
void print_array_misura_3 (misura* dati , int n , int used);


double media_array_double_misura (misura* valori, int N) ;
double stnd_double_misura(misura* value, int ndati, double media) ;
double mediana_double_misura (misura* dati, int n_dati) ;
int posmax_double_misura (misura* a, int p, int j) ;
int posmin_double_misura (misura* a, int p, int j) ;
void calcolaStats_misura ( misura* , int);
misura* copia_neg ( misura* dati , int ndati , int negativi) ;
misura* copia_pos ( misura* dati , int ndati , int negativi) ;
misura* copia_neut ( misura* dati , int ndati , int negativi) ;


