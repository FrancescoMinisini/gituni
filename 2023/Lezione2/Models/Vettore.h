#ifndef __Vettore_h__
#define __Vettore_h__
#include<iostream>
using namespace std;

Vettore::Vettore(){
    dim =0;
    pointer = NULL;
}

Vettore::Vettore(int dim ){
    dim = dim;
    pointer = new double [dim];
    for (int i = 0; i < dim; i++)
    {
        pointer[i] = 0;
    }
}

class Vetttore {
    public:
        int Count () const {return dim;};
        int GetValue (int index) const {
            if (index>dim) throw new exception;
            else return pointer[index];
        };
        void SetComponent(int, double);
        Vettore();
        Vettore(int);
    private:
        int dim;
        double* pointer;
};

void SetComponent(int  index, double value) {
    if ( index >= dim){



    }
}

#endif