#include "Models/EquazioniDifferenziali.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

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

  TApplication myApp("myApp", 0, 0);

  RungeKutta myRung;

  // Parametri iniziali
  double omega0 = 10.0;      // Pulsazione naturale
  double alpha = 1.0 / 30.0; // Coefficiente di smorzamento
  double tmax = 300.0;       // Tempo massimo per integrazione
  double h = atof(argv[1]);  // Passo di integrazione

  // Oscillatore forzato con pulsazione omega0
  OscillatoreForzatoSmorzato osc(omega0, omega0, alpha);
  arma::vec x{0.0, 0.0}; // Condizioni iniziali: posizione e velocità
  double t = 0.0;

  // Primo grafico: Oscillazioni in funzione del tempo
  TGraph myGraph;
  int nstep = static_cast<int>(tmax / h + 0.5);

  for (int step = 0; step < nstep; step++)
  {
    myGraph.SetPoint(step, t, x[0]);
    x = myRung.Passo(t, x, h, osc);
    t += h;
  }

  // Secondo grafico: Curva di risonanza
  TGraph resonanceGraph;
  double omega_min = 9.0;
  double omega_max = 11.0;
  double omega_step = 0.01;
  int i = 0;

  for (double omega = omega_min; omega <= omega_max; omega += omega_step)
  {
    OscillatoreForzatoSmorzato oscTemp(omega0, omega, alpha);

    // Riporta il sistema alle condizioni iniziali
    x = {0.0, 0.0};
    t = 0.0;

    // Evolve il sistema per esaurire il transiente
    for (int step = 0; step < nstep; step++)
    {
      x = myRung.Passo(t, x, h, oscTemp);
      t += h;
    }

    // Calcola l'ampiezza massima delle oscillazioni stazionarie
    double amplitude = 0.0;
    for (int step = 0; step < nstep; step++)
    {
      x = myRung.Passo(t, x, h, oscTemp);
      amplitude = std::max(amplitude, std::abs(x[0]));
      t += h;
    }

    resonanceGraph.SetPoint(i, omega, amplitude);
    i++;
  }

  // Terzo grafico: Oscillazioni in funzione del tempo con focus transiente
  TGraph transientGraph;
  t = 0.0;
  x = {0.0, 0.0};
  int transientSteps = static_cast<int>(25.0 / h + 0.5); // 25 secondi
  for (int step = 0; step < transientSteps; step++)
  {
    transientGraph.SetPoint(step, t, x[0]);
    x = myRung.Passo(t, x, h, osc);
    t += h;
  }

  // Creazione del canvas con matrice 3x1
  TCanvas canvas("canvas", "Grafici Oscillatore Forzato Smorzato", 1200, 1800);
  canvas.Divide(1, 3);

  // Primo sottografico
  canvas.cd(1);
  myGraph.SetTitle("Oscillazioni Forzate;Tempo [s];Posizione [m]");
  myGraph.GetXaxis()->SetTitle("Tempo [s]");
  myGraph.GetYaxis()->SetTitle("Posizione [m]");
  myGraph.Draw("AL");
  canvas.cd(1)->Modified();

  // Secondo sottografico
  canvas.cd(2);
  resonanceGraph.SetTitle("Curva di Risonanza");
  resonanceGraph.GetXaxis()->SetTitle("Pulsazione [rad/s]");
  resonanceGraph.GetYaxis()->SetTitle("Ampiezza [m]");
  resonanceGraph.SetMarkerStyle(20);
  resonanceGraph.SetMarkerSize(0.8);
  resonanceGraph.Draw("ALP");
  canvas.cd(2)->Modified();

  // Terzo sottografico
  canvas.cd(3);
  transientGraph.SetTitle("Oscillazioni Transiente;Tempo [s];Posizione [m]");
  transientGraph.GetXaxis()->SetTitle("Tempo [s]");
  transientGraph.GetYaxis()->SetTitle("Posizione [m]");
  transientGraph.Draw("AL");
  canvas.cd(3)->Modified();

  // Salvataggio dei grafici
  canvas.SaveAs("../grafici_oscillatore.pdf");

  // Avvia applicazione ROOT
  myApp.Run();

  return 0;
}

std::string convert(double h)
{
  int cifre_significative = -log10(h);
  std::ostringstream streamObj;
  streamObj << std::fixed;
  streamObj << std::setprecision(cifre_significative);
  streamObj << h;
  return streamObj.str();
}
