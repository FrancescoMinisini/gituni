#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "Models/RandomGen.h"
#include "Models/IntegralMc.h"
#include "Models/FunzioneBase.h"
#include "Models/EsperimentoPrisma.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;



int main() {
  // Vettori per i dati
    std::vector<double> X, Y, sigmaY;

    // Legge i dati dal file
    std::ifstream inputFile("../dati.txt"); // Sostituisci con il nome del tuo file
    if (!inputFile) {
        std::cerr << "Errore nell'apertura del file!" << std::endl;
    }

    double x, y, sigma_y;
    while (inputFile >> x >> y >> sigma_y) {
        X.push_back(x);
        Y.push_back(y);
        sigmaY.push_back(sigma_y);
    }
    inputFile.close();

    if (X.empty() || Y.empty() || sigmaY.empty()) {
        std::cerr << "Errore: Nessun dato letto dal file!" << std::endl;
    }

    // Crea il grafico con errori
    TCanvas* canvas = new TCanvas("canvas", "Regressione Lineare", 800, 600);
    canvas->SetGridx();
    canvas->SetGridy();

    TGraphErrors* graph = new TGraphErrors(X.size(), &X[0], &Y[0], nullptr, &sigmaY[0]);
    graph->SetTitle("Regressione Lineare;2#DeltaV [V];(BRTm)^{2}");
    graph->SetMarkerStyle(21);
    graph->SetMarkerSize(0.8);
    graph->SetMarkerColor(kBlue);

    // Disegna il grafico
    graph->GetXaxis()->SetTitleSize(0.04);
    graph->GetYaxis()->SetTitleSize(0.04);
    graph->GetXaxis()->SetTitleOffset(1.2);
    graph->GetYaxis()->SetTitleOffset(1.4);

    graph->Fit("pol1");
    // Crea il canvas per il grafico
    graph->Draw("AP");

    // Mostra il canvas
    canvas->SaveAs("../regressione_lineare.png");

    return 0;
}
