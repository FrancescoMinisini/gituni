#include<iomanip>
#include <iostream> 
#include <fstream>
#include <cstring>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
using namespace std;


  
struct sfere
{
    float diam; 
    char colore;
};

sfere* define_array_file_sfere ( int& n_dati , string directory);
int elimina (sfere valori [], int used, int pos);
void scambia ( sfere , int , int);
  

int main () {
    string directory = "sfere.dat"; 
    sfere*sfera ; 
    int used; 
    int n_dati=0 ;
    int rn_dati = n_dati;  
    sfera = define_array_file_sfere ( rn_dati , directory); 
    used = rn_dati; 
    int k= 1; 
    char colori[4] = "bgr";

  for (int i = 0; i < rn_dati - k ; i++) {
        if (sfera[i].colore == colori [1]) {
            while (sfera[rn_dati - k].colore == colori [1])
            {
            used--;
            k++;
            
            }
            
            used = elimina( sfera ,rn_dati - k +1 , i); 
            k++;
            
        }
    }

    for (int i = 0; i < used; i++)
    {
        cout << "{ " << sfera[i].diam << " , " << sfera[i].colore << " }" << endl;
    }
    
    return 0; 
}

sfere* define_array_file_sfere ( int& n_dati , string directory) {

    sfere* sfera;
    n_dati =  conta_coppiedati_file (directory); 
    sfera = new sfere [n_dati];

    ifstream data ;
    
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> sfera[k].diam ;
    data >> sfera[k].colore ;   
    }

    data.close () ;
    return sfera;
}

void scambia (sfere valori[] , int pos1, int pos2) {
    sfere appo = valori[pos1];
    valori[pos1] = valori[pos2];
    valori[pos2] = appo;

}


int elimina (sfere valori [], int used, int pos){
    
    scambia (valori, pos, used -1 );

    used--; 

    return used; 
}