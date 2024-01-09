
#include "/home/francesco/programmazione/gituni/librerie/random/random.h"

double stima_integrale (double min , double max, int n);
double function (double x);

int main (){
    imposta_seed();
    int n= 1000000;
    double res, min= 0 , max= 2;
    res  =stima_integrale ( min , max , n);


    cout<<res << endl;
    return 0;
}

double function (double x) {
    double y;
    y = pow(x, 3)*cos(x);
    return y;
}

double stima_integrale (double min , double max, int n) {
    double x,y= 0, avg, res;
    for (int i = 0; i < n; i++)
    {
        x = rand_uniforme ( min , max);
        y += function (x);
    }
    avg = y/n;
    res = avg*(max-min);
    return res; 
    
}