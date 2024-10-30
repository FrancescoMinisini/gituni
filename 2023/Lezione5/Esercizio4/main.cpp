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
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " <n> (number of datapoints)" << endl;
    exit(-1);
  }
  double maxValore = 2000;
  const double e = 1.60217653E-19;
  const double me = 9.1093826E-31;
  const double mp = 1.6726219E-27;
  const double d = 1.E-10;

  int n = atoi(argv[1]);
  double step = 900 * d / n;

  PuntoMateriale elettrone(me, -e, 0., 0., d / 2.);
  PuntoMateriale protone(mp, e, 0., 0., -d / 2.);

  vector<CampoVettoriale> dati(n);
  vector<Posizione> posizioni(n);

  TApplication app(0, 0, 0);
  TGraph g;

  Posizione tmp(0, 0, 0);

  for (int i = 0; i < n; i++)
  {
    tmp.SetZ(100 * d + i * step);
    posizioni[i] = tmp;
    dati[i] = elettrone.CampoElettrico(tmp) + protone.CampoElettrico(tmp);
    g.SetPoint(i, posizioni[i].GetZ(), dati[i].GetMagnitude());
  }

  TCanvas can2;
  can2.cd();
  can2.SetLogy(); 
  g.Draw("ALP");
  g.SetMarkerStyle(21); 
  g.SetMarkerSize(0.8); 
  g.SetLineWidth(2);    
  g.SetLineColor(kBlue);
  g.SetMarkerColor(kRed);
  g.SetTitle("Best charge value (Logarithmic Scale)");
  g.GetXaxis()->SetTitle("Position (m)");
  g.GetYaxis()->SetTitle("Electric Field (N/C)");
  
  g.GetXaxis()->CenterTitle(); 
  g.GetYaxis()->CenterTitle(); 
  
  can2.SetGrid(); 
  
  app.Run();

  return 0;
}
