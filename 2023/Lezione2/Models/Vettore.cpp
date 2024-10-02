#include "Vettore.h"

Vettore::Vettore(int dim) {
    this->dim = dim; 
    pointer = new double[dim];

    if (dim < 0)
    {
        throw out_of_range("Indice fuori dal range.");
    }
    for (int i = 0; i < dim; i++) {
        pointer[i] = 0;
    }
}

Vettore::Vettore() {
    this->dim = 0;
    this->pointer = nullptr; 
}

Vettore::~Vettore() {
    delete[] pointer; 
}

// Funzione per impostare un valore nel vettore
void Vettore::SetComponent(int index, double value) {
    if (index >= dim || index < 0) {
        throw out_of_range("Indice fuori dal range.");
    }
    pointer[index] = value; // Assegna il valore all'indice specificato
}

double Vettore::GetValue(int index) const
{
    if (index >= dim || index <0)
    {
        throw out_of_range("Indice fuori dal range.");
    }
    return pointer[index];
}

void Vettore::Scambia(int index1, int index2){
    double temp;
    
    if (index1>=dim || index2>= dim ||  index1 <0 ||  index2 <0)
    {
        throw new out_of_range("Index out of range");
    }
    
    temp = this->pointer[index1];
    this->pointer[index1] = this->pointer[index2];
    this->pointer[index2 ] = temp;    
}
Vettore& Vettore::operator=(const Vettore& V) {
  dim = V.Count();
  if ( pointer ) delete[] pointer;
  pointer = new double[dim];
  for (int i=0; i<dim; i++) pointer[i]=V.GetValue(i);
  return *this;
}

