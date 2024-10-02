#include<iostream>
using namespace std ; 
#include<cmath>
#include<strings.h>
#include<fstream>

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

double media_array_int (int value [], int ndati) ;

double media_array_float (float value [], int ndati); 

float stnd_int (int value [], int ndati, float media) ;

float stnd_float (float value [], int ndati, float media) ;


int posmin(int a[], int p, int j) ;

int MCD ( int p , int q) ;

bool isOutlier (int valore, float m,float stnd) ;

int resto (int Num, int Den);

double y_medio (my_array_puntiR2 dati);

double x_medio (my_array_puntiR2 dati);

double stima_m (my_array_puntiR2 dati, double xm , double ym);

double stima_q (my_array_puntiR2 dati , double x_medio , double y_medio , double m);

void stima_retta ( my_array_puntiR2 dati, double& m , double& q) ;