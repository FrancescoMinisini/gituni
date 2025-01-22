#ifndef SOLUTORE_H
#define SOLUTORE_H

#include "Measure.h"
#include "FunzioneBase.h"

class Solutore {
public:
    Solutore() {}
    Solutore(double prec) : _prec(prec) {}
    Solutore(double prec, unsigned int nmax) : _prec(prec), _nmax(nmax) {}
    Solutore(double xmin, double xmax) : _xmin(xmin), _xmax(xmax) {}
    Solutore(double xmin, double xmax, double prec) : _xmin(xmin), _xmax(xmax), _prec(prec) {}
    Solutore(double xmin, double xmax, double prec, unsigned int nmax) : _xmin(xmin), _xmax(xmax), _prec(prec), _nmax(nmax) {}
    virtual ~Solutore() {}

    virtual Measure CercaZeri(double xmin, double xmax, const FunzioneBase* f) = 0;
    virtual Measure CercaZeri(double xmin, double xmax, const FunzioneBase& f) = 0;

    virtual Measure CercaZeri(const FunzioneBase* f) = 0;
    virtual Measure CercaZeri(const FunzioneBase& f) = 0;

    void SetPrecisione(double epsilon) { _prec = epsilon; }
    double GetPrecisione() const { return _prec; }

    void SetNMaxiterations(unsigned int n) { _nmax = n; }
    unsigned int GetNMaxiterations() const { return _nmax; }

    unsigned int GetNiterations() const { return _niterations; }

protected:
    double _xmin = 0.0, _xmax = 0.0;  // Estremi dell'intervallo di ricerca
    double _prec = 0.001;       // Precisione richiesta
    unsigned int _nmax = 100;   // Numero massimo di iterazioni
    unsigned int _niterations = 0;  // Numero di iterazioni effettuate
};

#endif
