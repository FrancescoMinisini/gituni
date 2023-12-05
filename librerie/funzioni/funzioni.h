#include<iostream>
using namespace std ; 
#include<cmath>
#include<strings.h>
#include<fstream>

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

