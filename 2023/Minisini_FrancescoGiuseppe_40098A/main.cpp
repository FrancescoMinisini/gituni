#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TF1.h"
#include "Models/RandomGen.h"
#include "Models/IntegralMc.h"
#include "Models/FunzioneBase.h"
#include "Models/Integral.h"
#include "Models/Measure.h"
#include "Models/Vettore.h"
#include "Models/EquazioniDifferenziali.h"
#include "Models/Bisezione.h"
#include "Models/EsperimentoCondensatore.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int main(int argc, char **argv)
{
  // 1
  cout << endl
       << endl
       << "----------------------------  1  ----------------------------" << endl;
  double precision = .001;

  arma::vec inf{1, 4, 7};
  arma::vec sup{2, 5, 8};

  Funzione f([](double x)
             { return (1 + 2 * x * cos(x)) / (1 + sqrt(x)); });
  Bisezione bisezione(precision);

  vector<Measure> zeri = bisezione.CercaZeriMultipli(inf, sup, f);
  int count = 0;
  for (auto measure : zeri)
  {
    count++;
    cout << "Zero numero  " << count << endl;
    measure.Print();
  }



  // 2,3
  cout << endl
       << endl
       << "----------------------------  2,3  ----------------------------" << endl;
  double a = zeri[0].GetValue();
  double b = zeri[1].GetValue();
  unsigned int nstep = 4;
  Simpson myInt(a, b);
  Measure integrale = myInt.IntegraConErroreRunTime(nstep, f);
  cout << "Valore dell'integrale con la stima dell'errore runtime" << endl;
  integrale.Print();

  



  // 4
  cout << endl
       << endl
       << "----------------------------  4  ----------------------------" << endl;
  unsigned int niterations = 10000;
  double sigma = precision * 0.5;
  double epsilon2 = StimaErroreIndottoSimpson(1, a, b, niterations, nstep, sigma, f);
  cout << scientific << "Stima dell'errore epsilon 2 indotto dall'incertezza sugli zeri 1,2 di: " << epsilon2 << endl;



  // 5
  cout << endl
       << endl
       << "----------------------------  5  ----------------------------" << endl;
  double passo = myInt.GetPassoRunTime(epsilon2, f, (b-a)/nstep);
  unsigned int n_intervals = (int)((b - a) / passo);
  cout << "Numero di intervalli necessari per una stima con precisione epsilon 2: " << n_intervals << endl;
  cout <<endl<< "Integrale calcolato con il questo numero di intervalli: " << n_intervals << endl;
  Measure test =   myInt.IntegraConErroreRunTime(n_intervals,f);
  test.Print();

  // 6
  cout << endl
       << endl
       << "----------------------------  6  ----------------------------" << endl;
  Funzione F([&](double t)
             {
    Simpson myInt2(a,t);
    Measure result = myInt2.Integra(4,f);
    return result.GetValue(); });

  F.Plot("Plot of F(t);t;F(t)", a, zeri[2].GetValue());

// Trapezi Trapezi(a,b);
// Measure t = Trapezi.Integra(0.0001, f);
// t.Print();

  return 0;
}
