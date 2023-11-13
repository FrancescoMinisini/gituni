#include"funzioni.h"

float media_array_int (int valori[], int N) {
    int somma = 0 ;
    float res ;
    for (int i = 0; i < N; i++)
    {
     somma = somma + valori [i] ;
    }
    res = (float)somma / N ;

    return res ; 
} 
float media_array_float (float valori[], int N) {
    float somma = 0 ;
    float res ;
    for (int i = 0; i < N; i++)
    {
     somma = somma + valori [i] ;
    }
    res = (float)somma / N ;

    return res ; 
} 

double media_array_double (double valori[], int N) {
    double somma = 0 ;
    double res ;
    for (int i = 0; i < N; i++)
    {
     somma = somma + valori [i] ;
    }
    res = (double)somma / N ;

    return res ; 
} 



float stnd_int (int valori[], int N, float m) {
    float sum_scarto = 0 ; 
    float res ;
    for (int i = 0; i < N; i++)
    {
     sum_scarto = pow(valori [i] - m,2) + sum_scarto ;
    }
    res = sqrt(sum_scarto / (-1)) ;
    return res ;
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


double stnd_double (double value [], int ndati, double media) {
    double dev ;
    double scarto = 0;
    double somma = 0 ;
    for( int i = 0; i < ndati ; i++) {
        scarto = ( value[i]-media )  ;
        somma = somma + pow(scarto , 2 ) ;
    }
    dev = sqrt (somma / (ndati-1));
    return dev;
}


bool isOutlier (int valore, float m,float stnd) {

    float abs, c ; 
    abs = fabs(valore - m) ; 
    c = 3*stnd ;

    return abs > c ;

}

void scambia(int a[], int v1, int  v2) {
    int appoggio;
    appoggio = a[v1];
    a[v1] = a[v2];
    a[v2] = appoggio;
}

void print_array_int (int valori[], int num_elementi) {

    cout << "{ " ;
    for (int i = 0; i < num_elementi-1; i++) {
         cout << valori [i] << " , " ;
    }
    cout << valori [num_elementi-1] << " }" << endl ;
}

void print_array_float (float valori[], int num_elementi) {

    cout << "{ " ;
    for (int i = 0; i < num_elementi-1; i++) {
         cout << valori [i] << " , " ;
    }
    cout << valori [num_elementi-1] << " }" << endl ;
}

void print_array_char ( char valori[], int num_elementi) {

    cout << "{ " ;
    for (int i = 0; i < num_elementi-1; i++) {
         cout << valori [i] << " , " ;
    }
    cout << valori [num_elementi-1] << " }" << endl ;
}

void define_array (int voti[],int n) {
    for (int i = 0; i < n ; i++) {
        cout << endl << "inserisci qua il valore "<< i + 1 << ": "<< endl ;
        cin >> voti [i] ; 
        cout << endl;
    }    
}

int resto (int Num, int Den) {
    int q, r ;
    q =  Num/Den ; 
    r = Num - q*Den ;
    return r ; 

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

int deleteEntrySwap(int v[], int size, int used, int where) {
    for (int i = where; i < used; i++)
    {
      v [i] = v [i + 1] ;
    }
    used = used - 1 ;
    return used ; 
}

void ordcrescente(int a[], int n) {
    int p = 0;
    for (int i = 0; i < n; i++) {
        p = posmin(a, i, n);
        scambia(a, i, p);
    }
}

int conta_dati_file ( string directory ) {
    int i = 0 ;
    float appo ;
    ifstream data ;
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        return -1 ;
    }
    
    data >> appo;
    
    while (!data.eof()) {
        i++ ;
        data >> appo ;
    }

    return i ;
}

int conta_coppiedati_file (string directory){
    float dato ;
    char colore ;
    int n_dati = 0 ;
   
    ifstream data ;

    data.open(directory) ;
    
    if (data.fail() ) {
        cout << "failed to read file" << endl ;
        return -1 ;
    } 
    
    data >> dato;
    data >> colore ;
    while (!data.eof()) {
        n_dati++ ;
        data >> dato ;
        data >> colore ;
    }
    data.close () ;
    return n_dati;

}