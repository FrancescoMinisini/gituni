#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__
#include <cmath>
#include <err.h>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <armadillo>

class RandomGen
{

public:
    RandomGen(unsigned int seed = static_cast<unsigned int> (time(nullptr)), unsigned int a = 1664525, unsigned int c = 1013904223, unsigned int m = 1 << 31) : _a(a), _c(c), _m(m), _seed(seed) {};

    void SetA(unsigned int a) { _a = a; }
    void SetC(unsigned int c) { _c = c; }
    void SetM(unsigned int m) { _m = m; }

    double Rand()
    {
        unsigned int n = (_a * _seed + _c) % _m;
        double result = (double)n / (double)_m;
        _seed = n;
        return result;
    }

    double Unif(double xmin, double xmax)
    {
        if (xmin > xmax)
        {
            double temp = xmax;
            xmax = xmin;
            xmin = temp;
        }
        return xmin + (xmax - xmin) * Rand();
    };
    
arma::vec Unif(const arma::vec& inf, const arma::vec& sup) {
    if (inf.size() != sup.size()) {
        throw std::runtime_error("Le dimensioni di 'inf' e 'sup' non coincidono!");
    }

    arma::vec out(inf.size());

    for (arma::uword i = 0; i < inf.size(); ++i) {
        double local_min = inf[i];
        double local_max = sup[i];

        if (local_min > local_max) {
            std::swap(local_min, local_max);
        }

        double r = Rand();  
        out[i] = local_min + (local_max - local_min) * r;
    }

    return out;
}

    double Exp(double lambda)
    {
        lambda = (lambda > 0) ? lambda : -lambda;

        return (-1 / lambda) * log(1 - Rand());
    }
    double Gaus(double mean, double sigma)
    {
        double s = Rand();
        double t = Rand();
        double x = sqrt(-2. * log(1. - s)) * cos(2. * M_PI * t);
        return mean + x * sigma;
    }
double GausAR(double mean, double sigma, double xmin, double xmax) {
    double max = 1.0 / (sigma * sqrt(2.0 * M_PI));
    
    double x, y, g;
    do {
        x = Unif(xmin, xmax);
        
        y = Unif(0, max);
        
        g = (1.0 / (sigma * sqrt(2.0 * M_PI))) * exp(-0.5 * pow((x - mean) / sigma, 2.0));
    } while (y > g);  // Rifiuta il punto se y > g
    
    return x;
}


private:
    unsigned int _a, _c, _m;
    unsigned int _seed;
};

#endif
