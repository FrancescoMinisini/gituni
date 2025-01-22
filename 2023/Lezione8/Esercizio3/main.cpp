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

std::string convert(double h);

int main(int argc, char **argv)
{

  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <stepsize>" << std::endl;
    return -1;
  }


  RungeKutta myRK4;


  double tmax = 70.;
  double h = atof(argv[1]);
  double t = 0.;
  TGraph myGraph;
  int nstep = int(tmax / h + 0.5);
  Pendolo osc(1.);


  for (int i = 0; i < 30; i++)
  {
    double A = 0.1 * (i + 1);
    double v = 0.;
    double t = 0.;
    arma::vec x{-A, v};
    while (x[1] >= 0.)
    {
      v = x[1];
      x = myRK4.Passo(t, x, h, osc);
      t = t + h;
      std::cout << A << " " << x[0] << " " << t << std::endl;
    }
    t = t-h - v * h / (x[1] - v) ;
    //t = t - v * h/ (x[1] - v);
    double period = 2. * t;
    myGraph.SetPoint(i, A, period);
  }

  // grafici

  TCanvas c;
  c.cd();
  string title = "Oscillatore armonico (Eulero h = " + convert(h) + ")";
  myGraph.SetTitle(title.c_str());
  myGraph.GetXaxis()->SetTitle("Ampiezza [rad]");
  myGraph.GetYaxis()->SetTitle("Periodo [s]");
  myGraph.SetMarkerStyle(20);
  myGraph.Draw("ALP");
  c.SaveAs("../Periodo.pdf");

}

std::string convert(double h)
{

  int cifre_significative = -log10(h);
  std::ostringstream streamObj3;
  streamObj3 << std::fixed;
  streamObj3 << std::setprecision(cifre_significative);
  streamObj3 << h;
  std::string strObj3 = streamObj3.str();
  return strObj3;
};
