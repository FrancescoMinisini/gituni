#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
#include"Models\Vettore"

int main(int argc, char** kargs){
if (argc < 3) {
    cout << "\nToo few parameters executing file: " << kargs[0];
    return 1; // Exit if there are not enough arguments
}

    string filePath = kargs[1];
    ifstream data (filePath);
if (!data) {
    cout << "\ncannot open file: " << filePath;
    return 1; // Exit if the file cannot be opened
}

    double media = 0;
    int count = 0;
    int upperBound = stoi(kargs[2]);
    double temp = 0; 
    while ( !data.eof() && count < upperBound){
        data>> temp;
        media += temp/(double)upperBound;
        count++;
    }
    cout<< "Result: "<<  media <<"\n";

    
    return 0;
}
