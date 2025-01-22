#ifndef __VETTORE_H__
#define __VETTORE_H__

#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class Vettore
{
public:
    Vettore(); // Costruttore di default
    Vettore(int);
    Vettore(int, const string);
    ~Vettore();

    Vettore &operator=(const Vettore &);
    int Count() const { return dim; }
    T GetValue(int index) const;
    void SetComponent(int index, double value);
    void Scambia(int, int);
    T &operator[](int) const;
    double  GetAverage() const;
    double GetMediana() const;
    double GetVarianza() const;
    void Print();

private:
    int dim;         // Dimensione del vettore
    T* pointer; // Puntatore all'array dinamico
};

template <typename T>
void Vettore<T>::Print()
{
    cout << endl
         << "[ ";
    for (int i = 0; i < this->dim; i++)
    {
        if (i == 0)
        {
            cout << this->pointer[i];
        }
        else
        {
            cout << " , " << this->pointer[i];
        }
    }
    cout << " ]" << endl;
}

template <typename T>
double Vettore<T>::GetAverage() const
{
    double result = 0;
    for (int i = 0; i < dim; i++)
    {
        result += pointer[i] / dim;
    }
    return result;
}

template <typename T>
double Vettore<T>::GetVarianza() const
{
    if (dim == 0)
    {
        throw out_of_range("Vettore vuoto, impossibile calcolare la varianza.");
    }

    double media = this ->GetAverage();
    double varianza = 0.0;
    for (int i = 0; i < dim; i++)
    {
        double diff = this->pointer[i] - media;
        varianza += diff * diff;
    }

    return varianza / (double)dim;
}
template <typename T>
double Vettore<T>::GetMediana() const {
    if (dim == 0) {
        throw out_of_range("Vettore vuoto, impossibile calcolare la mediana.");
    }

    // Copia l'array originale in un nuovo Vettore temporaneo
    Vettore<T> temp;
    temp = *this;

    // Implementazione della selection sort
    for (int i = 0; i < dim - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < dim; j++) {
            if (temp.pointer[j] < temp.pointer[minIndex]) {
                minIndex = j;
            }
        }
        // Scambia i valori
        temp.Scambia(i, minIndex);
    }
    // Calcola la mediana
    if (dim % 2 == 0) {
        return (temp.pointer[dim / 2 - 1] + temp.pointer[dim / 2]) / 2.0;
    } else {
        return temp.pointer[dim / 2];
    }
}


template <typename T>
Vettore<T>::Vettore(int dim)
{
    this->dim = dim;
    pointer = new T[dim];

    if (dim < 0)
    {
        throw out_of_range("Indice fuori dal range.");
    }
    for (int i = 0; i < dim; i++)
    {
        pointer[i] = 0;
    }
}

template <typename T>
Vettore<T>::Vettore()
{
    this->dim = 0;
    this->pointer = nullptr;
}

template <typename T>
Vettore<T>::~Vettore()
{
    delete[] pointer;
}

// Funzione per impostare un valore nel vettore
template <typename T>
void Vettore<T>::SetComponent(int index, double value)
{
    if (index >= dim || index < 0)
    {
        throw out_of_range("Indice fuori dal range.");
    }
    pointer[index] = value; // Assegna il valore all'indice specificato
}

template <typename T>
T Vettore<T>::GetValue(int index) const
{
    if (index >= dim || index < 0)
    {
        throw out_of_range("Indice fuori dal range.");
    }
    return pointer[index];
}

template <typename T>
void Vettore<T>::Scambia(int index1, int index2)
{
    double temp;

    if (index1 >= dim || index2 >= dim || index1 < 0 || index2 < 0)
    {
        throw new out_of_range("Index out of range");
    }

    temp = this->pointer[index1];
    this->pointer[index1] = this->pointer[index2];
    this->pointer[index2] = temp;
}
template<typename T>
Vettore<T>& Vettore<T>::operator=(const Vettore<T>& V) {
    if (this != &V) {
        if (pointer) {
            delete[] pointer;
        }
        dim = V.dim;
        pointer = new T[dim];
        for (int i = 0; i < dim; ++i) {
            pointer[i] = V.pointer[i];
        }
    }
    return *this;
}

template <typename T>
T &Vettore<T>::operator[](int index) const
{
    if (index >= this.dim || index < 0)
    {
        throw new out_of_range("Index out of range");
    }
    return this.pointer[index];
}

template<typename T>
Vettore<T>::Vettore(int ndata, const std::string filePath) {
    dim = ndata;
    pointer = new T[dim]; // Alloca memoria per ndata elementi

    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Impossibile aprire il file.");
    }

    for (int i = 0; i < dim; ++i) {
        if (!(file >> pointer[i])) {
            throw std::runtime_error("Errore di lettura dal file o dati insufficienti.");
        }
    }
    
    file.close();
}


#endif
