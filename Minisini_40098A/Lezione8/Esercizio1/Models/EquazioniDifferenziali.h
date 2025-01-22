#ifndef __EquazioniDifferenziali_h__
#define __EquazioniDifferenziali_h__

#include <cmath>
#include<armadillo>

using namespace std;
double operator*(const arma::vec& a, const arma::vec& b) {
    return arma::dot(a, b);
}
arma::vec operator^(const arma::vec& a, const arma::vec& b) {
    return arma::cross(a, b);
}


class FunzioneVettorialeBase {

public:
  virtual arma::vec Eval(double t, const arma::vec & x) const = 0;
};


class OscillatoreArmonico : public FunzioneVettorialeBase {
public:
  OscillatoreArmonico(double omega0) {  _omega0 = omega0;  } ;

  virtual arma::vec Eval(double t, const arma::vec & x) const {
        // x[0] = posizione, x[1] = velocità
        arma::vec dxdt(2);
        dxdt[0] = x[1];                    // Derivata della posizione = velocità
        dxdt[1] = -_omega0 * _omega0 * x[0]; // Derivata della velocità = accelerazione
        return dxdt;
  };

 private:
  double _omega0;  
};

// ===========================================================================
// classe astratta per un integratore di equazioni differenziali
// ===========================================================================

class EquazioneDifferenzialeBase {

public:
  virtual arma::vec Passo(double t, 
                               const arma::vec& x, 
                               double h, 
                               const FunzioneVettorialeBase &f) const =0;
};

// integratore concreto, metodo di Eulero

class Eulero : public EquazioneDifferenzialeBase {

 public:

  virtual arma::vec Passo(double t, 
                               const arma::vec & x, 
                               double h, 
                               const FunzioneVettorialeBase &f) const override {
        arma::vec dxdt = f.Eval(t, x); // Compute f(t, x)
        arma::vec x_next(x.size());

        // Euler's method: x_next = x + h * f(t, x)
        for (size_t i = 0; i < x.size(); ++i) {
            x_next[i] = x[i] + h * dxdt[i];
        }
        return x_next;
    }

};

#endif
