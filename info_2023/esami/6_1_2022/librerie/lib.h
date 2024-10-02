#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
//#include"librerie/funzioni/funzioni.h"


struct evento {
double p1[4]; // energia-momento particella 1 (E1, p1x, p1y, p1z)
double p2[4]; // energia-momento particella 2 (E2, p2x, p2y, p2z)
bool segnale; // Segnale se 1|true, background se 0|false
double massainv; // Massa invariante
};

struct my_array_evento {
    int size, used;
    evento* raw;
};

my_array_evento inizializza_evento ( string directory, int& error_code) ;
int conta_segnale ( evento* dati , int n_dati);
int conta_background ( evento* dati , int n_dati);
void massainv ( my_array_evento );

void print_array_evento_10 (evento* dati , int n , int used);
void merge_sort_evento (evento data[], int init, int final);
void merge_evento (evento data[], int i, int m, int f);
void print_array_evento_4 (evento* dati , int n , int used);

double media_array_double (evento dato[], int N);
double stnd_double (evento* dato , int ndati, double media);
double media_array_double_segnale (evento dato[], int N);
double stnd_double_segnale (evento* dato , int ndati, double media);
int posmin(evento a[], int p, int j);
int posmax(evento* a, int p, int j);
int posmin_segnale (evento a[], int p, int j);
int posmax_segnale (evento* a, int p, int j);
void istogramma(float min, float max, int nbins, float data[], int used, char pixel, int max_n);
