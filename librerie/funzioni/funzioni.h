#include<iostream>
using namespace std ; 
#include<cmath>
#include<strings.h>
#include<fstream>

float media (int valori[], int n_elementi) ;

float stnd (int valori[], int n_elementi, float media) ;

bool isOutlier (int valore, float media,float stnd) ;

void scambia(int valori[], int pos1, int  pos2) ;

void print_array_int (int valori[], int n_elementi)  ;

void print_array_float (float valori[], int n_elementi) ; 

void print_array_char ( char valori[], int n_elementi) ;

void define_array (int valori[],int n_elementi) ;

int resto (int Num, int Den) ;

int MCD ( int p , int q) ;

int posmin(int valori[], int p, int j) ; 

int deleteEntrySwap(int valori[], int size, int used, int where) ;

void ordcrescente(int valori[], int n_elementi) ;

int conta_dati_file ( string directory ) ;

int conta_coppiedati_file (string directory) ;