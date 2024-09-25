#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
#define INCR 20

struct puntoR2 {
    double x; 
    double y; 
};
struct my_array_puntiR2 {
    int size;
    int used;
    puntoR2*raw;
} ;
struct my_array_int {
    int size;
    int used;
    int*raw;
};

struct my_array_double {
    int size;
    int used;
    double* raw;
};

float media_array_int (int valori[], int n_elementi) ;

float media_array_float (float valori[], int n_elementi) ;

double media_array_double (double valori[], int N) ;

float stnd_int (int valori[], int n_elementi, float media) ;

float stnd_float (float value [], int ndati, float media) ;

double stnd_double (double value [], int ndati, double media) ; 

bool isOutlier (int valore, float media,float stnd) ;

void scambia(int valori[], int pos1, int  pos2) ;

void scambia_float (float valori[], int pos1, int  pos2) ;

void print_array_int (int valori[], int n_elementi)  ;

void print_array_float (float valori[], int n_elementi) ; 

void print_array_char ( char valori[], int n_elementi) ;

void print_array_double ( double valori[], int n_elementi) ;

void define_array (int valori[],int n_elementi) ;

int resto (int Num, int Den) ;

int MCD ( int p , int q) ;

int posmin(int valori[], int p, int j) ; 

int posmin_float (float valori[], int where, int n_dati) ;

int deleteEntrySwap(int valori[], int size, int used, int where) ;

void ordcrescente(int valori[], int n_elementi) ;

void ordcrescente_float (float valori[], int n_elementi) ;

int conta_dati_file ( string directory ) ;

int conta_coppiedati_file (string directory) ;

void define_array_file_float (float dati[] , int n_dati , string directory);

void define_array_file_int (int dati[] , int n_dati , string directory);

int posmax(int dati[], int from, int n_dati); 

int posmax_float(float dati[], int from, int n_dati); 

float mediana (int dati[], int n_dati);

float mediana_float (float dati[], int n_dati);

void calcolaStats (float dati [], int n_dati , float* pmin, float*pmax, float* pmediana, float* pmedia, float*pstddev);

void print_array_flie_int (int valori[], int n_dati,string directory) ;

bool is_perfect_square(int n);

bool is_prime(int n) ;

int* carica_array_file_int (int& n_dati , string directory);

int conta_primi(int dati [], int n_dati );

int*seleziona_primi (int dati[], int n_dati, int& n_primi);

int resizeMyArray( my_array_int * my_array, int new_dim);

my_array_int carica_interi_file (int& n_dati , string directory, int& error_code);

void print_array_puntiR2  (my_array_puntiR2 dati);

double stima_m (my_array_puntiR2 dati, double x_medio , double y_medio);

double stima_q (my_array_puntiR2 dati , double x_medio , double y_medio , double m);

puntoR2* carica_puntoR2_file (int& n_dati , string directory, int& error_code);

double x_medio (my_array_puntiR2 dati);

double y_medio (my_array_puntiR2 dati);

void stima_retta ( my_array_puntiR2 dati, double& m , double& q);

void print_array_puntiR2  (my_array_puntiR2 dati);

int ricerca (my_array_int v , int chiave) ;

int ricerca_binaria (my_array_int dati, int inizio , int fine , int chiave) ;


void initialize( my_array_int* dati );
void initialize ( my_array_int* dati, int size);
void initialize( my_array_int* dati, string filename, int& error_code );
int peek (my_array_int*p, int pos);
void dispose(my_array_int *p);
void insert (my_array_int* dati, int value);
void remove (my_array_int* dati , int pos);
void insert (my_array_int* dati, int value , int  pos );
void deepCpy (my_array_int *p1, my_array_int*p2);

