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

#include "Models/CampoVettoriale.h"
#include "Models/PuntoMateriale.h"

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

  if ( argc!= 4) {
    cerr << "Usage: " << argv[0] << " <x> <y> <z>" << endl;
    exit(-1); 
  }

  const double e =1.60217653E-19 ;
  const double me=9.1093826E-31;
  const double mp=1.6726219E-27;  
  const double d =1.E-10;

  Posizione p( atof(argv[1]) , atof(argv[2]), atof(argv[3]) );

  PuntoMateriale elettrone(me, -e,0.,0.,d/2.);
  PuntoMateriale protone(mp, e,0.,0.,-d/2.);

  CampoVettoriale E = elettrone.CampoElettrico( p ) + protone.CampoElettrico( p ) ;

  cout << "E=(" << E.GetFx() << "," << E.GetFy() << "," << E.GetFz() << ")" << endl;
  return 0;  
}
