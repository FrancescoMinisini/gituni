#include "Models/EquazioniDifferenziali.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TGraph.h"
#include <armadillo>
using namespace std;

std::string convert ( double h ) ;

int main (int argc, char** argv ) {

  if ( argc!=2 ) {
    std::cerr << "Usage: " << argv[0] << " <stepsize>" << std::endl;
    return -1;
  }  

  RungeKutta myRung;
  OscillatoreArmonico osc(1.);

  double tmax = 70.;
  double h = atof(argv[1]);
  arma::vec x {0.,1.} ;
  double t = 0.;

auto graph = myRung.Plot("Posizione; X[m];Y[m]", 0,t,tmax,x, h,osc);

// cout<< myRung.Errore(0,t,tmax,x, h,osc)<< endl;

myRung.PlotErrore("Errore; h ;#sigma_{x}", 10 , 0 , t,tmax,x, h,osc);

}

