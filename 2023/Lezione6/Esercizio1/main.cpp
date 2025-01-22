#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Models/FunzioneBase.h"
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
  FunzioneBase *par1 = new Parabola(1, 2, 3);
  par1->Plot("Plotting");
  return 0;
}
