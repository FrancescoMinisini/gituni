#include <vector>      // contenitore
#include <algorithm>   // funzioni
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
template <typename T> vector<T> Read ( string filename ) {

  vector<T> v;

  ifstream in(filename);

  if ( !in ) {
    cout << "Cannot open file " << filename << endl;
    exit(11);
  } else {
    while ( !in.eof() ) {
      T val;
      in >> val ;
      v.push_back(val);
    };
  };
  return v;   
}
template <typename T> vector<T> Read( int N , string filename) {

  vector<T> v;

  ifstream in(filename);  

  if ( !in ) {
    cout << "Cannot open file " << filename << endl;
    exit(11);
  } else {
    for (int i=0; i<N; i++) {  
      T val ; 
      in >> val ; 
      v.push_back( val ) ;            
      if ( in.eof() ) {
        cout << "End of file reached exiting" << endl;
        exit(11);
      }    
    }
  }
  return v;  
};

template <typename T> void Print( const vector<T> & v ) {
  for (int i=0; i<v.size(); i++) cout << v[i] << endl;  
  return;
};

template <typename T> void Print( const vector<T> & v  , const char* filename ) {
  ofstream out(filename);
  if ( !out ) {
    cout << "Non posso creare il file " << filename << endl;
    return;
  }
  for (int i=0; i<v.size(); i++) out << v[i] << endl;
  out.close();
  return;
};
template <typename T> double CalcolaMediana( vector<T> v ) {

  sort( v.begin(), v.end() ) ;  

  double mediana = 0;

  if ( v.size() %2 == 0 ) {    
    mediana = ( v[v.size() /2 -1 ] + v[ v.size()/2 ]  ) /2.;    
  } else {
    mediana = v[ v.size() /2 ];    
  }

  return mediana;

};

template <typename T> double CalcolaMedia( vector<T> v ) {

    double result = 0;
    for(T value : v){
        result += value/v.size();
    }

    return result;

};
template <typename T> double CalcolaVarianza( vector<T> v ) {

    double result = 0;
    double media = CalcolaMedia<T>(v);
    for(T value : v){
        result += (media-value)*(media-value)/v.size();
    }
    return result;

};
template <typename T>
double CalcolaErrore(const std::vector<T>& v) {
    const size_t n = v.size() / 7;
    if (n == 0) return 0.0;  // Evita divisioni per zero

    double result = 0;
    double media = CalcolaMedia<T>(v);
    const double inv_n = 1.0 / static_cast<double>(n);

    for (size_t i = 0; i < n; ++i) {
        double diff = media - v[i * 7];
        result += diff * diff;
    }

    return sqrt(result * inv_n);
}
