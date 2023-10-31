#include<iostream>
#include<cmath>

double media_array (int value [], int ndati) { 
    int somma = 0 ;
    double media ;
    
    for ( int i = 0; i < ndati ; i++) {
        somma = somma + value [i] ;
    }

    media = (double)somma / ndati ;

    return media;
}

float devstd(int value [], int ndati, float media) {
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

