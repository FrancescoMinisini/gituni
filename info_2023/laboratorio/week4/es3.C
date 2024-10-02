#include<iostream> 
#include <fstream>
using namespace std ;

int main () {
    int i = 0 ;
    float appo ;
    
    ifstream data ;
    data.open("/home/studenti/francescogiuseppe.minisini/Informatica/LabInfo_2023_24/Lab05/dati_short.dat") ;
    
    data >> appo;
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        return -1 ;
    }
   
    while (!data.eof()) {
        i++ ;
        data >> appo ;
    }
    cout << i << endl ;
    return 0 ;
}