#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "Models/RandomGen.h"
#include "Models/IntegralMc.h"
#include "Models/FunzioneBase.h"
#include "Models/Integral.h"
#include "Models/Measure.h"
#include "Models/Vettore.h"
#include "Models/EquazioniDifferenziali.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
  // 1
  RungeKutta myRung;
  TCanvas canvas("canvas", "Grafici di traiettoria", 1000, 1000);
  canvas.Divide(3, 2);

  TGraph myGraph;

  // Parametri iniziali
  double alpha = 0.;
  double tmax = 20. * M_PI; // Tempo massimo per integrazione
  double h = .01;           // Passo di integrazione
  Prova3 sistema(alpha);

  double t = 0.0;
  arma::vec x{1., 0., 0., 1.}; // Condizioni iniziali: posizione e velocità
  int nstep = static_cast<int>(tmax / h + 0.5);

  for (int step = 0; step < nstep; step++)
  {
    myGraph.SetPoint(step, x[0], x[1]);
    x = myRung.Passo(t, x, h, sistema);
    t += h;
  }

  canvas.cd(1);
  myGraph.SetTitle("Traiettoria 1;X [m];Y [m]");
  // myGraph.GetXaxis()->SetTitle("Tempo [s]");
  // myGraph.GetYaxis()->SetTitle("Posizione [m]");
  myGraph.Draw("AL");
  // canvas.cd(1)->Modified();

  // Salvataggio dei grafici

  arma::vec x2 = x; // Condizioni iniziali: posizione e velocità
  double t2 = 0.0;
  double h2 = h * 0.5;
  int nstep2 = static_cast<int>(tmax / h2 + 0.5);

  for (int step = 0; step < nstep2; step++)
  {
    x2 = myRung.Passo(t2, x2, h2, sistema);
    t2 += h2;
  }

  double errore = 16. * abs(x[0] - x2[0]) / 15.;
  cout << "La stima dell'errore di integrazione al tempo " << tmax << "s : " << errore << endl;
  cout << "Posizione finale 1: " << x[0] << "\nPosizione finale 2: " << x2[0] << endl;

  double passo = pow(0.0001 * pow(h, 4) / errore, .25);
  cout << "Il valore del passo: " << passo << endl;

  // 2
  TGraph myGraph3;
  alpha = 2.;
  Prova3 sistema3(alpha);
  arma::vec x3{1.1, 0., 0., 1.}; // Condizioni iniziali: posizione e velocità
  tmax = 10 * M_PI;
  double t3 = 0.0;
  double h3 = passo;
  int nstep3 = static_cast<int>(tmax / h3 + 0.5);

  for (int step = 0; step < nstep3; step++)
  {
    myGraph3.SetPoint(step, x3[0], x3[1]);
    // cout << step<<" "<< x3[0]<<" "<< x3[1];
    x3 = myRung.Passo(t3, x3, h3, sistema3);
    t3 += h3;
  }

  canvas.cd(2);
  myGraph3.SetTitle("Alpha = 2; X[m]; Y[m]");
  // myGraph3.SetLineColor(200);
  myGraph3.Draw("AL");

  TGraph myGraph4;
  alpha = -2.;
  Prova3 sistema4(alpha);
  arma::vec x4{1.1, 0., 0., 1.}; // Condizioni iniziali: posizione e velocità
  double t4 = 0.0;
  double h4 = passo;
  int nstep4 = static_cast<int>(tmax / h4 + 0.5);

  for (int step = 0; step < nstep4; step++)
  {
    myGraph4.SetPoint(step, x4[0], x4[1]);
    x4 = myRung.Passo(t4, x4, h4, sistema4);
    t4 += h4;
  }
  canvas.cd(3);
  myGraph4.SetTitle("Alpha = -2; X[m]; Y[m]");
  // myGraph4.SetLineColor(200);
  myGraph4.Draw("AL");

//4
  TGraph myGraph5;
  alpha = -2.;
  Prova3 sistema5(alpha);
  arma::vec x5{1.1, 0., 0., 1.}; // Condizioni iniziali: posizione e velocità
  double t5 = 0.0;
  double h5 = passo;
  int nstep5 = static_cast<int>(tmax / h5 + 0.5);

  for (int step = 0; step < nstep5; step++)
  {
    myGraph5.SetPoint(step, t5, sqrt(x5[0]*x5[0]+x5[1]*x5[1]));
    x5 = myRung.Passo(t5, x5, h5, sistema5);
    t5 += h5;
  }
  canvas.cd(4);
  myGraph5.SetTitle("Alpha = 2, T[s]; R[m]");
  // myGraph5.SetLineColor();
  myGraph5.Draw("AL");

//6
  TGraph myGraph6;
  alpha = 2.;
  Prova32 sistema6(alpha);
  arma::vec x6{1.1, 0., 0., 1.}; // Condizioni iniziali: posizione e velocità
  double t6 = 0.0;
  double h6 = passo;
  int nstep6 = static_cast<int>(tmax / h6 + 0.6);

  for (int step = 0; step < nstep6; step++)
  {
    myGraph6.SetPoint(step, x6[0],x6[1]);
    x6 = myRung.Passo(t6, x6, h6, sistema6);
    t6 += h6;
  }
  canvas.cd(4);
  myGraph6.SetTitle("Alpha = 2, #beta ridefinito; T[s]; R[m]");
  // myGraph6.SetLineColor();
  myGraph6.Draw("AL");

  canvas.SaveAs("Plot.pdf");
  return 0;
}
