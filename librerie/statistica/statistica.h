#include<iostream>
using namespace std ; 
#include<cmath>
#include<strings.h>
#include<fstream>


double media_array_int (int value [], int ndati) ;

double media_array_float (float value [], int ndati); 

float stnd_int (int value [], int ndati, float media) ;

float stnd_float (float value [], int ndati, float media) ;


int posmin(int a[], int p, int j) ;

int MCD ( int p , int q) ;

bool isOutlier (int valore, float m,float stnd) ;

int resto (int Num, int Den);