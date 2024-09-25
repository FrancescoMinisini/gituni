#include <iostream>

using namespace std;


float leggiValore(float,float);

int main(){

    float massimo,minimo;

    int a,b;
    int val;




    cout << endl <<  "Inserire valori: " << endl;

    
   cin >> a >> b;
   

    cout << endl <<  "Valori inseriti: " << a << b <<  endl;

    
    if( a<b ){ 

       minimo = a;
       massimo =  b;

     }
    else{ 
       minimo = b;
       massimo =  a;

    }
   

    cout << endl << "Range definito: [" << minimo <<"..." << massimo <<"]" << endl;

 



   val = leggiValore(minimo,massimo);
  
  
  
    cout << endl <<"Valore valido letto! " << val << endl;
    return 0;
}


float leggiValore(float min,float max){
   
   int value;

   do{
      cout << endl << "inserire valore compreso tra" << min << " e " << max<< endl;
      cin >> value;
   }while(value<min or value >max);

   return value;

}
