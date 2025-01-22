#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TGraph.h"
#include "../Models/RandomGen.h"
#include "../Models/IntegralMc.h"
#include "../Models/FunzioneBase.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main()
{
    int nintegrals = 10000;
    std::vector<unsigned int> v{500, 1000, 5000, 10000, 50000, 100000};
    
    FunzioneBase *f = new Funzione([](double x)
                                   { return x * sin(x); });

    int count = 0;

    for (auto npoints : v)
    {
        std::ofstream outFile(Form("../../data/MonteCarloData_%d.txt", npoints));

        if (!outFile.is_open())
        {
            std::cerr << "Errore nell'aprire il file di output per npoints = " << npoints << std::endl;
            return 1;
        }

        IntegratoreMedia myIntegratore(1, npoints);

        for (int i = 0; i < nintegrals; i++)
        {
            double result = myIntegratore.Integra(*f, 0, M_PI * 0.5);
            outFile << result << std::endl;
        }

        outFile.close();
        std::cout << "Dati salvati per npoints = " << npoints << std::endl;
    }
    for (auto npoints : v)
    {
        std::ofstream outFile(Form("../../data/MonteCarloData_HitOrMiss_%d.txt", npoints));

        if (!outFile.is_open())
        {
            std::cerr << "Errore nell'aprire il file di output per npoints = " << npoints << std::endl;
            return 1;
        }

        IntegratoreHitOrMiss myIntegratore2(1,M_PI*0.5, npoints);

        for (int i = 0; i < nintegrals; i++)
        {
            double result = myIntegratore2.Integra(*f, 0, M_PI * 0.5);
            outFile << result << std::endl;
        }

        outFile.close();
        std::cout << "Dati salvati per npoints = " << npoints << std::endl;
    }

    delete f;
    return 0;
}
