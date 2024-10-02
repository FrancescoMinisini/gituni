#include"my_array_int.h"

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
