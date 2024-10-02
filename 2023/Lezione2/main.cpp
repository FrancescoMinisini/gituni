#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
#include"Models/Vettore.h"

int main ( ) {

  // costruttore senza argomenti ==>> crea un vettore di dimenione nulla 

  Vettore vnull ;
  cout << "Vettore vnull : dimensione = " << vnull.Count() << endl;
  for ( unsigned int k = 0 ; k < vnull.Count() ; k++ ) cout << vnull.GetValue(k) << " " ;
  cout << endl;

  // construttore con intero : costruisco un OGGETTO di tipo vettore di lunghezza 10

  Vettore v(10);
  cout << "Vettore v : = dimensione = " << v.Count() << endl;
  for ( unsigned int k = 0 ; k < v.Count() ; k++ ) cout << v.GetValue(k) << " " ;
  cout << endl;
  int comp = 3;
  cout << "Componente " << comp << " = " << v.GetValue(comp) << endl;

  v.SetComponent(comp,-999) ;

  for ( unsigned int k = 0 ; k < v.Count() ; k++ ) cout << v.GetValue(k) << " " ;
  cout << endl;

  // anche come puntatore

  Vettore * vp = new Vettore(10);
  cout << "Vettore vp : = dimensione = " << vp->Count() << endl;
  for ( unsigned int k = 0 ; k < vp->Count() ; k++ ) cout << vp->GetValue(k) << " " ;
  cout << endl;    

  delete vp;

  return 0;

}