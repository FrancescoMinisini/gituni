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

double x_medio (my_array_puntiR2 dati) {
    double somma = 0 ;
    double res ;
    if (dati.used = 0){
        cout << endl << "array slots used are 0"<< endl; 
    }
    for (int i = 0; i < dati.used; i++)
    {
     somma = somma + dati.raw[i].x ;
    }
    res = (double)somma / dati.used ;

    return res ; 
} 

double y_medio (my_array_puntiR2 dati) {
    double somma = 0 ;
    double res ;
    if (dati.used = 0){
        cout << endl << "array slots used are 0"<< endl; 
    }
    for (int i = 0; i < dati.used; i++)
    {
     somma = somma + dati.raw[i].y ;
    }
    res = (double)somma / dati.used ;

    return res ; 
} 


double stima_m (my_array_puntiR2 dati, double xm , double ym){
    double scarto_x ,scarto_y ,somma_nom = 0 , somma_den = 0 , res = 0; 
    for (int i = 0; i < dati.used; i++)
    {
    scarto_x = dati.raw[i].x - xm ; 
    scarto_y = dati.raw[i].y - ym ;
    somma_nom = somma_nom + scarto_x*scarto_y;
    somma_den = somma_den + powf64 (scarto_x , 2 );
    }
    res = somma_nom / somma_den; 
    return res ; 
}
double stima_q (my_array_puntiR2 dati , double x_medio , double y_medio , double m) {
    double res = x_medio - m*y_medio;   
    return res; 
}

void stima_retta ( my_array_puntiR2 dati, double& m , double& q) {
    double xm = x_medio ( dati), ym = y_medio (dati);
    m = stima_m (dati,xm,ym);
    q = stima_q ( dati ,m , xm , ym);
    if ( q < 0 ) {
    cout << endl << "Y = " << m << "X " << q << endl; }
    else if ( q == 0 ) {
    cout << endl << "Y = " << m << "X ";
    } else if ( q > 0 ) {
        cout << endl << "Y = " << m << "X +" << q << endl;
    }
}