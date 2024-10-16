#include <iostream>
#include <cstdlib>
#include "/snap/root-framework/936/usr/local/include/TH1F.h"
#include "/snap/root-framework/936/usr/local/include/TApplication.h"
#include "/snap/root-framework/936/usr/local/include/TCanvas.h"
#include "/snap/root-framework/936/usr/local/include/TGraphErrors.h"
#include "Models/Vettore.h"
#include <string>
#include <vector>
using namespace std;

int main(  ) {

  TApplication app("app",0,0);

  TGraphErrors trend;

  int index {0} ;

  for ( int i = 1940 ; i < 2024 ; i++) {

    string filename = "../dati/" +  to_string(i) + ".txt" ;
    
    vector<double> v = Read<double> ( filename ) ;
    cout<< i<<endl;
    double ave = CalcolaMedia(v);
    double err = CalcolaErrore(v);

    cout << "  Anno " << to_string(i) << "  delta medio = " << ave << " +/- " << err <<  endl;

    // inserisco media e deviazione standard dalla media nel grafico 

    trend.SetPoint(index, i, ave);
    trend.SetPointError( index , 0 , err);

    index++;

  }

  // grafica                                                                          

  TCanvas c("Temperature trend","Temperature trend");
  c.cd();
  c.SetGridx();
  c.SetGridy();

  trend.SetMarkerSize(1.0);
  trend.SetMarkerStyle(20);
  trend.SetFillColor(5);

  trend.SetTitle("Temperature trend");
  trend.GetXaxis()->SetTitle("Anno");
  trend.GetYaxis()->SetTitle("#Delta (#circ C)");
  trend.Draw("apl");
  trend.Draw("p");

  c.SaveAs("trend.pdf");

  app.Run();

}