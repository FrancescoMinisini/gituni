#include "random.h"


double rand_gaussiano (double media,  double stdVar){
    double n, res, u1, u2;  
    u1 = rand_uniforme (0, 1);
    u2 = rand_uniforme (0, 1);
    n = sqrt(-2*log(u1))*cos(2*PI*u2);
    res = stdVar*n + media ; 
    return res; 
}

double rand_uniforme(double minimo, double massimo) {
    double res,a; 
    if (massimo<minimo){  cout << "input non validi";  }
    a = (double)rand ()/RAND_MAX;
    res = (massimo-minimo)*a + minimo;


    return res; 
}

void imposta_seed () {
    srand(time(NULL));
}





