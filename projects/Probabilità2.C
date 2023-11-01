#include <iostream>
using namespace std;

int main(){
   
    int n_risultati ;
    float eventi [n_risultati] ;
    float frequenza [n_risultati] ;
    float frequenza_rel = 0 ; 
    double Media ; 
    float tot_eventi = 0 ;
    int i,k,j = 0 ; 
    
    cout << "Scrivi il mumero di risultati possibili: " ;
    
    cin >> n_risultati ;
    
    for (j = 0 ; j < n_risultati; j++ ) {
        cout << "Inserisci il valore dell'evento " << j+1 << ": " ;
        cin >> eventi [j];
        cout << "Inserisci la frequenza del valore dell'evento " << j+1 << ": " ;
        cin >> frequenza [j] ; 

            tot_eventi = frequenza [j] + tot_eventi ;
            
            frequenza_rel= eventi [j] * frequenza [j] +frequenza_rel ;
 
    }
    
   
    Media = frequenza_rel / tot_eventi ;

    cout << endl << Media << endl << endl ;
    
    return 0 ;
}
