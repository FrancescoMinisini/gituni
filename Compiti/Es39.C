#include<iostream>
#include<cmath>
using namespace std ; 

void define_array (int,int); 
int deleteEntrySwap(float , int , int , int );
void print_array (int, int) ; 

int deleteEntrySwap(int v[], int size, int used, int where) {
    for (int i = where; i < used; i++)
    {
      v [i] = v [i + 1] ;
    }
    used = used - 1 ;
    return used ; 
}

void print_array (int valori[], int num_elementi) {

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

int main() {
    int n, used , where ; 
    cout << "dichiara qual'è il numero di voti: " << endl ; 
    cin >> n ;
    used = n;
    int voti [n] ;
    define_array (voti,n);
    
    do {
    
    cout << endl << "posizione dell'elemento che vuoi eliminare: ";
    
    cin >> where ;
    
    where = where -1 ;
    
    cout << endl ;
    
    if (where > used or where < 0) {
        cout << endl << "indici fuori range" << endl ;
    }
    } while (where > used or where < 0) ;
    
    
    used = deleteEntrySwap (voti, n , used, where) ;
    
    print_array (voti, used) ; 

    return 0;
}
