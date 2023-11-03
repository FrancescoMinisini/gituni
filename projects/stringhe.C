#include<iostream>
#include<cstring>
using namespace std ; 

int main () {
    string s = "hello world";
    string t = "ciao mondo" ; 
    string d = s + " " + t;
    
    char g [1] ; 

    g [0] = s.at(3) ; 
    
    cout << g[0] << endl;

    return 0 ; 
}