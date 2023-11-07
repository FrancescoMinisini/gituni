#include <iostream> 
#include <fstream>
#include <string>
using namespace std;
int conta_coppiedati_file (string);

int main () {
    int k = 0 ;
    int n_dati ;
    ifstream data ;
    string directory = "/home/studenti/francescogiuseppe.minisini/Informatica/LabInfo_2023_24/Lab06/sfere.dat" ;
    
    
    n_dati = conta_coppiedati_file (directory);


    float  vdiams[n_dati];
    char  vcols[n_dati];
    

    data.open("/home/studenti/francescogiuseppe.minisini/Informatica/LabInfo_2023_24/Lab06/sfere.dat") ;
    
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        return -1 ;
    } 

    for (int k = 0 ; k<n_dati ; k++){
    data >> vdiams[k];
    data >> vcols[k];
    }

    data.close () ;
    return 0 ;
}


int conta_coppiedati_file (string directory){
    float dato ;
    char colore ;
    int n_dati = 0 ;
    ifstream data ;

    data.open(directory) ;
    
    if (data.fail() ) {
        cout << "failed to read file" << endl ;
        return -1 ;
    } 
    
    data >> dato;
    data >> colore ;
    while (!data.eof()) {
        n_dati++ ;
        data >> dato ;
        data >> colore ;
    }
    data.close () ;
    return n_dati;

}


