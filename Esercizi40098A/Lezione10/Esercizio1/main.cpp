#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TF1.h"
#include "TGraph.h"

#include <iostream>
#include <vector>
#include "Models/RandomGen.h"

int main()
{
    // TApplication app("app", 0, 0);

    RandomGen myGen(1);

    int nmax = 100000;

    TCanvas can2("Uniforme", "Uniforme");
    can2.Divide(3, 4);

    std::vector<TH1F *> histograms;

    std::vector<double> variances;

    for (int i = 0; i < 12; i++)
    {
        TH1F *unifHist = new TH1F(Form("Uniforme_%d", i + 1), Form("Distribuzione per N = %d; x [AU]; N", i + 1), 100, 0, i+1);

        for (int k = 0; k < nmax; ++k)
        {
            double sum = 0;
            for (int h = 0; h <= i; ++h)
            {
                sum += myGen.Rand();
            }
            unifHist->Fill(sum);
        }

        histograms.push_back(unifHist);

        variances.push_back(unifHist->GetStdDev() * unifHist->GetStdDev());
    }
    int count = 0;
    for (auto histo : histograms)
    {
        count++;
        can2.cd(count);
        //histo->Fit("gaus");
        histo->Draw();
    }
    can2.SaveAs("Plotting.pdf");
    TCanvas canVar("Varianze", "Teorema del limite centrale");
    TGraph varGraph(variances.size());

    for (size_t i = 0; i < variances.size(); ++i)
    {
        varGraph.SetPoint(i, i + 1, variances[i]);
    }

    canVar.SetGridx();
    canVar.SetGridy();
    varGraph.SetTitle("Teorema del limite centrale; N; Varianza");
    varGraph.GetXaxis()->SetTitle("N");
    varGraph.GetYaxis()->SetTitle("Varianza");
    varGraph.SetMarkerStyle(20);
    varGraph.SetLineColor(30);
    varGraph.Draw("ALP");
    canVar.SaveAs("VariancePlot.pdf");

    for (auto hist : histograms)
    {
        delete hist;
    }

    // app.Run();

    return 0;
}
