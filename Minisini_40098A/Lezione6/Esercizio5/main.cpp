#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Models/FunzioneBase.h"
#include "Models/Solutore.h"
#include "Models/Bisezione.h"
#include "Models/Measure.h"
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
  FunzioneBase *par1 = new UnsolvableFunc();
  par1->Plot("Plotting", 0,70,1e5);
  double xmin,xmax;
  int count = 0;
  for (int i = 0; i < 20; i++)
  {
    try{
    xmin = i*M_PI;
    xmax = (i + .5)*M_PI;
    Bisezione b(1e-7);
    Measure result = b.CercaZeri(xmin,xmax,par1);
    count++;
    cout << left << setw(20) <<"Zero number: "<< count << endl;
    result.Print();
    } catch (exception e){}
  }
  
  return 0;
}
