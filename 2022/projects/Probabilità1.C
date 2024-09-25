#include <iostream>
using namespace std;

int main(){
    float eventi [5] = { 26, 27 , 28 , 29 , 30 };
    float frequenza [5] = { 46, 38 ,30 , 36 , 50 };
    float frequenza_rel = 0 ; 
    double Media ; 
    float tot_eventi = 0 ;
    int i = 0 ; 
    int k = 0 ;
    
    while (k < 5) {
        tot_eventi = frequenza [k] + tot_eventi ;
        k++ ;
    }
    
    
    while (i < 5) {
        frequenza_rel= eventi [i] * frequenza [i] +frequenza_rel ;
        i++ ; 
    }
   
    Media = frequenza_rel / tot_eventi ;

    cout << endl << Media << endl << endl ;
    
    return 0;
}
