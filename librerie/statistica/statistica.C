#include"statistica.h"

double media_array_int (int value [], int ndati) { 
    int somma = 0 ;
    double media ;
    for ( int i = 0; i < ndati ; i++) {
        somma = somma + value [i] ;
    }

    media = (double)somma / ndati ;

    return media;
}

double media_array_float (float value [], int ndati) { 
    float somma = 0 ;
    double media ;
    for ( int i = 0; i < ndati ; i++) {
        somma = somma + value [i] ;
    }

    media = (double)somma / ndati ;

    return media;
}

float stnd_int(int value [], int ndati, float media) {
    float dev ;
    float scarto = 0;
    float somma = 0 ;
    for( int i = 0; i < ndati ; i++) {
        scarto = ( value[i]-media )  ;
        somma = somma + pow(scarto , 2 ) ;
    }
    dev = sqrt (somma / (ndati-1));
    return dev;
}

float stnd_float (float value [], int ndati, float media) {
    float dev ;
    float scarto = 0;
    float somma = 0 ;
    for( int i = 0; i < ndati ; i++) {
        scarto = ( value[i]-media )  ;
        somma = somma + pow(scarto , 2 ) ;
    }
    dev = sqrt (somma / (ndati-1));
    return dev;
}

int posmin(int a[], int p, int j) {
    int s = a[p];
    int posmin = p;
    for (int i = p + 1; i < j; i++) {
        if (s > a[i]) {
            s = a[i];
            posmin = i;
        }
    }
    return posmin;
}

int MCD ( int p , int q) {
    int mcd, r ;
    do {
        r = resto (p,q) ;
        p = q ; 
        q = r ; 
    } while (q != 0) ; 
    return p ; 
} 
bool isOutlier (int valore, float m,float stnd) {

    float abs, c ; 
    abs = fabs(valore - m) ; 
    c = 3*stnd ;

    return abs > c ;

}
int resto (int Num, int Den) {
    int q, r ;
    q =  Num/Den ; 
    r = Num - q*Den ;
    return r ; 

}