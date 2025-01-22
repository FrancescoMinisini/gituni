#ifndef BISEZIONE_H
#define BISEZIONE_H

#include "Solutore.h"
#include "Measure.h"
#include "FunzioneBase.h"
#include <stdexcept>

class Bisezione : public Solutore {
public:
    Bisezione() : Solutore() {}
    Bisezione(double prec) : Solutore(prec) {}
    Bisezione(double prec, unsigned int nmax) : Solutore(prec, nmax) {}
    Bisezione(double xmin, double xmax) : Solutore(xmin, xmax) {}
    Bisezione(double xmin, double xmax, double prec) : Solutore(xmin, xmax, prec) {}
    Bisezione(double xmin, double xmax, double prec, unsigned int nmax) : Solutore(xmin, xmax, prec, nmax) {}

    // Overload di CercaZeri che accetta intervallo e funzione come puntatore
    virtual Measure CercaZeri(double xmin, double xmax, const FunzioneBase* f) override {
        return CercaZeriLogica(xmin, xmax, *f, _prec, _nmax);
    }

    virtual Measure CercaZeri( const FunzioneBase* f) override {
        return CercaZeriLogica(_xmin, _xmax, *f, _prec, _nmax);
    }
    virtual Measure CercaZeri(double xmin, double xmax, const FunzioneBase& f) override {
        return CercaZeriLogica(xmin, xmax, f, _prec, _nmax);
    }

    virtual Measure CercaZeri( const FunzioneBase& f) override {
        return CercaZeriLogica(_xmin, _xmax, f, _prec, _nmax);
    }
    

private:
    Measure CercaZeriLogica(double xmin, double xmax, const FunzioneBase& f, double prec, unsigned int nmax) {
        double epsilon = xmax - xmin;
        double mean = (xmax + xmin) / 2;
        unsigned int count = 0;
        Segno sign;

        if (sign.Eval(f.Eval(xmin) * f.Eval(xmax)) == 1) {
            throw std::runtime_error("Gli estremi hanno lo stesso segno, impossibile applicare la bisezione");
        }

        while (epsilon / 2 > prec && count < nmax) {
            count++;
            int s = sign.Eval(f.Eval(xmin) * f.Eval(mean));

            if (s == 1) {
                xmin = mean;
            } else if (s == -1) {
                xmax = mean;
            } else {
                _niterations = count;
                return Measure(mean, 0.0);
            }

            epsilon = xmax - xmin;
            mean = (xmax + xmin) / 2;
        }

        _niterations = count;
        return Measure(mean, epsilon / 2,count);
    }
};

#endif
