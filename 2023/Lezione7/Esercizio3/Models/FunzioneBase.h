#ifndef __FUNZIONE_BASE__
#define __FUNZIONE_BASE__
#include <iostream>
#include <vector>
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TApplication.h"
#include "Integral.h"
#include "Measure.h"
#include <string>
#include <functional>  
#include <cmath>  
using namespace std;


class FunzioneBase
{
public:
    virtual double Eval(double) const = 0;
    virtual double operator()(double value) const { return Eval(value); }
    virtual void Plot(string name, double initialValue = -5., double finalValue = 5., int n_points = 1000) const
    {
        double step = (finalValue - initialValue) / (n_points - 1);

        std::vector<double> x_values(n_points), y_values(n_points);

        for (int i = 0; i < n_points; ++i)
        {
            double x = initialValue + i * step;
            double y = Eval(x);
            x_values[i] = x;
            y_values[i] = y;
        }

        TCanvas canvas("canvas", "Parabola Plot", 800, 600);
        TGraph graph(n_points, &x_values[0], &y_values[0]);
        canvas.cd();
        graph.Draw("ALP");

        graph.SetTitle("Parabola;X values;Y values");
        graph.SetLineColor(kBlue);
        graph.SetLineWidth(2);
        graph.SetMarkerStyle(21);
        graph.SetMarkerSize(0.8);
        graph.SetMarkerColor(kRed);
        canvas.SaveAs(("../" + name + ".pdf").c_str());
    }
    virtual ~FunzioneBase() {};
};

class Parabola : public FunzioneBase
{
public:
    Parabola()
    {
        _a = 0.;
        _b = 0.;
        _c = 0.;
    }
    Parabola(double a, double b, double c) : _a(a), _b(b), _c(c) {}

    double Eval(double value) const override { return _a * value * value + _b * value + _c; }
    double GetVertex() const { return -_b / (_a * 2); }
    void SetA(double a) { _a = a; }
    double GetA() const { return _a; }
    void SetB(double b) { _b = b; }
    double GetB() const { return _b; }
    void SetC(double c) { _c = c; }
    double GetC() const { return _c; }
    void Plot(string name, double initialValue , double finalValue , int n_points) const override
    {   
        double vertex = GetVertex();
        FunzioneBase::Plot(name, initialValue+ vertex, finalValue+vertex, n_points);
    }
    ~Parabola() {};

private:
    double _a, _b, _c;
};

class Segno : public FunzioneBase {
  public :
    double Eval( double x) const override { return (x==0.?0.:(x>0?1.:-1.)); };
};

class Funzione : public FunzioneBase {
public:
    
    Funzione(std::function<double(double)> f) : _f(f) {}
    double Eval(double x) const override {
        return _f(x);
    }

private:
    std::function<double(double)> _f;
};

class Gaussiana : public FunzioneBase {
public:
    Gaussiana(double mu, double sigma) : _media(mu), _sigma(sigma) {
        _f = [this](double x) {
            return (1.0 / (_sigma * std::sqrt(2 * M_PI))) * std::exp(-0.5 * std::pow((x - _media) / _sigma, 2));
        };
    }

    double Eval(double x) const {
        return _f(x);
    }

    double Probability(double x, double prec) const {
        Trapezi integral(_media, x); 
        Measure result =  integral.Integra(prec, _f); 
        return  result.GetValue();
    }

private:
    std::function<double(double)> _f; // Funzione gaussiana
    double _media;
    double _sigma;
};

#endif