#include <iostream>
#include <cstdlib>
#include "/snap/root-framework/936/usr/local/include/TH1F.h"
#include "/snap/root-framework/936/usr/local/include/TApplication.h"
#include "/snap/root-framework/936/usr/local/include/TCanvas.h"
#include "Models/Vettore.h"

#include <vector>
using namespace std;

int main( int argc , char** argv ) {

  if ( argc < 3 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }  

  TApplication app("app",0,0);

  string filename(argv[1]);
  vector<double> v = Read<double>( atoi(argv[2]) ,  filename);

  TH1F histo ("histo","histo", 200, -30, 30) ;
  histo.StatOverflows( kTRUE );
  for ( int k = 0 ; k < v.size() ; k++ ) histo.Fill( v[k] );

  cout << "Media dei valori caricati = " << histo.GetMean() << endl;

  TCanvas mycanvas("Histo", "Histo");

  histo.Draw();
  histo.GetXaxis()->SetTitle("measurement");

  app.Run();

}
