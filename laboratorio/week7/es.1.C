#include<iomanip>
#include <iostream> 
#include <fstream>
#include <cstring>
using namespace std;
 
void print_array_flie_int ( int valori[], int n_dati, string directory);

int main () {
    string directory = "es1.dat" ;
    int n_max = 100 ;
    bool valori[n_max+1];
    int* pos_primi; 
    int n_primi=0 ;
    int h= 0 ; 
    
    for (int  i = 0; i < n_max +1; i++)
    {
        valori [i] = true;
    }
    
    for (int i = 2 ; i < n_max +1 ; i++){
        if (valori[i] == true){
            /*inizia a cercare tra i true quello che divide per i con resto zero 
            e ne cambia il valore*/
            for (int k = i +1; k < n_max+1 ; k++) {
                if (valori[k]==false) {}
                else {
                    if (k%i == 0) {
                        valori[k] = false; 
                        } 
                    else {}
                    }
            } }
        else {}
        }


    for (int i = 2; i < n_max +1; i++)
    {
        if (valori[i]== true ) {
            n_primi++ ; 
        }
    }
    
    pos_primi = new int [n_primi];

    for (int i = 2; i < n_max + 1; i++)
    {
        if (valori[i] == true)
        {
        pos_primi[h] = i ; 
        h++ ; 
        }
        else {}
        
    }
    
    print_array_flie_int (pos_primi, n_primi , directory);

    return 0; 
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