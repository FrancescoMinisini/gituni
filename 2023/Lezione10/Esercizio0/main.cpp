#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TF1.h"

#include <iostream>
#include "Models/RandomGen.h"

int main()
{
  TApplication app("app", 0, 0);

  RandomGen myGen(1);

  int nmax = 10000;

  TCanvas can2("Uniforme", "Uniforme");
  can2.Divide(2, 2);

  TH1F unifHist("Uniforme", "Distribuzione Uniforme; x [AU]; N", 70, 4, 11);
  TH1F expHist("Esponenziale", "Distribuzione Esponenziale; x [AU]; N", 70, 0, 10);
  TH1F gaussHist ("Gaussiana", "Distribuzione Gaussiana; x [AU]; N", 70, 0, 200);
  TH1F gaussAR ("Gaussiana", "Distribuzione Gaussiana; x [AU]; N", 70, 0, 200);


  // Riempi istogrammi
  for (int k = 0; k < nmax; ++k)
  {
    unifHist.Fill(myGen.Unif(5, 10)); 
    expHist.Fill(myGen.Exp(1));       
    gaussHist.Fill(myGen.Gaus(100,10));
    gaussAR.Fill(myGen.GausAR(100,10,50,150));
  }

  can2.cd(1);
  // unifHist.Fit("pol1");
  unifHist.Draw();
  
  can2.cd(2);
  expHist.Fit("expo");
  expHist.Draw();
  
  can2.cd(3);
  gaussHist.Fit("gaus");
  gaussHist.Draw();

  can2.cd(4);
  gaussHist.Fit("gaus");
  gaussHist.Draw();

  can2.SaveAs("../Plotting.pdf");
  app.Run();

  return 0;
}
