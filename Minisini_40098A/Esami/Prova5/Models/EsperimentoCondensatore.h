#ifndef _ESPERIMENTO_CONDENSATORE_H_
#define _ESPERIMENTO_CONDENSATORE_H_

#include "RandomGen.h"

class EsperimentoCondensatore
{

public:
  EsperimentoCondensatore(unsigned int seed);
  ~EsperimentoCondensatore() { ; };
  EsperimentoCondensatore(unsigned int seed, double C, double R, double sigmar, double V0, double sigmav0, double V1, double sigmav1, double erroreperct) : _gen(seed), _C_input(C), _R_input(R), _R_sigma(sigmar), _V0_input(V0), _V0_sigma(sigmav0), _V1_input(V1), _V1_sigma(sigmav1)
  {
    _dt_input = R * C * log(V0 / V1);
    _dt_sigma = _dt_input*erroreperct;
  }

  void Esegui()
  {
    _V0_misurato = _gen.Gaus(_V0_input, _V0_sigma);
    _V1_misurato = _gen.Gaus(_V1_input, _V1_sigma);
    _R_misurato = _gen.Gaus(_R_input, _R_sigma);
    _dt_misurato = _gen.Gaus(_dt_input, _dt_sigma);
  };

  void Analizza()
  {
    _C_misurato = _dt_misurato / (_R_misurato * log(_V0_misurato / _V1_misurato));
  };

  Measure Risultato(unsigned int iterations)
  {
    vector<double> results;
    for (int i = 0; i < iterations; i++)
    {
        Esegui();
        Analizza();
        results.push_back(getCmis());
    }
      Measure result(CalcolaMedia<double>(results), sqrt(CalcolaVarianza<double>(results)));
  return result;
  }

  double getCmis() { return _C_misurato; };
  double getRmis() { return _R_misurato; };
  double getV0mis() { return _V0_misurato; };
  double getV1mis() { return _V1_misurato; };
  double getDtmis() { return _dt_misurato; };

  double getCinput() { return _C_input; };
  double getRinput() { return _R_input; };
  double getV0input() { return _V0_input; };
  double getV1input() { return _V1_input; };
  double getDtinput() { return _dt_input; };

private:
  // valori delle quantita' misurabili :
  // input    : valori assunti come ipotesi nella simulazione
  // misurato : valore dopo la simulazione di misura

  double _C_input, _C_misurato;
  double _R_input, _R_misurato, _R_sigma;
  double _V0_input, _V0_misurato, _V0_sigma;
  double _V1_input, _V1_misurato, _V1_sigma;
  double _dt_input, _dt_misurato, _dt_sigma;
  RandomGen _gen;
};

#endif
