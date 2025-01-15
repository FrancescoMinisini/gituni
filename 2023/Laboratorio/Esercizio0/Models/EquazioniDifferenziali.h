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

 protected:
  double _omega0;  
};
class PendoloSemplice : public FunzioneVettorialeBase {
public:
  PendoloSemplice(double l, double g = 9.80505): _l(l) , _g(g) {};

  virtual arma::vec Eval(double t, const arma::vec & x) const {
        // x[0] = posizione, x[1] = velocità
        arma::vec dxdt(2);
        dxdt[0] = x[1];                    // Derivata della posizione = velocità
        dxdt[1] = -_g * x[0]*_l; // Derivata della velocità = accelerazione
        return dxdt;
  };

 protected:
  double _l;
  double _g;

};
class OscillatoreForzatoSmorzato : public OscillatoreArmonico {
public:
    OscillatoreForzatoSmorzato(double omega0, double omega, double alpha)
        : OscillatoreArmonico(omega0), _omega(omega), _alpha(alpha) {}

    // Implementazione della funzione Eval
    virtual arma::vec Eval(double t, const arma::vec &x) const override {
        // x[0] = posizione, x[1] = velocità
        arma::vec dxdt(2);
        dxdt[0] = x[1]; // Derivata della posizione = velocità
        dxdt[1] = -_omega0 * _omega0 * x[0] - _alpha * x[1] + std::sin(_omega * t); // Accelerazione
        return dxdt;
    }

protected:
    double _alpha; // Coefficiente di smorzamento
    double _omega; // Frequenza della forzante
};



class EquazioneDifferenzialeBase {

public:
  virtual arma::vec Passo(double t, const arma::vec& x, double h, const FunzioneVettorialeBase &f) const =0;
};


class Eulero : public EquazioneDifferenzialeBase {

 public:

  virtual arma::vec Passo(double t, const arma::vec & x, double h, const FunzioneVettorialeBase &f) const override {
        arma::vec dxdt = f.Eval(t, x); // Compute f(t, x)
        arma::vec x_next(x.size());

        // Euler's method: x_next = x + h * f(t, x)
        for (size_t i = 0; i < x.size(); ++i) {
            x_next[i] = x[i] + h * dxdt[i];
        }
        return x_next;
    }

};

class RungeKutta : public EquazioneDifferenzialeBase {
public:
    virtual arma::vec Passo(double t, const arma::vec &x, double h, const FunzioneVettorialeBase &f) const override {
        arma::vec k1 = f.Eval(t, x);
        arma::vec temp = x + k1 * 0.5 * h;
        arma::vec k2 = f.Eval(t + h * 0.5, temp);
        
        temp = x + k2 * 0.5 * h;
        arma::vec k3 = f.Eval(t + h * 0.5, temp);
        
        temp = x + k3 * h;
        arma::vec k4 = f.Eval(t + h, temp);

        arma::vec x_next = x + (k1 + 2.0 * k2 + 2.0 * k3 + k4) * h / 6.0;

        return x_next;
    }
};
#endif
