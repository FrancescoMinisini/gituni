# include <iostream>
using namespace std;
int main (){
    int a;
    
    cout << endl <<  "inserire numero: " ; 
    cin >> a;

    int b = a+1;
    int c = a-1;
    cout << endl << "numero successivo: "<< b << endl ;
    cout << endl << "numero precedente: "<< c << endl ;
    return 0;
}