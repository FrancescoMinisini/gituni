#ifndef ELETTRONE_H
#define ELETTRONE_H

#include"Particella.h"
#include<iostream>
using namespace std;

class Elettrone: public Particella {
    public: 
    Elettrone(): Particella(9.1093826E-31,-1.60217653E-19){};
    ~Elettrone(){};
    void Print() const {
         cout << "Elettrone: m=" << m_massa 
       << ", q=" << m_carica
       << endl;
    }

};

#endif