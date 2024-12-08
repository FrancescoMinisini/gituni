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

  TApplication myApp("myApp",0,0);

  RungeKutta myRung;

  OscillatoreArmonico osc(1.);

  double tmax = 70.;
  double h = atof(argv[1]);
  arma::vec x {0.,1.} ;
  double t = 0.; 

  TGraph myGraph ;
  int nstep = int(tmax/h+0.5);

  // evoluzione del sistema fino a 70 s  

  for (int step=0; step<nstep; step++) {
    myGraph.SetPoint(step,t,x[0]);
    x = myRung.Passo(t,x,h,osc);
    t = t+h;
  }

  // grafici  

  TCanvas c ;
  c.cd();
  string title = "Oscillatore armonico (Eulero h = " + convert(h) + ")" ;
  myGraph.SetTitle(title.c_str());
  myGraph.GetXaxis()->SetTitle("Tempo [s]");
  myGraph.GetYaxis()->SetTitle("Posizione x [m]");
  myGraph.Draw("AL");

  myApp.Run();
}

std::string convert ( double h ) {

  int cifre_significative = -log10(h);
  std::ostringstream streamObj3;
  streamObj3 << std::fixed;
  streamObj3 << std::setprecision(cifre_significative);
  streamObj3 << h;
  std::string strObj3 = streamObj3.str();
  return strObj3;

} ;
