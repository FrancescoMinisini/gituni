#ifndef PARTICELLA_H
#define PARTICELLA_H

using namespace std;
#include<iostream>

class Particella {
public:
  Particella(){m_carica = 0; m_massa = 0;} ;
  Particella(double massa, double carica){m_massa = massa ; m_carica = carica;}
  ~Particella(){};

  double GetMassa() const  {return m_massa;}
  double GetCarica() const {return m_carica;}
  virtual void Print() const {
  cout << "Particella: m=" << m_massa 
       << ", q=" << m_carica
       << endl; 
}

  protected:
  double m_massa;
  double m_carica;

};
#endif