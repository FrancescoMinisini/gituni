#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "FunzioneBase.h"

using namespace std;                                                        

// base class

class Integral {

 public:

  Integral (double a, double b) {
    checkInterval (a,b);
    m_nstep = 0;
    m_h = 0 ;
    m_sum = 0 ;
    m_integral = 0 ;
  } ;

  virtual double Integra(unsigned int nstep, const FunzioneBase &) = 0 ;

 protected:

  void checkInterval( double a, double b ) {
    m_a = min(a,b);
    m_b = max(a,b);
    if ( a > b ) m_sign = -1;
    else m_sign = 1;
  }

  unsigned int m_nstep;
  double m_a, m_b;
  double m_sum, m_integral, m_h;
  int m_sign;

};

// derived class

class Midpoint : public Integral {

 public:

  Midpoint (double a, double b) : Integral(a,b) { ; } ;

  double Integra(unsigned int nstep, const FunzioneBase& f ) override {

    if ( nstep <= 0 ) { cout << "Error, number of steps is negative" << endl; exit(-1) ; } ;

    m_nstep = nstep;
    m_h = (m_b-m_a)/m_nstep;

    m_sum = 0.;
    for (unsigned int i=0; i<m_nstep; i++ ) {
      m_sum += f.Eval( m_a  + (i+0.5)*m_h );
    }
    m_integral = m_sign*m_sum*m_h;
    return m_integral;
  };

};
double LeggeDiPotenza(double x1,double y1,double x2,double y2){
  return log(fabs(y1/y2))/log(fabs(x1/x2));
}

#endif // __INTEGRAL_H__                                   
