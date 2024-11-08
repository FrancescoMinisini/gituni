#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "FunzioneBase.h"

using namespace std;

// base class

class Integral
{

public:
  Integral(double a, double b)
  {
    checkInterval(a, b);
    _nstep = 0;
    _h = 0;
    _sum = 0;
    _integral = 0;
  };

  virtual Measure Integra(unsigned int nstep, const FunzioneBase &) = 0;

protected:
  void checkInterval(double a, double b)
  {
    _a = min(a, b);
    _b = max(a, b);
    if (a > b)
      _sign = -1;
    else
      _sign = 1;
  }

  unsigned int _nstep;
  double _a, _b;
  double _sum, _integral, _h;
  int _sign;
};

class Midpoint : public Integral
{

public:
  Midpoint(double a, double b) : Integral(a, b) { ; };

  Measure Integra(unsigned int nstep, const FunzioneBase &f) override
  {

    if (nstep <= 0)
    {
      cout << "Error, number of steps is negative" << endl;
      exit(-1);
    };

    _nstep = nstep;
    _h = (_b - _a) / _nstep;

    _sum = 0.;
    for (unsigned int i = 0; i < _nstep; i++)
    {
      _sum += f.Eval(_a + (i + 0.5) * _h);
    }
    _integral = _sign * _sum * _h;
    return Measure(_integral, 0., nstep);
  };
};

class Simpson : public Integral
{

public:
  Simpson(double a, double b) : Integral(a, b) { }

  Measure Integra(unsigned int nstep, const FunzioneBase &f) override
  {
    //if(nstep % 2 == 1) nstep++; 
    double result = 0, h = (_b - _a) / nstep;
    int c = 0;
    result += f.Eval(_a) + f.Eval(_b); 
    for (int i = 1; i < nstep; i++)
    {
      c = (i % 2 == 0) ? 2 : 4;
      result += (double)c * f.Eval(_a + i * h);
    }
    result *= h / 3.0; 
    return Measure(result, pow(h, 4)); 
  }
};

#endif
