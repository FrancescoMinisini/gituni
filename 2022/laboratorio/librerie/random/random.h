#include<cstdlib>
#include<iostream>
using namespace std ; 
#include<cmath>
#include<strings.h>
#include<fstream>
#include <ctime>
#define PI 3.14159

double rand_uniforme(double minimo, double massimo);

double rand_gaussiano (double media,  double std);

void imposta_seed ();

void generate_array ( int dati [], int n_dati);
