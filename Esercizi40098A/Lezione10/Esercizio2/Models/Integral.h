#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "FunzioneBase.h"
#include <cmath>
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
    _maxiterations = 1000;
  };
  Integral(double a, double b, unsigned int it)
  {
    checkInterval(a, b);
    _nstep = 0;
    _h = 0;
    _sum = 0;
    _integral = 0;
    _maxiterations = it;
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
  unsigned int _maxiterations;
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
  Simpson(double a, double b) : Integral(a, b) {}

  Measure Integra(unsigned int nstep, const FunzioneBase &f) override
  {
    // if(nstep % 2 == 1) nstep++;
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

class Trapezi : public Integral
{
public:
  Trapezi(double a, double b) : Integral(a, b) {}
  Trapezi(double a, double b, unsigned int mas) : Integral(a, b, mas) {}
  Measure Integra(unsigned int nstep, const FunzioneBase &f) override
  {
    double h = (_b - _a) / (double)nstep, err = 0, result = 0.5 * (f(_b) + f(_a)), result2 = result;
    for (int i = 1; i < nstep; i++)
    {
      result = f(_a + h * i);
    }
    int steps = 2 * nstep;
    double h2 = h * 0.5;
    for (int i = 1; i < steps; i++)
    {
      result2 = f(_a + h2 * i);
    }
    return Measure(result2, 4 * fabs(result2 - result) / 3);
  }
  
  
  Measure Integra(double prec, const FunzioneBase &f)
  {
    double sum = 0.5*(f(_a)+f(_b)), sigma = prec +1., last = 0, h = _b -_a, result = sum*h;
    int count = 0;
    while (sigma > prec && _maxiterations > count)
    {
      count++;
      last = result;
      h = h*0.5;
      for (int i = 1; i < pow(2, count); i+=2)
      {
        sum += f(_a + h * i);
      }
      result = sum * h;
      sigma = 4 * fabs(last - result) / 3;
    }
    return Measure(result, sigma, count);
  }
};

 

double LeggeDiPotenza(double x1,double y1,double x2,double y2){
  return log(fabs(y1/y2))/log(fabs(x1/x2));
}
#endif
