#include "/home/francesco/programmazione/gituni/librerie/random/random.h"
#include<iomanip>


double rileva (double , double , double , double );

int main () {   
    int size = 10;
    ofstream output;

    int n = 100; 
    double x0= 2; 
    double v= 0.3; 
    double u = 0.2;
    double t = 0.0; 
    double y;
    output.open("rilevazioni.dat");
    if (output.fail ()){
        cout << endl << "qualcosa è andato storto";
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        t += 0.2; 
        y = rileva ( t , x0 , v , u);
       
        cout << fixed;
  
        output << endl  << setprecision(4) << t << setw(size) << y ;
    }
    output.close(); 



    return 0; 
}

double rileva (double time , double x0 , double v ,double u) {
    double x; 
    double k; 
    k = rand_gaussiano( 0, 0.4); 
    x = x0 + v*time + k; 


    return x; 
}