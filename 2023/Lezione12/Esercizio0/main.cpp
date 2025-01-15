#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "Models/RandomGen.h"
#include "Models/IntegralMc.h"
#include "Models/FunzioneBase.h"
#include "Models/EsperimentoPrisma.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int count = 10000;
    EsperimentoPrisma esperimento(1);
    vector<TH1F *> histograms;

    TCanvas canvas("Esperimento prisma", "Esperimento prisma", 1200, 800);
    canvas.SetGridx();
    canvas.SetGridy();

    canvas.Divide(3, 4); // Divide il canvas in 3 colonne e 4 righe

    // Creazione e aggiunta degli istogrammi al vettore
    TH1F *A = new TH1F("Discrepanza A", "Discrepanza A;Differenza;Occorrenze", 100, -0.005, -0.005);
    histograms.push_back(A);

    TH1F *B = new TH1F("Discrepanza B", "Discrepanza B;Differenza;Occorrenze", 100, -1e-15, 1e-15);
    histograms.push_back(B);

    TH1F *N1 = new TH1F("Discrepanza n1", "Discrepanza n1;Differenza;Occorrenze", 100, -0.001, 0.001);
    histograms.push_back(N1);

    TH1F *N2 = new TH1F("Discrepanza n2", "Discrepanza n2;Differenza;Occorrenze", 100, -0.001, 0.001);
    histograms.push_back(N2);

    TH1F *TH0 = new TH1F("Discrepanza TH0", "Discrepanza TH0;Differenza;Occorrenze", 100, -0.001, 0.001);
    histograms.push_back(TH0);

    TH1F *TH1 = new TH1F("Discrepanza TH1", "Discrepanza TH1;Differenza;Occorrenze", 100, -0.001, 0.001);
    histograms.push_back(TH1);

    TH1F *TH2 = new TH1F("Discrepanza TH2", "Discrepanza TH2;Differenza;Occorrenze", 100, -0.001, 0.001);
    histograms.push_back(TH2);

    TH1F *D1 = new TH1F("Discrepanza DELTA 1", "Discrepanza DELTA 1;Differenza;Occorrenze", 100, -0.002, 0.002);
    histograms.push_back(D1);

    TH1F *D2 = new TH1F("Discrepanza DELTA 2", "Discrepanza DELTA 2;Differenza;Occorrenze", 100, 0.002, 0.002);
    histograms.push_back(D2);

    // Creazione dei grafici 2D con titoli e assi
    TH2F AB("Residui A B", "Residui A B;A misurato;B misurato", 100, -0.005, 0.005, 100, -0.005e-13, 0.005e-13);
    TH2F D("Residui Delta 1,2", "Residui Delta 1,2;Delta 1 misurato;Delta 2 misurato", 100, -0.002, 0.002, 100, -0.002, 0.002);
    TH2F N("Residui N 1,2", "Residui N 1,2;N1 misurato;N2 misurato", 100, -0.001, 0.001, 100, -0.001, 0.001);

    // Loop per riempire gli istogrammi
    for (int i = 0; i < count; i++)
    {
        esperimento.Esegui();
        esperimento.Analizza();
        A->Fill(esperimento.getAmis() - esperimento.getAInput());
        B->Fill(esperimento.getBmis() - esperimento.getBInput());
        N1->Fill(esperimento.getN1mis() - esperimento.getN1Input());
        N2->Fill(esperimento.getN2mis() - esperimento.getN2Input());
        TH0->Fill(esperimento.getTh0mis() - esperimento.getTh0Input());
        TH1->Fill(esperimento.getTh1mis() - esperimento.getTh1Input());
        TH2->Fill(esperimento.getTh2mis() - esperimento.getTh2Input());
        D1->Fill(esperimento.getDm1mis() - esperimento.getDm1Input());
        D2->Fill(esperimento.getDm2mis() - esperimento.getDm2Input());
        AB.Fill(esperimento.getAmis() - esperimento.getAInput(), esperimento.getBmis() - esperimento.getBInput());
        D.Fill(esperimento.getDm1mis() - esperimento.getDm1Input(), esperimento.getDm2mis() - esperimento.getDm2Input());
        N.Fill(esperimento.getN1mis() - esperimento.getN1Input(), esperimento.getN2mis() - esperimento.getN2Input());
    }

count = 1;
for (size_t i = 0; i <= histograms.size(); ++i) {
    // Gestione dei pannelli per i grafici 2D
    if (count == 3) {
        canvas.cd(count); // Pannello specifico per AB
        AB.StatOverflows(kTRUE);
        AB.Draw("COLZ");
        count++; // Passa al pannello successivo
    }
    else if (count == 6) {
        canvas.cd(count); // Pannello specifico per N
        N.StatOverflows(kTRUE);
        N.Draw("COLZ");
        count++; // Passa al pannello successivo
    }
    else if (count == 12) {
        canvas.cd(count); // Pannello specifico per D
        D.StatOverflows(kTRUE);
        D.Draw("COLZ");
        count++; // Passa al pannello successivo
    }

    // Disegno degli istogrammi 1D
    if (count <= 12) { // Assicurati che ci siano pannelli disponibili
        canvas.cd(count); // Seleziona il pannello
        histograms[i]->StatOverflows(kTRUE);
        histograms[i]->Draw();
        count++; // Passa al pannello successivo
    }
}


    canvas.SaveAs("../FinalPlots.pdf"); // Salva il canvas in un file PDF

    return 0;
}
