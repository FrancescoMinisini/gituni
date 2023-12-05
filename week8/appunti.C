#include<iostream>
using namespace std; 

struct my_array_float {
    int size;
    int used ;
    float* dati ; 
};


int main() {
    my_array_float v; 
    int appo; 
    cout << endl << "dimensione aray: ";
    cin >> appo ; 
    v.size = appo ; 
    v.used = 0; 
    v.dati = new float [v.size]; 

    for (int i = 0; i < v.size; i++)
    {
        v.dati [i] = 0.2*i;
        v.used++; 
    }

    cout << endl<< "usati " << v.used<< "elementi";

    for (int  i = 0; i < v.used; i++)
    {
        cout << v.dati[i]<< endl ; 
    }
    
    delete [] v.dati;  
    v.size = 0; 
    v.used = 0; 

    return 0 ;
}



