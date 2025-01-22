#include <vector>      // contenitore
#include <algorithm>   // funzioni
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Posizione {
  public:
    double GetX() const {return x;}
    double GetY() const {return y;}
    double GetZ() const {return z;}
    double GetR() const {
      return sqrt(x*x+y*y+z*z);
    }       
    double GetPhi() const {
      return atan2(y,x);
    }
    double GetTheta() const {
      return acos(z/GetR());
    }
    double GetRho() const {
      return sqrt(x*x+y*y);
    }
    double Distanza(const Posizione& b) const {
  return sqrt( pow(GetX()-b.GetX(),2)
              +pow(GetY()-b.GetY(),2) 
              +pow(GetZ()-b.GetZ(),2) );
}
    
    Posizione(){x = 0.0; y = 0.0; z = 0.0; }
    Posizione(double xm, double ym, double zm){this->x = xm; this->y=ym; this->z=zm;} 
    ~Posizione(){}

  private:
    double x,y,z;
};