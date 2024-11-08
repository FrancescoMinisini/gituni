#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Models/FunzioneBase.h"
#include "Models/Solutore.h"
#include "Models/Bisezione.h"
#include "Models/Measure.h"
#include <cstdlib>
#include <string>

using namespace std;

int main ( int argc, char** argv ) {

  double xmin = atol(argv[1]), xmax = atol(argv[2]);
  if ( argc < 3 || xmin > xmax ) {
    cout << "Uso del programma : " << argv[0] << " <x_minimo> <x_massimo> " << endl;
    return -1 ;
  } else if ( xmin > xmax ) {
    cout << "<x_minimo> deve essere minore di <x_massimo>" << endl;
    return -1 ;
  }
  FunzioneBase *par1 = new Parabola(3, 5, -2);
  par1->Plot("Plotting");
  Bisezione b(1e-8);
  Measure result = b.CercaZeri(xmin,xmax,par1);
  result.Print();
  return 0;
}
