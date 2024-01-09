#include <fstream>
#include <iostream>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
#include <cstring>
using namespace std;
#define INCR 20

template <typename T>
struct my_array {
    int size;
    int used;
    T* raw;
};

template <typename T>
void initialize(my_array<T>* p, int d) {
    p->size = d;
    p->used = 0;
    p->raw = new T[d];  // Allocate memory for an array of type T
}

template <typename T>
void initialize(my_array<T>* p, string filename, int& error_code) {
    my_array<T> vettore;
    vettore.size = conta_dati_file(filename);
    vettore.raw = new T[vettore.size];
    if (vettore.raw == nullptr) {
        error_code = -2;
    }
    ifstream data;

    // data.seekg(0, ios::beg); lo riporta all'inizio.
    data.open(filename);

    if (data.fail()) {
        cout << "failed to read file" << endl;
        data.close();
        error_code = -1;
    }

    for (int k = 0; k < vettore.size; k++) {
        data >> vettore.raw[k];
    }

    data.close();
    vettore.used = vettore.size;
    error_code = 0;

    // Copy the initialized values to the target structure
    *p = vettore;
}

template <typename T>
void initialize(my_array<T>* p) {
    p->size = 0;
    p->used = 0;
    p->raw = nullptr;
}

template <typename T>
void dispose(my_array<T>* p) {
    p->size = 0;
    p->used = 0;
    delete[] p->raw;
}

template <typename T>
void insert(my_array<T>* p, T value) {
    if (p->used == p->size) {
        // Assuming resizeMyArray is a valid function for resizing the array
        resizeMyArray(p, p->size + INCR);
    }
    p->raw[p->used] = value;
    (p->used)++;
}

template <typename T>
void insert(my_array<T>* p, T value, int pos) {
    if (p->used == p->size) {
        // Assuming resizeMyArray is a valid function for resizing the array
        resizeMyArray(p, p->size + INCR);
    }

    for (int i = pos; i < p->size; i++) {
        p->raw[i + 1] = p->raw[i];
    }

    p->raw[pos] = value;
    (p->used)++;
}

template <typename T>
void remove(my_array<T>* p, int pos) {
    for (int i = pos; i < p->size - 1; i++) {
        p->raw[i] = p->raw[i + 1];
    }
    (p->used)--;
}

template <typename T>
void deepCpy(my_array<T>* p1, my_array<T>* p2) {
    p2->size = p1->size;
    p2->used = p1->used;
    p2->raw = new T[p1->size];
    memcpy((void*)p2->raw, (void*)p1->raw, p2->used * sizeof(T));
}

template <typename T>
int resizeMyArray(my_array<T>* my_array, int new_dim) {
    T* new_array;
    new_array = new T[new_dim];
    if (new_array == nullptr) {
        cout << "Something went wrong";
        return -1;
    }

    if (my_array->size <= new_dim) {
        for (int i = 0; i < my_array->size; i++) {
            new_array[i] = my_array->raw[i];
        }
    }
    if (my_array->size > new_dim) {
        for (int i = 0; i < new_dim; i++) {
            new_array[i] = my_array->raw[i];
        }
    }
    if (my_array->used > new_dim) {
        my_array->used = new_dim;
    } else {
        my_array->size = new_dim;
    }

    delete[] my_array->raw;
    my_array->raw = new_array;

    return 0;
}

int main() {
    int error_code;
    my_array<int> intArray;
    initialize(&intArray, "filename.txt", error_code);

    my_array<double> doubleArray;
    // Usage for doubleArray goes here

    return 0;
}