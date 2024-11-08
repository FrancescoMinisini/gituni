#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cfloat>

#include "TH1F.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TAxis.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TLine.h"

using namespace std;

// ===========================================================
// Funzione per leggere i dati da un file e salvarli in un vettore
// ===========================================================
vector<double> ParseFile(const string& filename) {
    ifstream fin(filename.c_str());
    vector<double> data;
    double val;

    if (!fin) {
        cerr << "Impossibile aprire il file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    while (fin >> val)
        data.push_back(val);

    fin.close();
    return data;
}

// ===========================================================
// Funzione per calcolare S(q)
// ===========================================================
double SFunction(double q, const vector<double>& charges) {
    double sum = 0;
    for (const auto& charge : charges) {
        double n = round(charge / q);
        sum += pow(q - charge / n, 2);
    }
    return sum;
}

// ===========================================================
// Funzione per calcolare q_min (miglior stima della carica elementare)
// ===========================================================
double ComputeQMin(double qmin, const vector<double>& charges) {
    double sum = 0;
    for (const auto& charge : charges) {
        double n = round(charge / qmin);
        sum += charge / n;
    }
    return sum / charges.size();
}

// ===========================================================
// Funzione per il fit con ROOT (usata da TF1)
// ===========================================================
double SFunctionROOT(double* q, double* params) {
    double sum = 0;
    int numCharges = static_cast<int>(params[0]);
    for (int k = 0; k < numCharges; ++k) {
        double charge = params[k + 1];
        double n = round(charge / q[0]);
        sum += pow(q[0] - charge / n, 2);
    }
    return sum;
}

// ===========================================================
// Funzione principale
// ===========================================================
int main(int argc, char* argv[]) {
    TApplication app("app", &argc, argv);

    // Imposta lo stile generale dei grafici
    gStyle->SetOptStat(0);
    gStyle->SetPalette(kRainBow);

    // Legge le cariche dal file
    vector<double> charges = ParseFile("../data_millikan.dat");

    // Stima della carica elementare
    double qmin = 0.0;
    double sqmin = DBL_MAX;
    double qStart = 1.51e-19;
    double qEnd = 1.75e-19;
    double qStep = 0.001e-19;

    TGraph sGraph;
    int counter = 0;

    for (double q = qStart; q <= qEnd; q += qStep) {
        double sValue = SFunction(q, charges);
        sGraph.SetPoint(counter, q, sValue);
        if (sValue < sqmin) {
            sqmin = sValue;
            qmin = q;
        }
        ++counter;
    }

    cout << "Trovato minimo approssimato a q = " << qmin << " C" << endl;

    // Raffina la stima usando il metodo derivativo
    double elementaryCharge = ComputeQMin(qmin, charges);
    cout << "Carica elementare stimata: " << elementaryCharge << " C" << endl;

    // Calcola l'incertezza statistica
    double sAtQ = SFunction(elementaryCharge, charges);
    double uncertainty = sqrt(sAtQ / (charges.size() * (charges.size() - 1)));
    cout << "Incertezza: " << uncertainty << " C (solo statistica)" << endl;

    // Crea l'istogramma dei multipli della carica elementare
    TCanvas canvasHistogram("canvasHistogram", "Istogramma dei Multipli di Carica");
    canvasHistogram.cd();

    int numBins = 10;
    double minMultiple = 0.5;
    double maxMultiple = 10.5;

    TH1F histoMultiples("histoMultiples", "Distribuzione dei Multipli di Carica", numBins, minMultiple, maxMultiple);

    for (const auto& charge : charges) {
        double multiple = charge / elementaryCharge;
        histoMultiples.Fill(multiple);
    }

    // histoMultiples.SetFillColor(kAzure - 4);
    histoMultiples.SetLineColor(kAzure);
    histoMultiples.SetTitle("Distribuzione dei Multipli della Carica Elementare");
    histoMultiples.GetXaxis()->SetTitle("Multiplo della Carica Elementare (q / e)");
    histoMultiples.GetYaxis()->SetTitle("Conteggi");
    histoMultiples.Draw();

    canvasHistogram.SaveAs("../IstogrammaMultipliCarica.pdf");

    // Grafico di S(q) vs q
    TCanvas canvasSGraph("canvasSGraph", "S(q) vs q");
    canvasSGraph.cd();

    sGraph.SetTitle("S(q) vs q");
    sGraph.GetXaxis()->SetTitle("q (C)");
    sGraph.GetYaxis()->SetTitle("S(q) (C^{2})");
    sGraph.SetMarkerStyle(20);
    sGraph.SetMarkerSize(0.8);
    sGraph.SetMarkerColor(kRed);
    sGraph.SetLineColor(kRed);
    sGraph.Draw("ALP");

    // Evidenzia il minimo trovato
    TLine minLine(qmin, -4, qmin, sqmin);
    minLine.SetLineStyle(2);
    minLine.SetLineColor(kBlue);
    minLine.Draw();

    TLegend legend(0.6, 0.7, 0.88, 0.85);
    legend.AddEntry(&sGraph, "S(q)", "l");
    legend.AddEntry(&minLine, Form("Minimo a q = %.2e C", qmin), "l");
    legend.Draw();

    canvasSGraph.SaveAs("../GraficoSFunction.pdf");

    // Esegue l'applicazione
    app.Run();

    return 0;
}
