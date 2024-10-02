#include<cstdlib>
#include<iostream>
using namespace std ; 
#include<cmath>
#include<strings.h>
#include<fstream>
#include<ctime>
#define PI 3.14159

void imposta_seed ();

double randUniforme(double minimo, double massimo);

double randGaussiano (double media,  double std);

int main () {
    imposta_seed();
    double massimo = 10; 
    double minimo = 5; 
    double res = 0 ;
    double res2 = 0 ; 
    res = randUniforme (minimo, massimo); 
    res2 = randUniforme (minimo, massimo);
    cout << res << " "<<res2<< endl ;
    return 0 ; 
    }


double randGaussiano (double media,  double stdVar){
    double n, res, u1, u2;  
    u1 = randUniforme (0, 1);
    u2 = randUniforme (0, 1);
    n = sqrt(-2*log(u1))*cos(2*PI*u2);
    res = stdVar*n + media ; 
    return res; 
}

double randUniforme(double minimo, double massimo) {
    double res,a; 
    if (massimo<minimo){  cout << "input non validi";  }
    a = (double)rand ()/RAND_MAX;
    res = (massimo-minimo)*a + minimo;


    return res; 
}

void imposta_seed () {
    srand(time(NULL));
}

