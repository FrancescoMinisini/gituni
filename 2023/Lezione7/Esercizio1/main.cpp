#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Models/FunzioneBase.h"
#include "Models/Solutore.h"
#include "Models/Bisezione.h"
#include "Models/Measure.h"
#include "Models/Integral.h"
#include <cstdlib>
#include <string>
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TApplication.h"

using namespace std;

int main (int argc, char** argv) {
 
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <nstep>" << endl;
    return -1;
  }

  unsigned int nstep = atoi(argv[1]);

  // Dichiara l'oggetto funzione e l'intervallo di integrazione
  Funzione f([] (double x) {return sin(x)*x;});
  double a = 0, b = M_PI / 2;
  Simpson myInt(a, b);

  // TApplication app("app", &argc, argv);
  TCanvas canvas("canvas", "Errore di Integrazione", 800, 600);
  TGraph g_errore;

  double  h = 0;
  unsigned int n_points = 10;
  for (unsigned int k = 0; k < n_points; k++) {
    h = (b - a) / nstep; 
    Measure I = myInt.Integra(nstep, f);
    I.Print();
    g_errore.SetPoint(k, h, I.GetSigma());
    nstep *= 2;
  }

  // Configura il grafico per l'errore
  g_errore.SetTitle("Errore di Integrazione; Passo h; Errore Assoluto");
  g_errore.SetLineColor(kBlue);
  g_errore.SetLineWidth(2);
  g_errore.SetMarkerStyle(21);
  g_errore.SetMarkerSize(0.8);
  g_errore.SetMarkerColor(kRed);

  // Disegna il grafico e salva l'immagine
  canvas.cd();
  g_errore.Draw("ALP");
  canvas.SaveAs("../Plot.pdf");

  // Avvia l'applicazione ROOT
  // app.Run();

  return 0;
}
