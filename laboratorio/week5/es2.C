#include <iostream> 
#include <fstream>
#include <cstring>
#include "/home/francesco/programmazione/gituni/librerie/funzioni/funzioni.h"
using namespace std;
int conta_coppiedati_file (string);

int main () {
    int k = 0 ;
    int n_dati ;
    int red = 0 ;
    int green = 0 ;
    int blue = 0 ;
    double m_b , m_r , m_g;
    double std_b , std_g ,std_r ;
    char colori[5]= "bgr"; 
    ifstream data ;
   /*string directory = "/home/studenti/francescogiuseppe.minisini/Informatica/LabInfo_2023_24/Lab06/sfere.dat" ;*/
    string directory = "/home/francesco/programmazione/LabInfo_2023_24/Lab06/sfere.dat" ;
    
    n_dati = conta_coppiedati_file (directory);


    double  vdiams[n_dati];
    char  vcols[n_dati];
    double vdiams_red [n_dati]; 
    double vdiams_green [n_dati];
    double vdiams_blue [n_dati];

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

        if (appo == colori[0]) {
            vdiams_blue[blue] = vdiams[i];
            blue++;
        } else if (appo == colori[1]) {
            vdiams_green[green] = vdiams[i];
            green++;
        } else if (appo == colori[2]) {
            vdiams_red[red] = vdiams[i];
            red++;
        } else {cout << "c'è un problema" << endl;
        }
    }

    m_b = media_array_double (vdiams_blue , blue);
    m_r = media_array_double (vdiams_red , red) ; 
    m_g = media_array_double (vdiams_green , green) ; 
    std_b = stnd_double (vdiams_blue, blue, m_b);
    std_g = stnd_double (vdiams_green, green, m_g);
    std_r = stnd_double (vdiams_red, red, m_r);
   
    cout << endl << "media diametro palline blu: " << m_b << endl ;
    cout << "con deviazione standard: "<< std_b << endl ;
    cout << endl << "media diametro palline verdi: " << m_g <<endl ;
    cout << "con deviazione standard: "<< std_g << endl ;
    cout << endl << "media diametro palline rosse: " << m_r <<endl ;
    cout << "con deviazione standard: "<< std_r << endl ;

    return 0 ;
}


