
#include "/home/francesco/programmazione/gituni/librerie/random/random.h"

struct puntoR2 {
    double x; 
    double y; 
};
bool is_inside_circle (puntoR2 p, double r );
double distance ( puntoR2 p );
int count_whithin ( int n , double r);
double rilev(int n, double r);

int main ()  {
    imposta_seed ();
    double res;  
    double r = 0.5;
    double n = 10000000; 
    res =  rilev (n , r);
    cout << endl << res << endl ;
    return 0; 
}


double distance ( puntoR2 p1, puntoR2 p2  ) { 
    double d; 
    d = sqrtf64x( powf64((p1.x-p2.x) , 2) + powf64( (p1.y - p2.y) , 2));
    return d;
}


bool is_inside_circle (puntoR2 p, double r ){
    bool B; 
    puntoR2 O;
    O.x = 0, O.y =0 ; 
    double d  = distance ( p , O );

    if (r < d) {
        B = false;
    } else {
        B = true;
    }

    return B;
}

int count_whithin_circle ( int n , double r) {
    puntoR2 test; 
    int res = 0; 
    for (int i = 0; i < n; i++)
    {
        test.x = rand_uniforme (0 , r);
        test.y = rand_uniforme ( 0 , r); 
        if (is_inside_circle (test , r)) {
            res++ ; 
        }
    }
    return res;
}

double rilev(int n, double r) {
    double res; 
    res = (double)count_whithin (n , r)*4 / n; 
    return res; 
}

