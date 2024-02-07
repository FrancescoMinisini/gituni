#include<iostream>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
#include "/home/francesco/programmazione/gituni/librerie/random/random.h"
using namespace std;
#define increment 50
int resizeMyArray( my_array_puntiR2 * my_array, int new_dim);
my_array_puntiR2 carica_dati_file(int& n_dati, string directory, int& error_code);

void print_array_puntiR2  (my_array_puntiR2 dati[], int num_elementi);

int resizeMyArray( my_array_puntiR2 * my_array, int new_dim) {
    puntoR2* new_array;
    new_array = new puntoR2 [new_dim];
    if (new_array == NULL) {
        cout << "qualcosa è andato storto";
        return -1; 
    }

    if (my_array->size <= new_dim) {
        for (int i = 0; i < my_array->size; i++)
        {
             new_array[i].x = my_array->raw[i].x;   
             new_array[i].y = my_array->raw[i].y;
        }
           
    }
    if (my_array->size > new_dim) {
        for (int i = 0; i < new_dim; i++)
        {
            new_array[i].x = my_array->raw[i].x;   
             new_array[i].y = my_array->raw[i].y;        }
            
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

my_array_puntiR2 carica_dati_file(int& n_dati, string directory, int& error_code) {
    my_array_puntiR2 punti;
    punti.size = increment;
    punti.raw = new puntoR2[punti.size];
    
    ifstream data;
    data.open(directory);

    if (data.fail()) {
        cout << "Failed to read file" << endl;
        data.close();
        error_code = -1;
        return punti;
    }
int i = 0 ;
do{
do{
    data >> punti.raw[i].x;
    data >> punti.raw[i].y;
    i++;
} while (!data.eof() && i<increment);
 if (data.eof()) {
    resizeMyArray ( &punti , (punti.size + increment));
 }
} while (!data.eof());


    data.close();
    punti.used = punti.size;
    error_code = 0;
    return punti;
}

int main() {
   string directory = "rilevazioni.dat";
   my_array_puntiR2* dati; 
   dati->size = 0; 
   int rn = dati->size;
   int error_code;
    carica_dati_file ( rn , directory , error_code);
    print_array_puntiR2 (dati, dati->used);
    return 0;
}

void print_array_puntiR2  (my_array_puntiR2 dati[], int num_elementi) {

    for (int i = 0; i < num_elementi-1; i++) {
         cout << "{ " << dati->raw[i].x << " , " <<dati->raw[i].y << " }" << endl;
    }
    
}