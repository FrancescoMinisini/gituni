#include<iostream> 
#include <fstream>
using namespace std ;

int main () {
    int i = 0 ;
    float appo ;
    ofstream output ;
    ifstream data ;
    data.open("/home/studenti/francescogiuseppe.minisini/Informatica/File_professore/LabInfo_2023_24/Lab05/dati_short.dat") ;
    output.open("copy_data") ;
    
    if (data.fail() or output.fail()) {
        cout << "failed to read file" << endl ;
        return -1 ;
    } 
    data >> appo;
    output << appo << endl;
    while (!data.eof()) {
        i++ ;
        data >> appo ;
        output << appo << endl;
    }
    data.close () ;
    output.close () ;
    return 0 ;
}