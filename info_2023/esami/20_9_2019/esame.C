#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
#include"librerie/funzioni/funzioni.h"

struct ione {
float x; // coordinata x dello ione
float y; // coordinata y dello ione
float r; // raggio dello ione
int carica; //carica dello ione
};

struct elettrone {
float x; // coord. x dell’elettrone
float y; // coord. y dell’elettrone
float vx;// comp. x velocita‘
float vy; // comp. y velocita‘
bool free; // e‘ libero?
};

struct forza {
    float x , y ; 
};

ione* inizializza_ioni (int& n_dati , string directory, int& error_code);
void stampa_ioni ( ione* dati , int d );


void print_array_elettroni (elettrone* dati , int n , int used);
elettrone* inizializza_elettrone (int& n_dati , string directory, int& error_code);

int gotcha(elettrone *el, ione ions[], int nions) ;
float distance (ione* io , elettrone* el);

void is_gotcha (elettrone* el , int n_el , ione* ion , int n_ion) ;
void stampa_captured ( elettrone* dati , int n_dati);
void stampa_elettroni ( elettrone* dati , int d );
int conta_free ( elettrone* dati , int n_dati);

forza forza_elettrostatica ( elettrone* el , int n_el , ione* ion , int n_ion , int campione);
forza* inizzializza_forza_elettrostatica (  elettrone* el , int n_el , ione* ion , int n_ion );
void velocita (elettrone& el , forza f );
void pos (elettrone& el , forza f );
void update_state (elettrone* el , int n_el , ione* ion , int n_ion , forza* f );


int main(){
    int n_ioni = 0, error_code = 0 , n_elettroni= 0  ; 
    string directory_ioni = "ioni.dat";
    string directory_elettroni = "elettroni.dat";
    ione* dati_ioni; 
    elettrone* dati_elettroni;
    forza* dati_forze;
    
    //1
    dati_ioni = inizializza_ioni ( n_ioni , directory_ioni , error_code);
    //cout << n_ioni ; 
    //stampa_ioni ( dati_ioni , n_ioni ); 
    //2
    dati_elettroni = inizializza_elettrone ( n_elettroni , directory_elettroni , error_code); 
    //print_array_elettroni ( dati_elettroni , 5 , n_elettroni);
    //3
    is_gotcha ( dati_elettroni , n_elettroni ,  dati_ioni , n_ioni);
    //stampa_captured ( dati_elettroni , n_elettroni);
    //cout << endl << conta_free (dati_elettroni , n_elettroni) << endl;
    //stampa_elettroni( dati_elettroni , n_elettroni);
    //4
    dati_forze = inizzializza_forza_elettrostatica (dati_elettroni , n_elettroni ,  dati_ioni , n_ioni);
    update_state (dati_elettroni , n_elettroni ,  dati_ioni , n_ioni, dati_forze );
    is_gotcha ( dati_elettroni , n_elettroni ,  dati_ioni , n_ioni);
    cout << conta_free ( dati_elettroni , n_elettroni);
    stampa_elettroni( dati_elettroni , n_elettroni);
    /*for (int i = 0; i < n_elettroni; i++)
    {
       cout << dati_forze[i].x << " " <<dati_forze[i].y << endl;
    }
    */

    

    return 0;
}


ione* inizializza_ioni (int& n_dati , string directory, int& error_code) {
    ione* vettore; 
    ifstream data ;
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
    }
    
    float x; // coordinata x dello ione
    float y; // coordinata y dello ione
    float r; // raggio dello ione
    int carica; //carica dello ione

    n_dati = 1 ; 
    data >> x >> y >> r >> carica ;
    
    while (!data.eof()) {
        n_dati++ ;
        data >> x >> y >> r >> carica ;    }
     data.close () ;

    vettore = new ione [n_dati];
    
    if (vettore == NULL) {
        error_code= -2;
        return vettore;
    }
    
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
        error_code = -1; 
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> vettore[k].x;
    data >> vettore[k].y;
    data >> vettore[k].r;
    data >> vettore[k].carica;
    }

    data.close () ;

    error_code = 0; 
    return vettore; 
}

void stampa_ioni ( ione* dati , int d ){

    for (int i = 0; i < d; i++)
    {
        cout  << "{ " << dati[i].x << " , " <<dati[i].y << " , " <<dati[i].r <<  " , " << dati[i].carica << " } "<< endl;
    }
}

elettrone* inizializza_elettrone (int& n_dati , string directory, int& error_code) {
    elettrone* vettore; 
    ifstream data ;
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
    }
    
    float x; // coord. x dell’elettrone
    float y; // coord. y dell’elettrone
    float vx;// comp. x velocita‘
    float vy; // comp. y velocita‘
    bool free; // e‘ libero?

    n_dati = 1 ; 
    data >> x >> y ;
    
    while (!data.eof()) {
        n_dati++ ;
        data >> x >> y ;    }
     data.close () ;

    vettore = new elettrone [n_dati];
    
    if (vettore == NULL) {
        error_code= -2;
        return vettore;
    }
    
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
        error_code = -1; 
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> vettore[k].x;
    data >> vettore[k].y;
    //data >> vettore[k].r;
    //data >> vettore[k].carica;
    vettore[k].vx = 0 ;
    vettore[k].vy = 0 ; 
    vettore[k].free = true ;  
    }

    data.close () ;

    error_code = 0; 
    return vettore; 
}

void print_array_elettroni (elettrone* dati , int n , int used) {

    for (int i = 0; i < n; i++) {
         cout  << "{ " << dati[i].x << " , " <<dati[i].y << " , " <<dati[i].vx << " , " <<dati[i].vy << " , " <<dati[i].free <<  " } "<< endl;
    }
    /* for (int i = used-1 ; i > used - n -1 ; i--) {
         cout  << "{ " << dati[i].time << " , " <<dati[i].db << " , " <<dati[i].dato <<  " } "<< endl;
    }*/
}

int gotcha(elettrone *el, ione ions[], int n_ioni) {
    int result = 0;
    for (int i = 0; i < n_ioni; i++)
    {
        if (distance( &ions [i] , el) < ions[i].r ) {
            el->free = false ;
            ions[i].carica--;
            result = 1; 
            //cout << endl << distance( &ions [i] , el);
        }
        //cout << endl << distance( &ions [i] , el);
    }
    return result ; 
    
}

float distance (ione* io , elettrone* el) {
    return sqrt ( pow( io->x - el->x , 2) + pow(io->y - el->y , 2));
}

void is_gotcha (elettrone* el , int n_el , ione* ion , int n_ion) {
    for (int i = 0; i < n_el; i++)
    {
        gotcha ( &el[i] , ion , n_ion);
    }
}

void stampa_captured ( elettrone* dati , int n_dati){
    for (int i = 0; i < n_dati; i++)
    {
        if (dati[i].free == false){
         cout  << "{ " << dati[i].x << " , " <<dati[i].y << " , " <<dati[i].vx << " , " <<dati[i].vy << " , " <<dati[i].free <<  " } "<< endl;
            }
    }
    
}

int conta_free ( elettrone* dati , int n_dati) {
    int res = 0 ; 
    for (int i = 0; i < n_dati; i++)
    {
       if ( dati[i].free == true ) {
        res++;
       }
    }
    return res;
}

void stampa_elettroni ( elettrone* dati , int d ){

    for (int i = 0; i < d; i++)
    {
         cout  << "{ " << dati[i].x << " , " <<dati[i].y << " , " <<dati[i].vx << " , " <<dati[i].vy << " , " <<dati[i].free <<  " } "<< endl;
    }
}

forza forza_elettrostatica ( elettrone* el , int n_el , ione* ion , int n_ion , int campione) {
    forza f ; 
    f.x = 0 ; 
    f.y = 0 ;
    float dx , dy ;
    for (int i = 0; i < n_el ; i++)
    {  if ( !(i == campione))
    {   dx  = el[campione].x - el[i].x ;
        dy  = el[campione].y - el[i].y; 
        
        f.x = f.x + dx/pow ( sqrt ( pow( dx , 2) + pow(dy , 2)) , 3 ); 
        f.y = f.y + dy/pow ( sqrt ( pow( dx, 2) + pow(dy , 2)), 3 ); 
    }
    }
    for (int i = 0; i < n_ion ; i++)
    {  dx  = el[campione].x - ion[i].x ;
        dy  = el[campione].y - ion[i].y;
    
        f.x = f.x - (float)ion[i].carica*dx /pow ( sqrt ( pow( dx , 2) + pow(dy , 2)) , 3 ); 
        f.y = f.y - (float)ion[i].carica*dy /pow ( sqrt ( pow( dx, 2) + pow(dy , 2)), 3 );
        //cout << f.x << endl << f.y << endl;
    }
    return f;

}

forza* inizzializza_forza_elettrostatica (  elettrone* el , int n_el , ione* ion , int n_ion ) {
    forza* forze ; 
    forze = new forza [n_el];
    for (int i = 0; i < n_el; i++)
    {   if (el[i].free == true){
        forze[i]=forza_elettrostatica ( el , n_el , ion , n_ion , i);
        //cout << forze[i].x << " " << forze[i].y<< endl;
    } else {forze[i].x = 0;
    forze[i].y = 0;}}
    return forze;
}

void velocita (elettrone& el , forza f ) {
    el.vx = el.vx + f.x*0.5;
    el.vy = el.vy + f.y*0.5;
}

void pos (elettrone& el , forza f ) {
    el.x = el.x + el.vx*0.5 +f.x*pow(0.5,3);
    el.y = el.y + el.vy*0.5 +f.y*pow(0.5,3);
    //cout << el.vx*0.5 +f.x*pow(0.5,2)/2 <<" " <<  el.vy*0.5 +f.y*pow(0.5,2)/2 << endl;
}

void update_state (elettrone* el , int n_el , ione* ion , int n_ion , forza* f ) {
    for (int i = 0; i < n_el; i++)
    { if (el[i].free == true){
        pos ( el[i], f[i]);
        velocita (el[i], f[i] );
    }
    }
    
}



