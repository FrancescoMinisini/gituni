#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TF1.h"
#include "Models/RandomGen.h"
#include "Models/IntegralMc.h"
#include "Models/FunzioneBase.h"
#include "Models/Integral.h"
#include "Models/Measure.h"
#include "Models/Vettore.h"
#include "Models/EquazioniDifferenziali.h"
#include "Models/Bisezione.h"
#include "Models/EsperimentoCondensatore.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
//1
double C = 2e-6, v0 = 12, v1 = 3, R = 100e3;
double errore = 0.03;
unsigned int iterations = 10000;
EsperimentoCondensatore esperimento(1,C,R,R*errore, v0, v0*errore, v1, v1*errore, errore);
Measure result = esperimento.Risultato(iterations);
result.Print();
cout<< "Errore percentuale: " << result.GetSigma()/result.GetValue()<< endl;

//2
vector<double> errori;

EsperimentoCondensatore esperimento2(1,C,R,R*errore, v0, 0, v1, 0, 0);
Measure result2 = esperimento2.Risultato(iterations);
result2.Print();
double errore2 = result2.GetSigma()/result2.GetValue();
errori.push_back(errore2);
cout<< "Errore percentuale: " << errore2<< endl;

EsperimentoCondensatore esperimento3(1,C,R, 0 , v0, v0*errore, v1, v1*errore, 0 );
Measure result3 = esperimento3.Risultato(iterations);
double errore3 = result3.GetSigma()/result3.GetValue();
errori.push_back(errore3);
cout<< "Errore percentuale: " << errore3<< endl;


EsperimentoCondensatore esperimento4(1,C,R, 0 , v0, 0 , v1, 0, errore);
Measure result4 = esperimento4.Risultato(iterations);
double errore4 = result4.GetSigma()/result4.GetValue();
errori.push_back(errore4);
cout<< "Errore percentuale: " << errore4<< endl;

sort(errori.begin(), errori.end());
cout<< "L'errore che ha il maggior impatto è quello su: ";
if (errori[errori.size()-1] == errore2) {
  cout<< "R"<< endl;
} else if (errori[errori.size()-1] == errore3) {
  cout<< "Tensioni"<< endl;
} else if (errori[errori.size()-1] == errore4) {
  cout<< "Tempo"<< endl;
}

//3
Funzione f([&] (double x) {
EsperimentoCondensatore esperimento6(1,C,R,R*errore, v0, v0*x, v1, v1*x, errore);
        Measure result = esperimento6.Risultato(iterations); 
        return result.GetSigma()/result.GetValue();});
TGraph* graph = f.Plot("Errore percentuale su C; #sigma_{V}(%);#sigma_{C}(%)", .02,.07);

//4
TF1 fitFunction("fitFunction", "pol1", .02, .07); // Esempio di fit con polinomio di grado 2
graph->Fit(&fitFunction, "R");

// Stampa i parametri del fit
double par0 = fitFunction.GetParameter(0); // Costante
double par1 = fitFunction.GetParameter(1); // Coefficiente lineare
cout << "Fit parameters: " << par0 << ", " << par1 <<endl;





  return 0;
}
