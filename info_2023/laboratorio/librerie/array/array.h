#include<fstream>
#include<iostream>
//#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
#include<string.h>
//#include "/home/francesco/programmazione/gituni/librerie/random/random.h"
using namespace std;
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



void initialize( my_array_int* dati, string filename, int& error_code );
void initialize( my_array_int* dati );
void initialize ( my_array_int* dati, int size);
int peek (my_array_int*p, int pos);
void dispose(my_array_int *p);
void insert (my_array_int* dati, int value);
void remove (my_array_int* dati , int pos);
void insert (my_array_int* dati, int value , int  pos );
void deepCpy (my_array_int *p1, my_array_int*p2);
int ricerca_binaria (my_array_int dati, int inizio , int fine , int chiave);
    


int posmin(int a[], int p, int j) ;

int deleteEntrySwap(int v[], int size, int used, int where) ;

void ordcrescente(int a[], int n) ;

void define_array (int voti[],int n) ; 

void print_array_int (int valori[], int num_elementi) ;

void print_array_float (float valori[], int num_elementi) ;

void print_array_char ( char valori[], int num_elementi) ;

void scambia(int a[], int v1, int  v2) ;

int ricerca (my_array_int v , int chiave);

int conta_dati_file ( string directory );