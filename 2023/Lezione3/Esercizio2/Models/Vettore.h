#include <vector>      // contenitore
#include <algorithm>   // funzioni

using namespace std;

template <typename T> vector<T> Read( int N , const char* filename ) {

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
