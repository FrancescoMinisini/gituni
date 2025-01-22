#ifndef __INTEGRALMC_H__
#define __INTEGRALMC_H__

#include "FunzioneBase.h"
#include <cmath>
#include "RandomGen.h"
using namespace std;

class IntegraleMC {

public:

  IntegraleMC(unsigned int seed, unsigned int punti = 0) : _gen(seed) , _punti(punti) 
  {
    _errore = 0;
  }

  virtual double Integra( const FunzioneBase& f, double inf , double sup ) = 0 ;

  double GetErrore() const {return _errore;}
  unsigned int GetN() const {return _punti;}

protected:

  RandomGen _gen;
  double _errore;
  unsigned int _punti;

};

class IntegratoreMedia : public IntegraleMC {

public:

  IntegratoreMedia(unsigned int seed, unsigned int punti = 0) : IntegraleMC(seed, punti) { ; };

  virtual double Integra ( const FunzioneBase& f, double inf , double sup) {
    double sum = 0;
    for (int i = 0; i < _punti; i++)
    {
      sum += f(_gen.Unif(inf, sup))/(double)_punti;
    }
    return sum*(sup-inf);
  };
};

class IntegratoreHitOrMiss : public IntegraleMC {
public:
    IntegratoreHitOrMiss(unsigned int seed, double fmax ,unsigned int punti = 0)
        : IntegraleMC(seed, punti), _fmax(fmax) { }

    virtual double Integra(const FunzioneBase& f, double inf, double sup) override {
        int count = 0;
        double x, y;
        for (unsigned int i = 0; i < _punti; i++) {
            x = _gen.Unif(inf, sup);
            y = _gen.Unif(0, _fmax);
            if (f(x) > y) {
                count++;
            }
        }
        return (sup - inf) * _fmax * count / (double)_punti;
    }

private:
    double _fmax;
};

#endif
