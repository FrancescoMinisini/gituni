#include<iostream>
#include<cstring>

using namespace std; 

int main () {
    char a[100] ; 
    char b[] = "maggie" ;
    char d[] = "MAGGIE" ;
    char c[] = "Maggie" ;
    cout << "chi è la ragazza più bella del mondo?????" << endl ; 
    
    cin.getline(a, sizeof(a)); 
    
    int res1 = strcmp (a , b) ; 
    int res2 = strcmp (a , c) ; 
    int res3 = strcmp (a , d) ; 

    if (res1 != 0 and res2 != 0 and res3 != 0) {
   
    do {
        cout << "no! ritenta" << endl ;
        cin.getline(a, sizeof(a)); 
        res1 = strcmp (a , b) ; 
        res2 = strcmp (a , c) ; 
        res3 = strcmp (a , d) ; 
    } while (res1 != 0 and res2 != 0 and res3 != 0) ; 
    }

    cout << "bravoooooo"<< endl ;
    return 0;
}