#ifndef _ESPERIMENTO_PRISMA_H_
#define _ESPERIMENTO_PRISMA_H_

#include "RandomGen.h"

class EsperimentoPrisma {

 public :

  EsperimentoPrisma( unsigned int seed ) ;
  ~EsperimentoPrisma() {;} ;

  void Esegui(){
    _th0_misurato = _gen.Gaus( _th0_input, _sigmat);
    _th1_misurato = _gen.Gaus( _th1_input, _sigmat);
    _th2_misurato = _gen.Gaus( _th2_input, _sigmat);
  } ;
  
  void Analizza() {
      _dm1_misurato = _th1_misurato - _th0_misurato;
      _dm2_misurato = _th2_misurato - _th0_misurato;

      _n1_misurato = sin((_dm1_misurato + _alpha)*0.5) / sin(_alpha *0.5);
      _n2_misurato = sin((_dm2_misurato + _alpha)*0.5) / sin(_alpha *0.5);

      double lambda1_squared = _lambda1 * _lambda1;
      double lambda2_squared = _lambda2 * _lambda2;
      double n1_squared = _n1_misurato * _n1_misurato;
      double n2_squared = _n2_misurato * _n2_misurato;

      _A_misurato = (lambda2_squared * n2_squared - lambda1_squared * n1_squared) / (lambda2_squared - lambda1_squared);
      _B_misurato = (n2_squared - n1_squared) / (1.0 / lambda2_squared - 1.0 / lambda1_squared);
  };

  double getAmis() { return _A_misurato ; } ;
  double getBmis() { return _B_misurato ; } ;
  double getN1mis() { return _n1_misurato ; } ;
  double getN2mis() { return _n2_misurato ; } ;
  double getDm1mis() { return _dm1_misurato ; } ;
  double getDm2mis() { return _dm2_misurato ; } ;
  double getTh0mis() { return _th0_misurato ; } ;
  double getTh1mis() { return _th1_misurato ; } ;
  double getTh2mis() { return _th2_misurato ; } ;

  double getAInput() { return _A_input ; } ;
  double getBInput() { return _B_input ; } ;
  double getN1Input() { return _n1_input ; } ;
  double getN2Input() { return _n2_input ; } ;
  double getDm1Input() { return _dm1_input ; } ;
  double getDm2Input() { return _dm2_input ; } ;
  double getTh0Input() { return _th0_input ; } ;
  double getTh1Input() { return _th1_input ; } ;
  double getTh2Input() { return _th2_input ; } ;

 private:

  // generatore di numeri casuali
  RandomGen _gen ;

  // parametri dell'apparato sperimentale
  double _lambda1, _lambda2, _alpha, _sigmat;

  // valori delle quantita' misurabili :
  // input    : valori assunti come ipotesi nella simulazione
  // misurato : valore dopo la simulazione di misura 

  double _A_input, _A_misurato;
  double _B_input, _B_misurato;
  double _n1_input, _n1_misurato;
  double _n2_input, _n2_misurato;
  double _dm1_input, _dm1_misurato;
  double _dm2_input, _dm2_misurato;
  double _th0_input, _th0_misurato;
  double _th1_input, _th1_misurato;
  double _th2_input, _th2_misurato;

};

EsperimentoPrisma::EsperimentoPrisma( unsigned int seed ) : _gen( seed ), _lambda1(579.1E-9), _lambda2(404.7E-9), _alpha(60.*M_PI/180.), _sigmat(0.3E-3), _A_input(2.7), _B_input(60000E-18)
{
  _n1_input = sqrt( _A_input + _B_input / (_lambda1*_lambda1) ) ;
  _n2_input = sqrt( _A_input + _B_input / (_lambda2*_lambda2) ) ;

  _th0_input = M_PI/2. ;

  _dm1_input = 2.*asin( _n1_input * sin (0.5 * _alpha) ) - _alpha ;
  _th1_input = _th0_input + _dm1_input ;
  _dm2_input = 2.*asin( _n2_input * sin (0.5 * _alpha) ) - _alpha ;
  _th2_input = _th0_input + _dm2_input ;

}

#endif
