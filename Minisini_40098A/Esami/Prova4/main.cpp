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
#include "Models/Bisezione.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
  //1
  double a = -.00005;
  double b = - a;
  double d = .0001;
  double lambda = 500E-9;
  double l = 1.;
  unsigned int it =  1000;
  Prova4 f (a, b, d, lambda, l, it);
  f.Plot("Plot della funzione A(x)", -0.1, 0.1,10000);

//2
  bool found = false;
  double h = .01, x = 0, precision = 1e-6;
  Measure result(0,0);
  while (!found && x <= 0.1)
  {
    try
    {
    Bisezione bisezione(x, x+h, precision);
    x += h;
    result = bisezione.CercaZeri(f);
    found = true;
    }
    catch(const std::exception& e){
        // std::cerr << e.what() << '\n';
    }
  }
  
  cout << "Il primo zero della funzione con lambda: "<< lambda << "m"<< endl;
  result.Print();

//3
  double a2 = -.00005;
  double b2 = - a;
  double d2 = .0001;
  double lambda2 = 400E-9;
  double l2 = 1.;
  unsigned int it2 =  1000;
  Prova4 f2 (a2, b2, d2, lambda2, l2, it2);
  found = false;
  h = .01, x = 0, precision = 1e-6;
  Measure result2(0,0);
  while (!found && x <= 0.1)
  {
    try
    {
    Bisezione bisezione(x, x+h, precision);
    x += h;
    result2 = bisezione.CercaZeri(f2);
    found = true;
    }
    catch(const std::exception& e){
        // std::cerr << e.what() << '\n';
    }
  }
  
  cout << "Il primo zero della funzione con lambda: "<< lambda2 << "m"<< endl;
  result2.Print();

  double a3 = -.00005;
  double b3 = - a;
  double d3 = .0001;
  double lambda3 = 450E-9;
  double l3 = 1.;
  unsigned int it3 =  1000;
  Prova4 f3 (a3, b3, d3, lambda3, l3, it3);
  found = false;
  h = .01, x = 0, precision = 1e-6;
  Measure result3(0,0);
  while (!found && x <= 0.1)
  {
    try
    {
    Bisezione bisezione(x, x+h, precision);
    x += h;
    result3 = bisezione.CercaZeri(f3);
    found = true;
    }
    catch(const std::exception& e){
        // std::cerr << e.what() << '\n';
    }
  }
  
  cout << "Il primo zero della funzione con lambda: "<< lambda3 << "m"<< endl;
  result3.Print();


  return 0;
}
