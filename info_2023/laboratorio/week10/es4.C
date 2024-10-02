#include<fstream>
#include<iostream>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
#include "/home/francesco/programmazione/gituni/librerie/random/random.h"
using namespace std;
/*void print_array_puntiR2  (my_array_puntiR2 dati);
double stima_m (my_array_puntiR2 dati, double x_medio , double y_medio);
double stima_q (my_array_puntiR2 dati , double x_medio , double y_medio , double m);
double x_medio (my_array_puntiR2 dati);
double y_medio (my_array_puntiR2 dati);
void stima_retta ( my_array_puntiR2 dati, double& m , double& q);
void print_array_puntiR2  (my_array_puntiR2 dati);
puntoR2* carica_puntoR2_file (int& n_dati , string directory, int& error_code) ; 
*/
int main () {
string directory =  "rilevazioni.dat" ;
int n_dati = 0 , error_code = 0;
double m = 0, q = 0 , xm = 0 , ym = 0;  
int& rn_dati = n_dati;
int& rerror_code = error_code;
my_array_puntiR2 dati; 
puntoR2* vettore;
vettore = carica_puntoR2_file ( rn_dati , directory , rerror_code);
n_dati = rn_dati; 
error_code = rerror_code; 
if ( error_code == -2 or error_code == -1 ) {
    cout << endl <<  "somethings gone wrong"<< endl; 
} else {
    dati.size = n_dati; 
    dati.used = n_dati; 
    dati.raw = vettore; 
    xm = x_medio ( dati); 
    ym = y_medio ( dati);
    m = stima_m ( dati, xm , ym);
    q = stima_q ( dati , xm, ym , m);
    if ( q < 0 ) {
    cout << endl << "Y = " << m << "X " << q << endl; }
    else if ( q == 0 ) {
    cout << endl << "Y = " << m << "X ";
    } else if ( q > 0 ) {
        cout << endl << "Y = " << m << "X +" << q << endl;
    }
}
delete[] vettore ;
    return 0; 
}

/*
double stima_m (my_array_puntiR2 dati, double xm , double ym){
    double scarto_x ,scarto_y ,somma_nom = 0 , somma_den = 0 , res = 0; 
    for (int i = 0; i < dati.used; i++)
    {
    scarto_x = dati.raw[i].x - xm ; 
    scarto_y = dati.raw[i].y - ym ;
    somma_nom = somma_nom + scarto_x*scarto_y; 
    somma_den = somma_den + powf64(scarto_x , 2 );
    }
    res = somma_nom / somma_den; 
    return res ; 
}

double stima_q (my_array_puntiR2 dati,  double m, double x_medio , double y_medio  ) {
    double res = x_medio - m*y_medio;   
    return res; 
}

puntoR2* carica_puntoR2_file (int& n_dati , string directory, int& error_code) {
    puntoR2* vettore; 
     
    int j; 
    j = conta_dati_file (directory);
    n_dati = j /2; 
    if ( !(j%2 == 0) ) {
        cout << "il numero di dati non è divisiblile per 2" << endl ;
    }

    vettore = new puntoR2 [n_dati];
    if (vettore == NULL) {
        error_code= -2;
        return vettore;
    }
    ifstream data ;
    
    //data.seekg(0,ios::beg); lo riporta all'inizio.
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
        error_code = -1; 
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> vettore[k].x;
    data >> vettore[k].y;
    }

    data.close () ;
    error_code = 0; 
    return vettore; 
}

double x_medio (my_array_puntiR2 dati) {
    double somma = 0 ;
    double res ;
    if (dati.used == 0){
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
    if (dati.used == 0){
        cout << endl << "array slots used are 0"<< endl; 
    }
    for (int i = 0; i < dati.used; i++)
    {
     somma = somma + dati.raw[i].y ;
    }
    res = (double)somma / dati.used ;

    return res ; 
} 

void print_array_puntiR2  (my_array_puntiR2 dati) {

    for (int i = 0; i < dati.used; i++) {
         cout << "{ " << dati.raw[i].x << " , " <<dati.raw[i].y << " }" << endl;
    }
    
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

*/
