#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
#include"librerie/funzioni/funzioni.h"

struct bersaglio {
float x,y; // coordinate bersaglio
float c; // capacita‘ di corazza
bool distr; // stato (distrutto o meno)
};

struct colpo {
float theta,phi; // alzo e angolo di tiro
float xf,yf; // coordinate impatto
bool hit; // a segno
};

bersaglio* inizializza_bersagli (int& n_dati , string directory, int& error_code);
int conta_distrutti ( bersaglio* dati , int n_dati) ;
int conta_nondistrutti ( bersaglio* dati , int n_dati);
void print_3bersagli_dis ( bersaglio* dati, int n , int n_dati);
void print_3bersagli_nondis ( bersaglio* dati, int n , int n_dati) ;

colpo* inizializza_colpo (int& n_dati , string directory, int& error_code);
void print_array_colpo (colpo* dati , int n , int n_colpo);

void controllo (bersaglio* dati_bersaglio , int n_bersaglio , colpo* dati_colpo , int n_colpo , int& n_colpi_segno , float& danno);
float d ( float xi , float yi , float xf , float yf);
float danno ( float corazza , float d) ;

void print_bersagli_dis ( bersaglio* dati, int n_dati);

int main () {
    bersaglio* dati_bersaglio;
    colpo* dati_colpo;
    string directory1 = "bersagli.dat", directory2 = "alzo_angolo.dat" , directory3 = "results.dat";
    int n_bersaglio  = 0 ,  n_distrutti = 0 , n_nondistrutti =0 , error_code = 0 , n_colpo = 0, n_distrutti1 =0 , n_colpi_segno = 0;
    float danno = 0;

   

//1
    dati_bersaglio = inizializza_bersagli ( n_bersaglio, directory1 , error_code );
    n_distrutti1 = conta_distrutti(dati_bersaglio , n_bersaglio);
    n_nondistrutti = conta_nondistrutti ( dati_bersaglio, n_bersaglio);
    cout << endl << "il numero di bersagli caricati è : " << n_bersaglio << endl << " il numero di bersagli distrutti è : " << n_distrutti << endl << " il numero di bersagli non distrutti è : " << n_nondistrutti << endl ; 
    print_3bersagli_nondis ( dati_bersaglio,  3 ,  n_bersaglio) ;
    print_3bersagli_dis ( dati_bersaglio,  3 ,  n_bersaglio);
//2
    dati_colpo = inizializza_colpo ( n_colpo ,  directory2, error_code);
    cout << endl << "il numero di colpi sparati è : "<< n_colpo << endl ; 
   print_array_colpo ( dati_colpo , 3 ,  n_colpo);
//3 
    controllo ( dati_bersaglio ,  n_bersaglio ,  dati_colpo ,  n_colpo , n_colpi_segno , danno);
//4
    n_distrutti =  conta_distrutti( dati_bersaglio , n_bersaglio);
    cout<< endl << " il numero di bersagli distrutti è :" << n_distrutti - n_distrutti1<< endl; 
    cout << endl << " la quantità di danno totale è : " << danno << endl; 
    cout << endl << " il totale di colpi a segno è : " << n_colpi_segno << endl; 
//5 
//    cout << dati_bersaglio << endl << dati_colpo<< endl;
    delete [] dati_bersaglio;
    //delete [] dati_colpo;
    return 0;
}


void print_3bersagli_dis ( bersaglio* dati, int n , int n_dati)  {
    int i = 0; 
    int k = 0 ; 
        do {
            if ( dati[i].distr == true) {
         cout << "{ " << dati[i].x << " , " <<dati[i].y << " }      " << dati[i].c<< "    " << dati[i].distr<< " ; " << endl;
         k++;
         i++;
            } else { i++ ; }
    } while ( k < n and i < n_dati);

    
}

void print_3bersagli_nondis ( bersaglio* dati, int n , int n_dati)  {
    int i = 0; 
    int k = 0 ; 
        do {
            if ( dati[i].distr == false) {
         cout << "{ " << dati[i].x << " , " <<dati[i].y << " }      " << dati[i].c<< "    " << dati[i].distr<< " ; " << endl;
         k++;
         i++;
            } else { i++ ; }
    } while ( k < n and i< n_dati);

    
}

bersaglio* inizializza_bersagli (int& n_dati , string directory, int& error_code) {
    bersaglio* vettore; 
     
    int j; 
    j = conta_dati_file (directory);
    n_dati = j /3; 
    if ( !(j%3 == 0) ) {
        cout << "il numero di dati non è divisiblile per 2" << endl ;
    }

    vettore = new bersaglio [n_dati];
    if (vettore == NULL) {
        error_code= -2;
        return vettore;
    }
    ifstream data ;
    
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
        error_code = -1; 
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> vettore[k].x;
    data >> vettore[k].y;
    data >> vettore[k].c;
    if (vettore[k].c < 0) {
        vettore[k].distr = true;
    } else {
         vettore[k].distr = false;
    }
    }

    data.close () ;

    
    error_code = 0; 
    return vettore; 
}

int conta_distrutti ( bersaglio* dati , int n_dati) {
    int res = 0 ; 
    for (int i = 0 ; i < n_dati  ; i++)   {
        if ( dati[i].distr == true){
        res++ ;}
    }  

    return res ; 
}

int conta_nondistrutti ( bersaglio* dati , int n_dati) {

    int res = 0 ; 
    for (int i = 0 ; i < n_dati  ; i++)   {
        if ( dati[i].distr == true)
        res++ ;
    }  
    
    return res ; 
}



colpo* inizializza_colpo (int& n_dati , string directory, int& error_code) {
    colpo* vettore;
    float G; 
     
    int j; 
    j = conta_dati_file (directory);
    n_dati = j /2; 
    if ( !(j%2 == 0) ) {
        cout << "il numero di dati non è divisiblile per 2" << endl ;
    }

    vettore = new colpo [n_dati];
    if (vettore == NULL) {
        error_code= -2;
        return vettore;
    }
    ifstream data ;
    
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
        error_code = -1; 
    } 

    for (int i = 0 ; i< j ; i++){
    data >> vettore[i].theta;
    data >> vettore[i].phi;
    G =  10000*sin( 2*vettore[i].theta) / 9.81 ; 
    vettore[i].xf = G*cos(vettore[i].phi);
    vettore[i].yf = G*sin(vettore[i].phi);
    vettore[i].hit = false; 
    }

    data.close () ;

    error_code = 0; 


    return vettore; 
}

void print_array_colpo (colpo* dati , int n , int n_colpo) {

    for (int i = 0; i < n; i++) {
         cout << "{ " << dati[i].theta << " , " <<dati[i].phi << " }        ";
          cout << "{ " << dati[i].xf << " , " <<dati[i].yf << " }       " << dati[i].hit << endl;
    }
     for (int i = n_colpo-1 ; i > n_colpo - n -1 ; i--) {
         cout << "{ " << dati[i].theta << " , " <<dati[i].phi << " }        ";
          cout << "{ " << dati[i].xf << " , " <<dati[i].yf << " }       " << dati[i].hit << endl;
    }

}



void controllo (bersaglio* dati_bersaglio , int n_bersaglio , colpo* dati_colpo , int n_colpo , int& n_colpi_segno , float& danno_tot) {
    float condizione = 0 ; 
    for (int i = 0; i < n_bersaglio ; i++)
    {
        
            for (int k = 0; k < n_colpo; k++)
        {   condizione = d (dati_bersaglio[i].x , dati_bersaglio[i].y , dati_colpo[k].xf , dati_colpo[k].yf );
            //cout << endl << condizione;
            if ( condizione  < 10) {
                dati_colpo[k].hit = true ; 
                dati_bersaglio[i].c = danno( dati_bersaglio[i].c , condizione);
                n_colpi_segno++;
                danno_tot = danno_tot - danno ( dati_bersaglio[i].c , condizione) + dati_bersaglio[i].c;
                //cout << dati_bersaglio[i].c << endl;
            }

        }
        //cout << endl << i;
         if ( dati_bersaglio[i].c <= 0) {
                    dati_bersaglio[i].distr = true ;
                    
                }
                
    }
    
}

float d ( float xi , float yi , float xf , float yf) {

float res = sqrt ( powf32((xi - xf) , 2) + powf32((yi - yf) , 2));

return res ; 
}

float danno ( float corazza , float d) {
    float res = 0;

    res = corazza - 2*(1-(d/10)) ;
    
    return res;

}


void print_bersagli_dis ( bersaglio* dati, int n_dati)  {
    int i = 0; 
        for (int i = 0; i < n_dati; i++)
        {
             if ( dati[i].distr == true) {
         cout << "{ " << dati[i].x << " , " <<dati[i].y << " }      " << dati[i].c<< "    " << dati[i].distr<< " ; " << endl;
        }
}
}


