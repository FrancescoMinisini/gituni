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
  Funzione f([] (double x) {return sin(x)*x;});
  double a = 0, b = M_PI / 2;
  Trapezi myInt(a, b, 10000000);
  
  auto result = myInt.Integra(prec,f);
  result.Print();



  return 0;
}
