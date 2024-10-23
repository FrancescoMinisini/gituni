#ifndef PUNTOMATERIALE_H
#define PUNTOMATERIALE_H

#include "Posizione.h"
#include "CampoVettoriale.h"
#include "Particella.h"
#include <iostream>
#include <cmath>
using namespace std;

class PuntoMateriale: public Posizione, public Particella {
public:
  PuntoMateriale(double massa, double carica, const Posizione&);
  PuntoMateriale(double massa, double carica, double x, double y, double z);

  ~PuntoMateriale(){;};

  // Qui sta la fisica, calcolo e restituisco il campo in una posizione
  CampoVettoriale CampoElettrico(const Posizione&) const ;
  CampoVettoriale CampoGravitazionale(const Posizione&) const;
};

PuntoMateriale::PuntoMateriale(double massa, double carica, const Posizione& p): Posizione(p.GetX(),p.GetY(),p.GetZ()), Particella(massa, carica){}
PuntoMateriale::PuntoMateriale(double massa, double carica, double x, double y, double z): Posizione(x,y,z), Particella(massa, carica){}
CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& p) const {
    double k = 8.987551787e10;
    double carica = this->GetCarica();
    double distanza = this->Distanza(p);
    double Fx = k*abs(this->GetX()-p.GetX())*carica/pow(distanza,3);
    double Fy = k*abs(this->GetY()-p.GetY())*carica/pow(distanza,3);
    double Fz = k*abs(this->GetZ()-p.GetZ())*carica/pow(distanza,3);
    return CampoVettoriale(p, Fx, Fy, Fz);
}
CampoVettoriale PuntoMateriale::CampoGravitazionale(const Posizione& p) const {
    double G = -6.67e-11;
    double carica = this->GetCarica();
    double distanza = this->Distanza(p);
    double Fx = G*abs(this->GetX()-p.GetX())*carica/pow(distanza,3);
    double Fy = G*abs(this->GetY()-p.GetY())*carica/pow(distanza,3);
    double Fz = G*abs(this->GetZ()-p.GetZ())*carica/pow(distanza,3);
    return CampoVettoriale(p, Fx, Fy, Fz);
}

#endif