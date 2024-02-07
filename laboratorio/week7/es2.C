#include<iomanip>
#include <iostream> 
#include <fstream>
#include <cstring>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
using namespace std;
bool is_prime(int n);

int main(){

    int numero;

    cout << "Inserire numero: ";
    cin >> numero;

    if(is_prime(numero))
        cout << numero << " e`  primo." << endl;
    else
        cout << numero << " NON e` primo" << endl; 
    return 0;
}

bool is_prime(int n){
    for(int i=2; i<n; i++){
        if(n%i==0) return false;
    }
    return true;
}