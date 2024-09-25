#include<iostream>
using namespace std;
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"

bool leggiDato(ifstream& file, int &rdato);





my_array_int carica_interi_file_resize (int& n_dati , string directory, int& error_code) {
    my_array_int vettore; 
     
    
  
    vettore.raw = new int [vettore.size];
    if (vettore.raw == NULL) {
        error_code= -2;
        return vettore;
    }
    ifstream data ;
    
    //data.seekg(0,ios::beg); lo riporta all'inizio.
    data.open(directory) ;

    data.close () ;
    vettore.used=vettore.size;
    error_code = 0; 
    return vettore;
     
}

bool leggiDato(ifstream& file, int &rdato){
   
   //Variabile di appoggio
   int appo;

   //Leggo da stream e registro in variabile di appoggio
   file >> appo;

   //Controllo stato dello stream: se in fail() o lo stream è in eof, restituisco false
   //in questo modo il programma chiamante potrà accorgersi che il dato manca.
   if(file.eof() || file.fail()){
      return false;
   }
   else{
      //Il dato effettivamente c'e`. Lo salvo nella variabile "che esporta il valore dalla funzione"
      rdato = appo;
      //Tutto a posto: il dato c'e`: restutuisco true
      return true;
   }


} 
