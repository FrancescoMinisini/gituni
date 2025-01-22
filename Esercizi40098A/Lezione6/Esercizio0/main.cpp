#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Models/Posizione.h"
#include <cstdlib>
#include "Models/Particella.h"
#include "Models/Elettrone.h"
#include "Models/CampoVettoriale.h"
#include "Models/PuntoMateriale.h"

using namespace std;

int main() {

  Particella *p = new Particella(1.,2.);
  Elettrone  *e = new Elettrone();
  Particella *b = new Elettrone(); // Puntatore a Particella che punta ad un oggetto Elettrone

  p->Print(); // Metodo Print di Particella
  e->Print(); // Metodo Print di Elettrone
  b->Print(); // Quale Print ???

  delete p;
  delete e;
  delete b;

  return 0;

}
