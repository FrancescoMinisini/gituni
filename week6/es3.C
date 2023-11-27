#include <iostream> 
#include <fstream>
#include <cstring>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
using namespace std;
int conta_coppiedati_file (string);

int main () {
    int red = 0 , k = 0, n_dati;
    char colori[5]= "bgr"; 
    double*  vdiams, *vdiams_red;
    char*  vcols;
    vcols = new char[n_dati]; 
    vdiams= new double[n_dati] ; 
    vdiams_red = new double[red]; 


    ifstream data ;
   /*string directory = "/home/studenti/francescogiuseppe.minisini/Informatica/LabInfo_2023_24/Lab06/sfere.dat" ;*/
    string directory = "/home/francesco/programmazione/LabInfo_2023_24/Lab06/sfere.dat" ;
    
    n_dati = conta_coppiedati_file (directory);

    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        return -1 ;
    } 

    for (int k = 0 ; k<n_dati ; k++){
    data >> vdiams[k];
    data >> vcols[k];
    }

    data.close () ;

 for (int i = 0; i < n_dati; i++) {
        char appo = vcols[i];
        if (appo == colori[2]) {
            red++;
            vdiams_red[red] = vdiams[i];
        }
    }

    delete[] vdiams;
    delete[] vdiams_red;
    return 0 ;
}


