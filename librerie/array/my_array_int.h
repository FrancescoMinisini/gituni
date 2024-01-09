#include<fstream>
#include<iostream>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
#include<string.h>
//#include "/home/francesco/programmazione/gituni/librerie/random/random.h"
using namespace std;
#define INCR 20 

void initialize( my_array_int* dati, string filename, int& error_code );
void initialize( my_array_int* dati );
void initialize ( my_array_int* dati, int size);
int peek (my_array_int*p, int pos);
void dispose(my_array_int *p);
void insert (my_array_int* dati, int value);
void remove (my_array_int* dati , int pos);
void insert (my_array_int* dati, int value , int  pos );
void deepCpy (my_array_int *p1, my_array_int*p2);
