#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
#include"Models/Vettore.h"


int main ( int argc, char** argv ) {

  if ( argc < 3 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }

  int ndata = atoi(argv[1]);
  char * filename = argv[2];

  // usiamo il contenitore Vettore per immagazzinare double !

  Vettore <double> v = Vettore<double>( ndata , filename );

  v.Print();

  cout << "media    = " << v.GetAverage() << endl;
  cout << "varianza = " << v.GetVarianza() << endl;
  cout << "mediana  = " << v.GetMediana() << endl; 


  // v.~Vettore();
  return 0;

}


