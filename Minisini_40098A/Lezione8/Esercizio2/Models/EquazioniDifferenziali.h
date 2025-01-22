#ifndef __EquazioniDifferenziali_h__
#define __EquazioniDifferenziali_h__

#include <cmath>
#include "TGraph.h"
#include "TCanvas.h"
#include <armadillo>

using namespace std;
double operator*(const arma::vec &a, const arma::vec &b)
{
  return arma::dot(a, b);
}
arma::vec operator^(const arma::vec &a, const arma::vec &b)
{
  return arma::cross(a, b);
}

class FunzioneVettorialeBase
{

public:
  virtual arma::vec Eval(double t, const arma::vec &x) const = 0;
};

class OscillatoreArmonico : public FunzioneVettorialeBase
{
public:
  OscillatoreArmonico(double omega0) { _omega0 = omega0; };

  virtual arma::vec Eval(double t, const arma::vec &x) const
  {
    // x[0] = posizione, x[1] = velocità
    arma::vec dxdt(2);
    dxdt[0] = x[1];                      // Derivata della posizione = velocità
    dxdt[1] = -_omega0 * _omega0 * x[0]; // Derivata della velocità = accelerazione
    return dxdt;
  };

private:
  double _omega0;
};

class EquazioneDifferenzialeBase
{

public:

  virtual arma::vec Passo(double t, const arma::vec &x, double h, const FunzioneVettorialeBase &f) const = 0;

  virtual TGraph *Plot(string name, unsigned int index, double t , double tmax , arma::vec x , double h , const FunzioneVettorialeBase &f )
  {
    
    int nstep = int(tmax / h + 0.5);

    // evoluzione del sistema fino a 70 s
    if (index < 0 || index > x.size())
    {
      throw std::out_of_range("Indice fuori dai limiti del vettore");
    }
    TGraph *graph = new TGraph();
    TCanvas canvas("canvas", name.c_str(), 800, 600);

    for (int step = 0; step < nstep; step++)
    {
      graph->SetPoint(step, t, x[index]);
      x = Passo(t, x, h, f);
      t = t + h;
    }
    // Configura e disegna il grafico
    canvas.cd();
    graph->Draw("AL");
    canvas.SetGridx();
    canvas.SetGridy();
    graph->SetTitle(Form("%s", name.c_str()));
    graph->SetLineColor(kRed);
    graph->SetLineWidth(1);
    // graph->SetMarkerStyle(21);
    canvas.SaveAs(("../" + name + ".pdf").c_str());

    return graph;
  }

  virtual arma::vec Errore(double t, double tmax, arma::vec x, double h, const FunzioneVettorialeBase &f)
  {

    int nstep = int(tmax / h + 0.5);
    arma::vec x2 = x;
    double t2 = t;

    for (int step = 0; step < nstep; step++)
    {
      x = Passo(t, x, h, f);
      t = t + h;
    }

    double h2 = h * 0.5;
    int nstep2 = 2*nstep;

    for (int step = 0; step < nstep2; step++)
    {
      x2 = Passo(t2, x2, h2, f);
      t2 = t2 + h2;
    }

    arma ::vec errore = 16. * abs(x - x2) / 15.;
    return errore;
  }

  virtual TGraph *PlotErrore(string name, unsigned int npunti, unsigned int index, double t, double tmax, arma::vec x, double h, const FunzioneVettorialeBase &f )
  {

    TGraph *graph = new TGraph();
    TCanvas canvas("canvas", name.c_str(), 800, 600);
    for (int i = 0; i < npunti; i++)
    {
      arma::vec errore = Errore( t, tmax, x, h, f);
      graph->SetPoint(i, h, errore[index]);
      h *= 0.8;
    }
    canvas.cd();
    graph->Draw("ALP");
    canvas.SetGridx();
    canvas.SetGridy();
    canvas.SetLogx();
    canvas.SetLogy();
    graph->SetTitle(Form("%s", name.c_str()));
    graph->SetLineColor(kRed);
    graph->SetLineWidth(1);
    graph->SetMarkerStyle(21);
    canvas.SaveAs(("../" + name + ".pdf").c_str());

    return graph;
  }

  virtual arma::vec Passo(double sigmarichiesto, double t, double tmax, arma::vec x, double hn, const FunzioneVettorialeBase &f){
    arma::vec errore = Errore(t,tmax,x,hn,f);
    arma::vec result(errore.size());
     for (int i = 0; i < errore.size(); i++)
     {
      result[i] = pow(sigmarichiesto*hn/ errore[i], .25);
     }
    return result;
  }

};

class Eulero : public EquazioneDifferenzialeBase
{

public:
  virtual arma::vec Passo(double t, const arma::vec &x, double h, const FunzioneVettorialeBase &f) const override
  {
    arma::vec dxdt = f.Eval(t, x); // Compute f(t, x)
    arma::vec x_next(x.size());

    // Euler's method: x_next = x + h * f(t, x)
    for (size_t i = 0; i < x.size(); ++i)
    {
      x_next[i] = x[i] + h * dxdt[i];
    }
    return x_next;
  }
};

class RungeKutta : public EquazioneDifferenzialeBase
{
public:
  virtual arma::vec Passo(double t, const arma::vec &x, double h, const FunzioneVettorialeBase &f) const override
  {
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
