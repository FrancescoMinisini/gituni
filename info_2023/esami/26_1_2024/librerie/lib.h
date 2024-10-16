
#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
//#include"librerie/funzioni/funzioni.h"

struct giocatore {
int cod; //codice giocatore
bool is_pro; //true per professionista, false per amatore
int tot_punt; //punteggio ottenuto al torneo del Palio di Masnago
int nmani; //mani giocate al torneo del Palio di Masnago
};

struct mano {
int cod; //codice giocatore
int punti; //punti mano al torneo del Palio/punti classifica nazionale.
};

struct my_array_giocatore {
    int size, used;
    giocatore* raw;
};

struct my_array_mano {
    int size, used;
    mano* raw;
};


giocatore* inizializza_giocatore (int& n_dati , string directory, int& error_code) ;
mano* inizializza_mano (int& n_dati , string directory, int& error_code);
int conta_pro (my_array_giocatore dati) ;
int conta_ama (my_array_giocatore dati) ;
void print_array_giocatore_3 (giocatore* dati , int n , int used) ;

void print_array_mano_3 (mano* dati , int n , int used) ;
void update_status (my_array_giocatore g , my_array_mano m);
void print_array_giocatore_3_update (giocatore* dati , int n , int used);


void merge_giocatore_decr(giocatore* data, int i, int m, int f);
void merge_sort_decr_giocatore (giocatore* data, int i, int f);
void stampa_giocatore ( giocatore* dati , int d );

void update_status_classifica (my_array_mano classifica ,  my_array_giocatore g);

void merge_sort_decr_classifica (mano* data, int i, int f) ;
void merge_classifica_decr(mano* data, int i, int m, int f) ;
void stampa_classifica (mano* dati , int d );