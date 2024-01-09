#include "/home/francesco/programmazione/gituni/librerie/random/random.h"
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
#include<iostream>
using namespace std;


void bogoSort ( int a [] , int used);
bool isSorted ( int a [], int used);
void generate_array ( int a[] , int);

int main () {
    int n_dati = 10;
    int dati [n_dati];
   // char risposta; 
    imposta_seed();
    generate_array ( dati, n_dati);
    print_array_int ( dati , n_dati);
    //cout << "would you like to continue and sort the array? [Y/N]"<< endl;
    //cin << risposta; 
    
    //if (risposta == "Y" ) {
    bogoSort (dati, n_dati);
    print_array_int ( dati , n_dati);
   // }
    return 0;
}


void bogoSort(int a[], int used) {
    while (!isSorted(a, used)) {
        for (int i = 0; i < used - 1; i++) {
            int index = (int)rand_uniforme(i, used);
            // Swap elements at i and index
            int temp = a[i];
            a[i] = a[index];
            a[index] = temp;
        }
    }
}

bool isSorted ( int a [], int used) {
    bool res =  true; 
    int i = 0; 
    do
    {
        if (a[i] >= a[i+1]) {
            res = false ; 
        }
        i++;
    } while (res && i <= used-1);
    return res; 
}

void generate_array ( int dati [], int n_dati) {
    int appo ; 
    for (int i= 0 ; i < n_dati ; i++){
        appo = (int)rand_uniforme(0,1000);
        dati[i]= appo;
    }

}