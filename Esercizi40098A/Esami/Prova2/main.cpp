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

  TCanvas canvas("canvas", "Grafici Oscillatore Smorzato", 1000, 1000);
  TGraph myGraph;

  // 1
  RungeKutta myRung;

  // Parametri iniziali
  double omega0 = 1.15; // Pulsazione naturale
  double alpha = 0.01;  // Coefficiente di smorzamento
  double tmax = 43.0;   // Tempo massimo per integrazione
  double h = .1;        // Passo di integrazione

  // Oscillatore forzato con pulsazione omega0
  OscillatoreSmorzato osc(omega0, alpha);
  arma::vec x{1.0, 0.0}; // Condizioni iniziali: posizione e velocità
  double t = 0.0;

  // Primo grafico: Oscillazioni in funzione del tempo
  int nstep = static_cast<int>(tmax / h + 0.5);

  for (int step = 0; step < nstep; step++)
  {
    myGraph.SetPoint(step, t, x[0]);
    x = myRung.Passo(t, x, h, osc);
    t += h;
  }

  // canvas.cd(1);
  canvas.cd();
  myGraph.SetTitle("Oscillazioni Forzate;Tempo [s];Posizione [m]");
  myGraph.GetXaxis()->SetTitle("Tempo [s]");
  myGraph.GetYaxis()->SetTitle("Posizione [m]");
  myGraph.Draw("AL");
  canvas.cd(1)->Modified();

  // Salvataggio dei grafici
  canvas.SaveAs("Plot.pdf");

  // 2
  arma::vec x2{1.0, 0.0}; // Condizioni iniziali: posizione e velocità
  double t2 = 0.0;
  double h2 = h * 0.5;
  int nstep2 = nstep*2;

  for (int step = 0; step < nstep2; step++)
  {
    x2 = myRung.Passo(t2, x2, h2, osc);
    t2 += h2;
  }

  double errore = 16. * abs(x[0] - x2[0]) / 15.;
  cout << "La stima dell'errore di integrazione al tempo " << tmax << "s : " << errore << endl;
  cout << "Posizione finale 1: " << x[0] << "\nPosizione finale 2: " << x2[0] << endl;

  // 3
  double passo = pow(0.00005 * pow(h, 4) / errore, .25);
  cout << "Il valore del passo: " << passo << endl;

  // 4
  vector<double> results;
  double h3 = passo;
  RandomGen gen(1);
  double sig = 0.003;

  for (int i = 0; i < 10000; i++)
  {
    arma::vec x3{1.0, gen.Gaus(0., sig)}; // Condizioni iniziali: posizione e velocità
    double t3 = 0.0;
    int nstep3 = static_cast<int>(tmax / h3 + 0.5);

    for (int step = 0; step < nstep3; step++)
    {
      x3 = myRung.Passo(t3, x3, h3, osc);
      t3 += h3;
    }
    results.push_back(x3[0]);
  }

  double devFinale = sqrt(CalcolaVarianza<double>(results));
  cout << "Deviazione standard di 10000 integrazioni: " << devFinale << endl;

  // 5
  vector<double> sigmas{0.003, 0.005, 0.008, .012, .015};
  TCanvas canvas2("canvas", "Histogrammi degli errori di integrazione", 1000, 1000);
  canvas2.Divide(3, 2);
  vector<TH1F *> histograms;
  int count = 0;


  for (auto sigma : sigmas)
  {
    count++;
    TH1F *hist = new TH1F(Form("Integrazione_%d", count), Form("Distribuzione per sigma = sigmas[%d]; N; Value", count), 100, x[0]-6*sigma, x[0]+6*sigma);
    hist->SetLineColor(kBlue);
    hist->SetLineWidth(2);
    hist->SetFillColor(kCyan);
    hist->SetFillStyle(3004);

  RandomGen gen;

  for (int i = 0; i < 10000; i++)
  {
    double h4 = passo;
    arma::vec x4{1.0, gen.Gaus(0., sigma)}; // Condizioni iniziali: posizione e velocità
    double t4 = 0.0;
    int nstep4 = static_cast<int>(tmax / h4 + 0.5);

    for (int step = 0; step < nstep4; step++)
    {
      x4 = myRung.Passo(t4, x4, h4, osc);
      t4 += h4;
    }
    hist->Fill(x4[0]);
  }
    histograms.push_back(hist);
  }
  vector<double> deviazioni;
  count = 0;
  for (auto hist : histograms)
  {
    deviazioni.push_back(hist-> GetStdDev());
    canvas2.cd(++count);
    hist->Draw();
  }

    TGraph stdGraph(deviazioni.size());
  
    for (int i = 0; i < deviazioni.size(); ++i)
    {
        stdGraph.SetPoint(i, sigmas[i], deviazioni[i]);
    }

    canvas2.cd(count++);
    stdGraph.SetTitle("Teorema del limite centrale; Sigma velocità; Deviazione");
    stdGraph.GetXaxis()->SetTitle("Sigma velocità");
    stdGraph.GetYaxis()->SetTitle("Deviazione");
    stdGraph.SetMarkerStyle(20);
    stdGraph.SetLineColor(30);
    stdGraph.Draw("ALP");

  canvas2.SaveAs("Histograms.pdf");

  return 0;
}
