#ifndef MEASURE_H
#define MEASURE_H

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Measure {
public:
    Measure(double v, double s)
        : _value(v), _sigma(s) {
        CalculateRoundedValues();
    }

    Measure(double v, double s, unsigned int it)
        : _value(v), _sigma(s), _iterations(it) {
        CalculateRoundedValues();
    }

    // Operatore di assegnazione
    Measure& operator=(const Measure& m) {
        if (this != &m) { // Protezione contro l'auto-assegnazione
            _value = m._value;
            _sigma = m._sigma;
            _iterations = m._iterations;
            _cifre = m._cifre;
            _rounded_value = m._rounded_value;
            _rounded_sigma = m._rounded_sigma;
        }
        return *this;
    }

    // Ritorna la misura con tutte le cifre significative
    double GetValue() const { return _value; }
    double GetSigma() const { return _sigma; }

    // Ritorna la misura con le corrette cifre significative
    double GetRoundedValue() const { return _rounded_value; }
    double GetRoundedSigma() const { return _rounded_sigma; }

    unsigned int GetIterations() const { return _iterations; }

    void Print() const {
        cout << "----------------------------------------" << endl;
        cout << left << setw(20) << "Result:"
             << "(" << fixed << setprecision(_cifre)
             << _rounded_value << " ± " << _rounded_sigma << ")" << endl;

        if (_iterations > 0) {
            cout << left << setw(20) << "Iterations:"
                 << _iterations << endl;
        }

        cout << "----------------------------------------" << endl;
    }

private:
    double _value = 0.0, _sigma = 0.0;
    double _rounded_value = 0.0, _rounded_sigma = 0.0;
    unsigned int _iterations = 0;
    int _cifre = 0;

    void CalculateRoundedValues() {
        _cifre = (_sigma > 0) ? static_cast<int>(-floor(log10(_sigma))) : 0;
        if (_sigma * pow(10, _cifre) < 3.5) _cifre++;
        _rounded_value = round(_value * pow(10, _cifre)) / pow(10, _cifre);
        _rounded_sigma = round(_sigma * pow(10, _cifre)) / pow(10, _cifre);
    }
};

#endif
