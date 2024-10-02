#ifndef __VETTORE_H__
#define __VETTORE_H__

#include <iostream>
#include <exception>

using namespace std;

class Vettore {
public:

    Vettore(); // Costruttore di default
    Vettore(int); // Costruttore con dimensione
    ~Vettore();

    int Count() const { return dim; }
    double GetValue(int index) const;
    void SetComponent(int index, double value);
    void Scambia(int, int);

private:
    int dim; // Dimensione del vettore
    double* pointer; // Puntatore all'array dinamico
};

#endif
 