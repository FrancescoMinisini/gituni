#include<iostream>
using namespace std;
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"


/*
//my_array->raw === (*my_array).raw diverso da my_array.raw
struct my_array_int {
    int size;
    int used;
    int* raw;
};
*/
int resizeMyArray( my_array_int * my_array, int new_dim);

int main (){
    my_array_int my_array;
    my_array.size = 8;
    my_array.used = 10;
    my_array.raw = new int [my_array.size]; 
    int new_size = 5; 
    
    define_array (my_array.raw , my_array.size);
    resizeMyArray(&my_array,new_size);
    print_array_int( my_array.raw , new_size);
    cout << my_array.used << " "<< my_array.size;
    delete [] my_array.raw;
    return 0;
}

/*int resizeMyArray( my_array_int * my_array, int new_dim) {
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
    }*/

