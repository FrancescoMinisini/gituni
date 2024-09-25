#include"array.h"


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

void define_array (int voti[],int n) {
    for (int i = 0; i < n ; i++) {
        cout << endl << "inserisci qua il valore "<< i + 1 << ": "<< endl ;
        cin >> voti [i] ; 
        cout << endl;
    }    
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


void scambia(int a[], int v1, int  v2) {
    int appoggio;
    appoggio = a[v1];
    a[v1] = a[v2];
    a[v2] = appoggio;
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

void initialize( my_array_int *p, string directory, int& error_code ){
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