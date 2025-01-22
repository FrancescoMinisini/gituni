#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "Models/RandomGen.h"
#include "Models/IntegralMc.h"
#include "Models/FunzioneBase.h"
#include "Models/Integral.h"
#include "Models/Measure.h"
#include "Models/Vettore.h"


#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;



int main (int argc, char** argv) {

  unsigned int nstep = 2;
  unsigned int n_points = 10;

  // Dichiara l'oggetto funzione e l'intervallo di integrazione
  Funzione f([] (double x) {return x*x*x*log(sqrt(M_E+x*x));});
  double a = 0, b = sqrt(M_E);
  Midpoint myInt(a, b);
  double Iv = 3*M_E*M_E/(double)16, x1,x2,y1,y2;
  // Measure I(0,0);
  double err = 0, h = 0;


  // Dichiara oggetti per la grafica ROOT
  TCanvas canvas("canvas", "Errore di Integrazione", 800, 600);
  canvas.Divide(2,1);
  TGraph g_errore;

  

  for (unsigned int k = 0; k < n_points; k++) {
    h = (b - a) / (double)nstep; 
    Measure I = myInt.Integra(nstep, f);
    err = fabs(I.GetValue() - Iv);
    //cout << "Passi: "  << nstep << " Errore: " << err << endl;
    g_errore.SetPoint(k, h, err);
    nstep *= 2;
    if(k == 1){
      x1 = h;
      y1 = err;
    } else if (k == 9) {
      x2 = h;
      y2 = err;
    }
  }

  // Configura il grafico per l'errore
  g_errore.SetTitle("Errore di Integrazione Midpoint; Passo h; Errore Assoluto");
  g_errore.SetLineColor(kBlue);
  g_errore.SetLineWidth(2);
  g_errore.SetMarkerStyle(21);
  g_errore.SetMarkerSize(0.8);
  g_errore.SetMarkerColor(kRed);

  // Disegna il grafico e salva l'immagine
  canvas.cd(1);
  g_errore.Draw("ALP");


//2
  double k2 = log(y2/y1)/log(x2/x1);
  cout << "Midpoint k2: "<< k2 << endl;
  double k1 = y1/pow(x1 , k2);
  cout << "Midpoint k1: "<< k1 << endl;


//3
  nstep = 2;
  Midright myInt2(a, b);
  // Measure I2(0,0);
  x1=0; x2=0; y1=0; y2=0; err = 0, h = 0;


  // Dichiara oggetti per la grafica ROOT
  TGraph g_errore2;

  

  for (unsigned int k = 0; k < n_points; k++) {
    h = (b - a) / (double)nstep; 
    Measure I2 = myInt2.Integra(nstep, f);
    err = fabs(I2.GetValue() - Iv);
    //cout << "Passi: "  << nstep << " Errore: " << err << endl;
    g_errore2.SetPoint(k, h, err);
    nstep *= 2;
    if(k == 1){
      x1 = h;
      y1 = err;
    } else if (k == 9) {
      x2 = h;
      y2 = err;
    }
  }

  // Configura il grafico per l'errore
  g_errore2.SetTitle("Errore di Integrazione Midright; Passo h; Errore Assoluto");
  g_errore2.SetLineColor(kBlue);
  g_errore2.SetLineWidth(2);
  g_errore2.SetMarkerStyle(21);
  g_errore2.SetMarkerSize(0.8);
  g_errore2.SetMarkerColor(kRed);

  // Disegna il grafico e salva l'immagine
  canvas.cd(2);
  g_errore2.Draw("ALP");


//4
  k2 = log(y2/y1)/log(x2/x1);
  cout << "Midright k2: "<< k2 << endl;
  k1 = y1/pow(x1 , k2);
  cout << "Midright k1: "<< k1 << endl;

//5
  vector<double> valori;
  for (int i = 0; i < 1000; i++)
  {
    IntegratoreMedia Int(i,16);
    double I = Int.Integra(f,a,b);
    valori.push_back(I);
  }
  double errore = sqrt(CalcolaVarianza<double>(valori));  
  cout<< "Errore sulla integrazione MC: "<< errore << endl;

//6
  Midpoint myInt3(a,b);
  Measure I3 = myInt3.Integra(16, f);
  double err_mid = abs(Iv-I3.GetValue());
  int n = 1+pow(errore, 2)*16./(pow(err_mid,2));
  cout<< "Numero di punti stimati: "<< n <<  "\nPer una prescisione di: "<< err_mid <<endl;

//7
  nstep = 2, b=2. , a= 0.;
  Midpoint myInt4(0,2);
  Funzione f2([] (double x) {return 1/sqrt(4-x*x);});
  Iv = M_PI*0.5;
  for (unsigned int k = 0; k < n_points; k++) {
    h = (b - a) / (double)nstep; 
    Measure I4 = myInt4.Integra(nstep, f2);
    err = fabs(I4.GetValue() - Iv);
    //cout << "Passi: "  << nstep << " Errore: " << err << endl;
    nstep *= 2;
    if(k == 1){
      x1 = h;
      y1 = err;
    } else if (k == 9) {
      x2 = h;
      y2 = err;
    }
  }
  k2 = log(y2/y1)/log(x2/x1);
  cout << "Midpoint k2: "<< k2 << endl;
  k1 = y1/pow(x1 , k2);
  cout << "Midpoint k1: "<< k1 << endl;

  canvas.SaveAs("../Plot.pdf");
  return 0;
}

