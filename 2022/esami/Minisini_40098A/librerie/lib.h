
#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
//#include"librerie/funzioni/funzioni.h"


struct voto {
int cod; //codice esame
int cre; //numero crediti esame
int matr; //matricola studente
int val; //voto conseguito
};

struct studente {
int matr; //matricola studente
int cre; //numero crediti conseguiti
float wm; //media pesata
int nfails; //numero esami falliti
bool is_out; //true: espulso
};


struct my_array_voto {
    int size, used;
    voto* raw;
};

struct my_array_studente {
    int size, used;
    studente * raw;
};
//1
studente* inizializza_studente (int& n_dati , string directory, int& error_code) ;
voto* inizializza_voto (int& n_dati , string directory, int& error_code) ;
int conta_insuf (my_array_voto dati) ;
int conta_suf (my_array_voto dati) ;
void print_array_voto_3 (voto* dati , int n , int used);
//2
int conta_espulso (my_array_studente dati);
int conta_ammesso (my_array_studente dati);
void print_array_studente_fuori (studente* dati , int n ) ;
//3
void remove (my_array_studente dati , int pos) ;
void clean (my_array_studente dati) ;
void merge_sort_studente (studente* data, int init, int final);
void merge_studente (studente* data, int i, int m, int f);
void print_array_studente_3 (studente* dati , int n , int used) ;
//4,5
void update_status ( my_array_studente stud , int& nespulsi) ;
void update_status_studente (my_array_studente studenti ,  my_array_voto voti , int& nespulsi);
void update_media ( studente stud , voto vot) ;
//6

void stampa ( studente* dati , int d );
void stampa_file ( studente* dati, string directory , int d );



