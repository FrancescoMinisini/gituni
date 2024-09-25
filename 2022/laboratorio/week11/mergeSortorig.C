#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
#include "/home/francesco/programmazione/gituni/librerie/random/random.h"
#include<iostream>
using namespace std;

my_array_int merge ( my_array_int v1 ,my_array_int v2);

int main () {
    int dimensione = 10 ;
    my_array_int v1 , v2, res;
    initialize( &v1, dimensione);
    initialize( &v2, dimensione);
    generate_array( v1.raw , v1.size);
    generate_array( v2.raw , v2.size);
    ordcrescente(v1.raw, v1.size);
    ordcrescente(v2.raw, v2.size);
    print_array_int (v1.raw , v1.size );
    print_array_int (v2.raw , v2.size );
    res = merge ( v1, v2);
    print_array_int (res.raw , res.used); 
    return 0;
}

void mergeSort( my_array_int dati , int l , int r) {

}

my_array_int merge ( my_array_int v1 ,my_array_int v2) {
    my_array_int risultato; 
    int*res;
    res = new int [v1.size + v2.size];
    int r = 0 , k= 0 , i=0;
if (v2.raw[0]>v1.raw[v1.size -1]) {
    for (int i = 0; i < v1.size; i++)
    {
        res[i]=v1.raw[i];
    }
    for (int i = 0; i < v2.size; i++)
    {
        res[i]=v2.raw[i];
    }
    }
if (v1.raw[0]>v2.raw[v2.size -1]) {
    for (int i = 0; i < v1.size; i++)
    {
        res[i]=v2.raw[i];
    }
    for (int i = 0; i < v1.size; i++)
    {
        res[i]=v1.raw[i];
    }
    } else {
        do {
            if (v1.raw[r] < v2.raw[k]) {
                res[r+k] = v1.raw[r];
            } else {
                res[r+k] = v2.raw[r];
            }
        } while (k+r <= v1.size + v2.size -2); 
        }
    risultato.raw = res;
    risultato.used = v1.used + v2.used ; 
    risultato.size = v1.size + v2.size ; 
    return risultato;
}


