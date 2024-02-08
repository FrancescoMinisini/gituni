#include"lib.h"

int conta_pro (my_array_giocatore dati) {
    int conta = 0;
    for (int i = 0; i < dati.used; i++)
    {
     if ( dati.raw[i].is_pro == true ) {
        conta++;
     }
    }
    return conta;
}

int conta_ama (my_array_giocatore dati) {
    int conta = 0;
    for (int i = 0; i < dati.used; i++)
    {
     if ( dati.raw[i].is_pro == false ) {
        conta++;
     }
    }
    return conta;
}

void print_array_giocatore_3 (giocatore* dati , int n , int used) {
    cout  << endl ;
    for (int i = 0; i < n; i++) {
         if ( dati[i].is_pro == true ) {
         cout  <<"{ " << dati[i].cod << " , pro" <<   " } "<< endl;
         }
        else { cout  <<"{ " << dati[i].cod << " , ama" <<   " } "<< endl;}

    }
     cout  << endl ;
     for (int i = used-1 ; i > used - n -1 ; i--) {
                  if ( dati[i].is_pro == true ) {
         cout  <<"{ " << dati[i].cod << " , pro" <<   " } "<< endl;
         }
        else { cout  <<"{ " << dati[i].cod << " , ama" <<   " } "<< endl;}
        }

}

giocatore* inizializza_giocatore (int& n_dati , string directory, int& error_code) {
    giocatore* vettore; 
    ifstream data ;
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
    }
    
int cod; //codice giocatore
bool is_pro; //true per professionista, false per amatore
int tot_punt; //punteggio ottenuto al torneo del Palio di Masnago
int nmani; //mani giocate al torneo del Palio di Masnago

    n_dati = 1 ; 
    data >> cod;
    
    while (!data.eof()) {
        n_dati++ ;
    data >> cod;    }
     data.close () ;

    vettore = new giocatore [n_dati];
    
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
    data >> vettore[k].cod;
    if ( vettore[k].cod <= 1000 and vettore[k].cod >= 1 ) {
    vettore[k].is_pro = true ;
    }
    if ( vettore[k].cod >= 2000 ) {
    vettore[k].is_pro = false ;
    }
    vettore[k].tot_punt = 0;
    vettore[k].nmani = 0;

    }

    data.close () ;

    error_code = 0; 
    return vettore; 
}

mano* inizializza_mano (int& n_dati , string directory, int& error_code) {
    mano* vettore; 
    ifstream data ;
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
    }
    
int cod; //codice giocatore
int punti; //punti mano al torneo del Palio/punti classifica nazionale.

    n_dati = 1 ; 
    data >> cod >> punti;
    
    while (!data.eof()) {
        n_dati++ ;
    data >> cod >> punti;    }
     data.close () ;

    vettore = new mano [n_dati];
    
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
    data >> vettore[k].cod;
    vettore[k].punti;
    }

    data.close () ;

    error_code = 0; 
    return vettore; 
}

