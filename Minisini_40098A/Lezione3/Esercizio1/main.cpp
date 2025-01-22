#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
#include"Models/Vettore.h"
#include <cstdlib>
#include <vector>


using namespace std;

int main( int argc , char** argv ) {

  if ( argc < 3 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }  

  vector<double> v = Read<double>( atoi(argv[1]) , argv[2] );

  Print(v) ;
  cout << "media    = " << CalcolaMedia<double>( v ) << endl;
  cout << "varianza = " << CalcolaVarianza<double>( v ) << endl;
  cout << "mediana  = " << CalcolaMediana<double>( v ) << endl;

  return 0;

}



