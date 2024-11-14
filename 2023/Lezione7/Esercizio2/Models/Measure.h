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
        _cifre = (_sigma > 0) ? static_cast<int>(-floor(log10(_sigma))) : 0;
        if (_sigma * pow(10, _cifre) < 3.5) _cifre++;
        _rounded_value = round(_value * pow(10, _cifre)) / pow(10, _cifre);
        _rounded_sigma = round(_sigma * pow(10, _cifre)) / pow(10, _cifre);
    }

    Measure(double v, double s, unsigned int it)
        : _value(v), _sigma(s), _iterations(it) {
        _cifre = (_sigma > 0) ? static_cast<int>(-floor(log10(_sigma))) : 0;
        if (_sigma * pow(10, _cifre) < 3.5) _cifre++;
        _rounded_value = round(_value * pow(10, _cifre)) / pow(10, _cifre);
        _rounded_sigma = round(_sigma * pow(10, _cifre)) / pow(10, _cifre);
    }
    
    //Ritorna la misura con tutte le cifre significative
    double GetValue() const { return _value; }
    //Ritorna il sigma con tutte le cifre significative
    double GetSigma() const { return _sigma; }

    //Ritorna la misura con le corrette cifre significative
    double GetRoundedValue() const { return _rounded_value; }
    //Ritorna il sigma con le corrette cifre significative
    double GetRoundedSigma() const { return _rounded_sigma; }

    unsigned int GetIterations() const { return _iterations; }

    Measure& operator = (Measure& m) {
        this->_value = m._value;
        this->_cifre = m._cifre;
        this->_iterations = m._iterations;
        this->_rounded_sigma = m._rounded_sigma;
        this->_rounded_value= m._rounded_value;
        this->_sigma = m._sigma;
        return *this;
    }

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

};

#endif
