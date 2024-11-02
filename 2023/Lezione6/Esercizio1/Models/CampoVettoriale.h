#ifndef CAMPOVETTORIALE_H
#define CAMPOVETTORIALE_H

#include "Posizione.h"
#include <iostream>
using namespace std;

class CampoVettoriale: public Posizione {
public:
  CampoVettoriale();
  CampoVettoriale(const Posizione&);
  CampoVettoriale(const Posizione&, double Fx, double Fy, double Fz);
  CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz);

  double GetFx() const { return m_Fx; }
  double GetFy() const { return m_Fy; }
  double GetFz() const {return m_Fz;}
  double GetMagnitude() const {return sqrt(m_Fx*m_Fx+m_Fy*m_Fy+m_Fz*m_Fz);}

  void SetFx(double Fx) { m_Fx=Fx;}
  void SetFy(double Fy) { m_Fy=Fy;}
  void SetFz(double Fz) { m_Fz=Fz;}

  CampoVettoriale& operator += (const CampoVettoriale& v){*this = *this + v; return *this;}
  CampoVettoriale operator + (const CampoVettoriale& v) const {
    if ( ( v.GetX()!= GetX() ) || ( v.GetY()!= GetY() ) || ( v.GetZ()!= GetZ() ) ) {
    std::cout << "Somma di campi vettoriali in punti diversi non ammessa" << std::endl;
    exit (-11) ;
  } 
      CampoVettoriale sum ( Posizione( GetX(),GetY(), GetZ()) ) ; // creo un campo vettoriale nella posizione Giusta
  sum.SetFx( GetFx() + v.GetFx()) ;  
  sum.SetFy( GetFy() + v.GetFy()) ;  
  sum.SetFz( GetFz() + v.GetFz()) ;  
  return sum;
}
  CampoVettoriale& operator=(const CampoVettoriale& v){this->m_Fx = v.GetFx(); this->m_Fy = v.GetFy(); this->m_Fz = v.GetFz(); return *this;}

  ~CampoVettoriale() {}

  protected:
  double m_Fx, m_Fy, m_Fz;
};


CampoVettoriale::CampoVettoriale(): Posizione(){
    m_Fx = 0;
    m_Fy = 0;
    m_Fz = 0;
}

CampoVettoriale::CampoVettoriale(const Posizione& p): Posizione(p.GetX(),p.GetY(),p.GetZ()){
    m_Fx = 0;
    m_Fy = 0;
    m_Fz = 0;
}
CampoVettoriale::CampoVettoriale(const Posizione& p, double Fx, double Fy, double Fz): Posizione(p.GetX(),p.GetY(),p.GetZ()){
    m_Fx = Fx;
    m_Fy = Fy;
    m_Fz = Fz;
}
CampoVettoriale::  CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz): Posizione(x,y,z){
    m_Fx = Fx;
    m_Fy = Fy;
    m_Fz = Fz;
}

#endif