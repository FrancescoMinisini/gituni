
#include "funzioni.h"
//#include "../librerie/random/random.h"

#include<iostream>


using namespace std;


//void initialize ( my_array_int* dati, int size);
my_array_int merge ( my_array_int v1 ,my_array_int v2);
void mergeSort( my_array_int dati , int l , int r);

int main () {
    int dimensione = 10 ;
    my_array_int* v1 , *v2, *res;
    v1->size = dimensione;
    v2->size = dimensione; 
    v1->used = dimensione;
    v2->used = dimensione;
    initialize( v1, dimensione);
    /*initialize( v2, dimensione);
    generate_array( v1.raw , v1.size);
    generate_array( v2.raw , v2.size);
    ordcrescente(v1.raw, v1.size);
    ordcrescente(v2.raw, v2.size);
    print_array_int (v1.raw , v1.size );
    print_array_int (v2.raw , v2.size );
    res = merge ( v1, v2);
    cout << res.size << "   " << res.used ;
    print_array_int (res.raw , res.used);*/ 
    return 0;
}





void mergeSort( my_array_int dati , int l , int r) {

}


my_array_int merge(my_array_int v1, my_array_int v2) {
    my_array_int risultato;
    int* res;
    res = new int[v1.size + v2.size];
    int r = 0, k = 0;

    if (v2.raw[0] > v1.raw[v1.size - 1]) {
        for (int i = 0; i < v1.size; i++) {
            res[i] = v1.raw[i];
        }
        for (int i = 0; i < v2.size; i++) {
            res[v1.size + i] = v2.raw[i]; // Append elements from v2
        }
    }

    if (v1.raw[0] > v2.raw[v2.size - 1]) {
        for (int i = 0; i < v2.size; i++) {
            res[i] = v2.raw[i];
        }
        for (int i = 0; i < v1.size; i++) {
            res[v2.size + i] = v1.raw[i]; // Append elements from v1
        }
    } else {
        do {
            if (r < v1.size && (k >= v2.size || v1.raw[r] < v2.raw[k])) {
                res[r + k] = v1.raw[r];
                r++;
            } else {
                res[r + k] = v2.raw[k];
                k++;
            }
        } while (r < v1.size || k < v2.size);
    }

    risultato.raw = res;
    risultato.used = v1.used + v2.used;
    risultato.size = v1.size + v2.size;

    // Free the allocated memory
    delete[] res;

    return risultato;
}


/*void initialize (my_array_int *p, int d) {
    p->size = d;
    p->used = 0;
    p->raw = new int[d];  // Allocate memory for an array of integers
}
*/

