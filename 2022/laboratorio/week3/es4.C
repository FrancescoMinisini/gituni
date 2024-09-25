#include <iostream>

using namespace std;


int leggiValore(int,int);

int main(){
   int max = 30 ;
   int min = 18 ;
   int scores [10] ;
   int i = 0 ; 
   int data ;
   while (i < 10 ) {
        leggiValore (min , max);
   
    scores [i] = data ;
    i++ ;
   }

 cout << endl << "[ " ;
    for (int k = 0 ; k<i ; k++) { 
        cout << " " << scores [k] << " ";
    }
    cout << " ]" << endl << endl ;
    return 0 ;

}

   int leggiValore(int min,int max){
   
   int value;

   do{
      cout << endl << "inserire valore compreso tra" << min << " e " << max<< endl;
      cin >> value;
   }while(value >= min and value <= max);
   
   return value;

}