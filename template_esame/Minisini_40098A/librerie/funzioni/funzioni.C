#include"funzioni.h"
#include<cstring>
#define INCR 20

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

void scambia_float (float a[], int v1, int  v2) {
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

void print_array_double (double valori[], int num_elementi) {

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

int posmin_float (float a[], int p, int j) {
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

void ordcrescente_float (float valori[], int n_elementi) {
 int p = 0;
    for (int i = 0; i < n_elementi; i++) {
        p = posmin_float(valori, i, n_elementi);
        scambia_float(valori, i, p);
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

void define_array_file_float (float dati[] , int n_dati , string directory) {

    ifstream data ;
    
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> dati [k];
    }

    data.close () ;

}

void define_array_file_int (int dati[] , int n_dati , string directory) {

    ifstream data ;
    
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> dati [k];
    }

    data.close () ;

}

int posmax(int a[], int p, int j) {
    int s = a[p];
    int posmax = p;
    for (int i = p + 1; i < j; i++) {
        if (s < a[i]) {
            s = a[i];
            posmax = i;
        }
    }
    return posmax;
}

int posmax_float (float a[], int p, int j) {
    int s = a[p];
    int posmax = p;
    for (int i = p + 1; i < j; i++) {
        if (s < a[i]) {
            s = a[i];
            posmax = i;
        }
    }
    return posmax;
}

float mediana_float (float dati[], int n_dati) {
    float mediana; 
    if (n_dati % 2 == 0){
        mediana = (dati[n_dati/2]+dati[(n_dati/2)-1])/2 ;
    } else {
        mediana = dati[(n_dati-1)/2] ; 
    }
    return mediana ;
}

float mediana (int dati[], int n_dati) {
    float mediana; 
    if (n_dati % 2 == 0){
        mediana = (dati[n_dati/2]+dati[(n_dati/2)-1])/2 ; 
    } else {
        mediana = dati[(n_dati-1)/2] ;
    }
    return mediana ;
}

void calcolaStats (float dati [], int n_dati , float* pmin, float*pmax, float* pmediana, float* pmedia, float*pstddev) {
*pmin = dati[posmin_float(dati , 0 , n_dati)];
*pmax = dati[posmax_float(dati, 0 , n_dati)];
*pmediana = mediana_float (dati, n_dati);
*pmedia = media_array_float (dati, n_dati);
*pstddev = stnd_float (dati, n_dati, *pmedia);
}

void print_array_flie_int (int valori[], int n_dati,string directory) {
    ofstream file;
    file.open (directory) ; 
    if (file.fail() or file.fail()) {
        cout << "failed to read file" << endl ;
    } 

    for (int i = 0; i < n_dati; i++)
    {
        file << valori[i]<< endl;
    }
    file.close ();
    

}

bool is_perfect_square(int n) {
    bool value = false ; 
    float scarto = sqrtf(n)-(int)sqrtf(n);
    if (scarto == 0) {
        value = true; 
    }
    return value;
}

bool is_prime(int n){
    for(int i=2; i<n; i++){
        if(n%i==0) return false;
    }
    return true;
}

int* carica_array_file_int (int& n_dati , string directory) {
    int* dati;
     
    
    n_dati = conta_dati_file (directory); 
   dati = new int [n_dati];
    ifstream data ;
    

    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
        return NULL;
        n_dati = -1; 
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> dati [k];
    }

    data.close () ;


    return dati; 
}

int conta_primi(int dati [], int n_dati ) {
    int n_primi = 0; 
    for (int i = 0; i < n_dati; i++)
        {
            if ( is_prime (dati [i])) {
                n_primi++ ;
            }
        }

        return n_primi; 
    }

int*seleziona_primi (int dati[], int n_dati, int& n_primi) {
        int* primi;
        n_primi = conta_primi ( dati , n_dati );
        primi = new int [n_primi]; 
        int k= 0 ; 
        for (int i = 0; i < n_dati; i++)
        {
            if ( is_prime (dati [i])) {
                primi [k] = dati[i];  
                k++; 
            }
        }
        return primi; 
    }

int resizeMyArray( my_array_int * my_array, int new_dim) {
    int* new_array;
    new_array = new int [new_dim];
    if (new_array == NULL) {
        cout << "qualcosa è andato storto";
        return -1; 
    }

    if (my_array->size <= new_dim) {
        for (int i = 0; i < my_array->size; i++)
        {
             new_array [i] = my_array->raw[i];        }
           
    }
    if (my_array->size > new_dim) {
        for (int i = 0; i < new_dim; i++)
        {
            new_array [i] = my_array->raw[i];        }
            
    }
       if (my_array->used > new_dim) {
        my_array->used = new_dim;
       } else {
        my_array->size = new_dim;
        }

        delete [] my_array->raw;
        my_array->raw = new_array;
        
        return 0;
}

my_array_int carica_interi_file (int& n_dati , string directory, int& error_code) {
    my_array_int vettore; 
     
    
    vettore.size = conta_dati_file (directory);
    n_dati =vettore.size;
    vettore.raw = new int [vettore.size];
    if (vettore.raw == NULL) {
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

    for (int k = 0 ; k< vettore.size ; k++){
    data >> vettore.raw[k];
    }

    data.close () ;
    vettore.used=vettore.size;
    error_code = 0; 
    return vettore; 
}

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

void print_array_puntiR2  (my_array_puntiR2 dati) {

    for (int i = 0; i < dati.used; i++) {
         cout << "{ " << dati.raw[i].x << " , " <<dati.raw[i].y << " }" << endl;
    }
    
}

int ricerca (my_array_int v , int chiave) {
    int pos = -1; 
    for (int i = 0 ; i < v.used  ; i++)
    {
        if ( v.raw[i] == chiave){
            pos = i;
            break;
        }
    }
    return pos;
}

int ricerca_binaria (my_array_int dati, int inizio , int fine , int chiave) {
int m = (inizio + fine)/2 ;
if (dati.raw[m] == chiave) {
    return m; 
}
else if ( dati.raw[m] > fine ){
    cout << endl <<"qualcosa è andato storto nella ricerca" << endl; 
    return -1;
}
else {
    if ( dati.raw[m] > chiave) {
        return ricerca_binaria (dati , inizio , m-1 , chiave );
    }
    else {
        return ricerca_binaria ( dati , m+1 , fine, chiave);
    }
    } 
}

void initialize (my_array_int* p) {
p->size = 0; //(*p).size
p->used = 0;
p->raw = NULL;
}

void initialize (my_array_int *p, int d) {
    p->size = d;
    p->used = 0;
    p->raw = new int[d];  // Allocate memory for an array of integers
}

void initialize ( my_array_int *p, string directory, int& error_code ){
    my_array_int vettore; 
    vettore.size = conta_dati_file(directory);
    vettore.raw = new int [vettore.size];
    if (vettore.raw == NULL) {
        error_code= -2;
    }
    ifstream data ;
    
    //data.seekg(0,ios::beg); lo riporta all'inizio.
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
        error_code = -1; 
    } 

    for (int k = 0 ; k< vettore.size ; k++){
    data >> vettore.raw[k];
    }

    data.close () ;
    vettore.used=vettore.size;
    error_code = 0; 
}

int peek (my_array_int*p, int pos) {
    return p->raw[pos];
}

void dispose(my_array_int *p){
p->size = 0; //(*p).size
p->used = 0;
delete [] p->raw;
}

void insert (my_array_int* dati, int value){
    if (dati->used == dati->size) {
        resizeMyArray (dati, dati->size + INCR);
    }
    dati->raw[dati->used] = value;
(dati->used)++;
}

void insert (my_array_int* dati, int value , int  pos ){
    if (dati->used == dati->size) {
        resizeMyArray (dati, dati->size + INCR);
    }

    for (int i = pos ; i < dati->size; i++)
    {
        dati->raw[i+1] = dati->raw[i];
    }
    
    dati->raw[pos] = value;
    (dati->used)++;
}

void remove (my_array_int* dati , int pos) {
    for (int i = 0; i < dati->size -1; i++)
    {
        dati->raw[i] = dati->raw[i+1];
    }
    (dati->used)--;
}

void deepCpy (my_array_int *p1, my_array_int*p2)
{
p2->size =p1->size;
p2->used =p1->used;
p2->raw = new int [p1->size];
memcpy((void*) p2->raw,(void*) p1->raw, p2->used*sizeof(int));
}




void merge_ints(int data[], int i, int m, int f){
    int j, k, z;
    int* tmp = NULL; 
    tmp = new int[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j] <= data[k]) {
            tmp[z] = data[j];
            j++;
        } else {
            tmp[z] = data[k];
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++){
            tmp[z] = data[k];
            z++;
        }
    } else {
        for (j; j <= m; j++){
            tmp[z] = data[j];
            z++;
        }
    }

    //ricopia tmp in data
    z = 0;
    for (z; z < f-i+1; z++){
        data[i+z] = tmp[z];
    }

    delete []tmp;
    tmp = NULL;
}


void merge_sort_int(int data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_int(data, init, m);
        merge_sort_int(data, m+1, final);
        merge_ints(data, init, m, final);
    }
}


void merge_floats(float data[], int i, int m, int f){
    int j, k, z;
    float* tmp; 
    tmp = new float[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j] <= data[k]) {
            tmp[z] = data[j];
            j++;
        } else {
            tmp[z] = data[k];
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++){
            tmp[z] = data[k];
            z++;
        }
    } else {
        for (j; j <= m; j++){
            tmp[z] = data[j];
            z++;
        }
    }

    //ricopia tmp in data
    z = 0;
    for (z; z < f-i+1; z++){
        data[i+z] = tmp[z];
    }

    delete []tmp;
    tmp = NULL;
}


void merge_sort_float(float data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_float(data, init, m);
        merge_sort_float(data, m+1, final);
        merge_floats(data, init, m, final);
    }
}


void merge_doubles(double data[], int i, int m, int f){
    int j, k, z;
    double* tmp; 
    tmp = new double[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j] <= data[k]) {
            tmp[z] = data[j];
            j++;
        } else {
            tmp[z] = data[k];
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++){
            tmp[z] = data[k];
            z++;
        }
    } else {
        for (j; j <= m; j++){
            tmp[z] = data[j];
            z++;
        }
    }

    //ricopia tmp in data
    z = 0;
    for (z; z < f-i+1; z++){
        data[i+z] = tmp[z];
    }

    delete []tmp;
    tmp = NULL;
}


void merge_sort_double(double data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_double(data, init, m);
        merge_sort_double(data, m+1, final);
        merge_doubles(data, init, m, final);
    }
}




void merge_sort_decr(float data[], int i, int f);

void merge_floats(float data[], int i, int m, int f) {
    int j, k, z;
    float* tmp; 
    tmp = new float[f - i + 1];

    j = i; // indice del primo sottovettore
    k = m + 1; // indice del secondo sottovettore
    z = 0; // indice di tmp

    while (j <= m && k <= f) {
        if (data[j] >= data[k]) { // Cambiato da <= a >= per l'ordinamento decrescente
            tmp[z] = data[j];
            j++;
        } else {
            tmp[z] = data[k];
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++) {
            tmp[z] = data[k];
            z++;
        }
    } else {
        for (j; j <= m; j++) {
            tmp[z] = data[j];
            z++;
        }
    }

    // ricopia tmp in data
    z = 0;
    for (z; z < f - i + 1; z++) {
        data[i + z] = tmp[z];
    }

    delete[] tmp;
    tmp = NULL;
}

void merge_sort_decr(float data[], int i, int f) {
    if (i < f) {
        int m = i + (f - i) / 2;

        merge_sort_decr(data, i, m);
        merge_sort_decr(data, m + 1, f);

        merge_floats(data, i, m, f);
    }
}






















