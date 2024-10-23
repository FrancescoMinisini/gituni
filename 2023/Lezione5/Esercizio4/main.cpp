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

#include "TH1F.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TAxis.h"

using namespace std;

int main(int argc, char **argv)
{

  if (argc != 4)
  {
    cerr << "Usage: " << argv[0] << " <n> (number of datapoints)" << endl;
    exit(-1);
  }

  const double e = 1.60217653E-19;
  const double me = 9.1093826E-31;
  const double mp = 1.6726219E-27;
  const double d = 1.E-10;

  int n = atoi(argv[1]);
  double step = 50 * d / n;

  PuntoMateriale elettrone(me, -e, 0., 0., d / 2.);
  PuntoMateriale protone(mp, e, 0., 0., -d / 2.);

  vector<CampoVettoriale> dati;
  vector<Posizione> posizioni;

  TApplication app(0, 0, 0);
  TGraph g;

Posizione tmp(0, 0, 0);

  for (int i = 0; i <= n; i++)
  {
    posizioni[i] = tmp.SetZ(-50 * d + i * step);
    dati[i] = elettrone.CampoElettrico(tmp) + protone.CampoElettrico(tmp);
    g.SetPoint(i, posizioni[i], dati[i]);
  }

  TCanvas can2;
  can2.cd();
  g.Draw("ALP");
  g.SetMarkerStyle(20);
  g.SetMarkerSize(0.5);
  g.SetTitle("Best charge value");
  g.GetXaxis()->SetTitle("Charge (C)");
  g.GetYaxis()->SetTitle("S(q) (C^{2})");
  app.Run();

  return 0;
}
