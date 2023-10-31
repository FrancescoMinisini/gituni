#include<iostream>
using namespace std ;

float massimo (float, float) ;

float massimo (float a, float b) { 

    if (a<=b) {
        return b ;
    }
    else { 
        return a ;
    }
} 
int main  () {
    
    int v1, v2 ;
    
    cin >> v1 >> v2 ;
    
    cout << "il valore piu' grande inserito e': "<< massimo (v1,v2)<< enl;

    return 0;
}