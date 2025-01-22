#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TAxis.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    TCanvas canvas("Analisi Monte Carlo", "Analisi Monte Carlo");
    canvas.Divide(3, 2);

    double precision = 0.001;
    vector<unsigned int> v{500, 1000, 5000, 10000, 50000, 100000};
    vector<double> stdDevs;
    vector<TH1F *> histograms;

    int count = 0;

    for (auto npoints : v)
    {
        ifstream inFile(Form("../../data/MonteCarloData_%d.txt", npoints));

        if (!inFile.is_open())
        {
            cerr << "Errore nell'aprire il file di input per npoints = " << npoints << endl;
            return 1;
        }

        TH1F *hist = new TH1F(Form("MonteCarlo_%d", npoints), Form("Distribuzione per npoints = %d; N; Value", npoints), 100, 0.88, 1.18);
        hist->SetLineColor(kBlue);
        hist->SetLineWidth(2);
        hist->SetFillColor(kCyan);
        hist->SetFillStyle(3004);

        double value;

        while (inFile >> value)
        {
            hist->Fill(value);
        }

        stdDevs.push_back(hist-> GetStdDev());
        histograms.push_back(hist);
        inFile.close();
    }

    for (auto hist :histograms){
        canvas.cd(++count);
        hist->Draw();
    }

    canvas.SaveAs("../AnalysisPlot.pdf");

    TCanvas canError("Errore","Errore");
    TGraph error;

    canError.cd();
    for (int i = 0; i < v.size(); i++)
    {
        error.SetPoint(i,v[i],histograms[i]->GetStdDev());
    }
    error.SetTitle("Errore nella stima dell'integrale; Npoints; Error");
    error.GetXaxis()->SetTitle("Npoints");
    canError.SetGridx();
    canError.SetGridy();
    canError.SetLogx();
    canError.SetLogy();
    error.GetYaxis()->SetTitle("Error");
    error.SetMarkerStyle(20);
    error.SetLineColor(35);
    error.Draw("ALP");
    canError.SaveAs("../VariancePlot.pdf");

    double k = histograms[v.size()-1]->GetStdDev()* sqrt(v[v.size()-1]);
    cout << "N per una incertezza di "<< precision<< " : " << pow(k/precision,2)<< endl;
   
    vector<double> stdDevs2;
    vector<TH1F *> histograms2;
    count = 0;

    for (auto npoints : v)
    {
        ifstream inFile(Form("../../data/MonteCarloData_HitOrMiss_%d.txt", npoints));

        if (!inFile.is_open())
        {
            cerr << "Errore nell'aprire il file di input per npoints = " << npoints << endl;
            return 1;
        }

        TH1F *hist = new TH1F(Form("MonteCarlo_HitOrMiss_%d", npoints), Form("Distribuzione per npoints = %d; N; Value", npoints), 100, 0.88, 1.18);
        hist->SetLineColor(kBlue);
        hist->SetLineWidth(2);
        hist->SetFillColor(kCyan);
        hist->SetFillStyle(3004);

        double value;

        while (inFile >> value)
        {
            hist->Fill(value);
        }

        stdDevs2.push_back(hist-> GetStdDev());
        histograms2.push_back(hist);
        inFile.close();
    }

    for (auto hist :histograms2){
        canvas.cd(++count);
        hist->Draw();
    }

    canvas.SaveAs("../AnalysisPlot_HitOrMiss.pdf");

    TCanvas canError2("Errore","Errore");
    TGraph error2;

    canError2.cd();
    for (int i = 0; i < v.size(); i++)
    {
        error2.SetPoint(i,v[i],histograms2[i]->GetStdDev());
    }
    error2.SetTitle("Errore nella stima dell'integrale; Npoints; Error2");
    error2.GetXaxis()->SetTitle("Npoints");
    canError2.SetGridx();
    canError2.SetGridy();
    canError2.SetLogx();
    canError2.SetLogy();
    error2.GetYaxis()->SetTitle("Error");
    error2.SetMarkerStyle(20);
    error2.SetLineColor(35);
    error2.Draw("ALP");
    canError2.SaveAs("../VariancePlot_HitOrMiss.pdf");

    double h = histograms2[v.size()-1]->GetStdDev()* sqrt(v[v.size()-1]);
    cout << "HitOrMiss N per una incertezza di "<< precision<< " : " << pow(h/precision,2)<< endl;

    return 0;
}
