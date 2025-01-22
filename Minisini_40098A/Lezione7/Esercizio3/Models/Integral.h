#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "FunzioneBase.h"
#include "Measure.h"
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
class Midright : public Integral
{

public:
  Midright(double a, double b) : Integral(a, b) { ; };
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
      _sum += f.Eval(_a + (i + 1) * _h);
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
    if(nstep % 2 == 1) nstep++;
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
      result += f(_a + h * i);
    }
    int steps = 2 * nstep;
    double h2 = h * 0.5;
    for (int i = 1; i < steps; i++)
    {
      result2 += f(_a + h2 * i);
    }
  result *= h;
  result2 *= h2;
    return Measure(result2, 4. * fabs(result2 - result) / 3.);
  }
  
  
  Measure Integra(double prec, const FunzioneBase &f)
  {
    double sum = 0.5*(f(_a)+f(_b)), sigma = INFINITY, last, h = _b -_a, result = sum*h;
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
      if(count != 1) {
      sigma = 4 * fabs(last - result) / 3;
      }
    }
    return Measure(result, sigma, count);
  }
};

class Prova4 : public FunzioneBase {
  public :
    Prova4(double a, double b,double d, double lambda, double l, unsigned int it) : _a(a), _b(b), _d(d), _lambda(lambda), _l(l), _it(it){}
    
    double Eval( double x) const override { 
      Trapezi myInt(_a,_b);
      Funzione f([=] (double t) {return cos((sqrt(_l*_l+ (x-t)*(x-t))-sqrt(_l*_l+x*x))/_lambda)/_d;});
      Measure result =  myInt.Integra(_it, f);
      return result.GetValue(); 
      };

  protected:
  double _a;
  double _b;
  double _d;
  double _lambda;
  double _l;
  unsigned int _it;
};
class Gaussiana : public FunzioneBase {
public:
Gaussiana(double mu, double sigma)
    : _media(mu), _sigma(sigma), _f([mu, sigma](double x) {
      if(sigma == 0){return mu;}
      else{
        return (1.0 / (sigma * sqrt(2 * M_PI))) *
               exp(-0.5 * pow((x - mu) / sigma, 2));
      }
    }) {}


    double Eval(double x) const {
        return _f(x);
    }

    Measure Probability(double t, double prec) const {
        Trapezi integral(_media, _sigma*t); 
        Measure result =  integral.Integra(prec, _f); 
        return  result;
    }

private:
    Funzione _f; // Funzione gaussiana
    double _media;
    double _sigma;
};


double LeggeDiPotenza(double x1,double y1,double x2,double y2){
  return log(fabs(y1/y2))/log(fabs(x1/x2));
}
#endif
