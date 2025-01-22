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
    cout << "Usage: " << argv[0] << " <precision>" << endl;
    return -1;
  }

  // unsigned int nstep = atoi(argv[1]);
  double prec = atof(argv[1]);
  Gaussiana gaus(0 , 1);
  Funzione f([&] (double x) {
  Measure result =  gaus.Probability(x,prec);
  return 2*result.GetValue();
  });
  
  double x = 2.20733   ;
  Measure test = gaus.Probability(x,prec);
  

  f.Plot("Gaus",0,5);

  return 0;
}
