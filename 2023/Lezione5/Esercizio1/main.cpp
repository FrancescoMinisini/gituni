#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Models/Posizione.h"
#include <cstdlib>
#include "Models/Particella.h"
#include "Models/Elettrone.h"

int main() {

  Particella a (1.,1.6E-19);
  Elettrone *e = new Elettrone();

//   cout << "Particella " << a.GetMassa() << "," << a.GetCarica() << endl;
  a.Print(); 

//   cout << "Elettrone " << e->GetMassa() << "," << e->GetCarica() << endl;
  e->Print(); 

  Particella b(a) ;  
  Particella d(*e) ; 

  return 0;

}