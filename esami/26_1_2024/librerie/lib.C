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

void print_array_mano_3 (mano* dati , int n , int used) {
    cout  << endl ;
    for (int i = 0; i < n; i++) {
         cout  <<"{ " << dati[i].cod << " , " << dati[i].punti << " } "<< endl;
    
    }
     cout  << endl ;
     for (int i = used-1 ; i > used - n -1 ; i--) {
                cout  <<"{ " << dati[i].cod << " , " << dati[i].punti << " } "<< endl;
        }

}

void update_status (my_array_giocatore g , my_array_mano m){
    for (int i = 0; i < g.size; i++)
    {
        for (int k = 0; k < m.size; k++)
        {
            if( g.raw[i].cod == m.raw[k].cod){
                g.raw[i].nmani++;
                g.raw[i].tot_punt = g.raw[i].tot_punt+m.raw[k].punti ;
            }
        }
    }
}

void print_array_giocatore_3_update (giocatore* dati , int n , int used) {
    cout  << endl ;
    for (int i = 0; i < n; i++) {
         if ( dati[i].is_pro == true ) {
        cout  <<"{ " << dati[i].cod << " , pro" << dati[i].nmani << dati[i].tot_punt <<   " } "<< endl;         }
        else { cout  <<"{ " << dati[i].cod << " , ama" << dati[i].nmani << dati[i].tot_punt <<   " } "<< endl;}

    }
     cout  << endl ;
     for (int i = used-1 ; i > used - n -1 ; i--) {
                  if ( dati[i].is_pro == true ) {
        cout  <<"{ " << dati[i].cod << " , pro" << dati[i].nmani << dati[i].tot_punt <<   " } "<< endl;    }
        else { cout  <<"{ " << dati[i].cod << " , ama" << dati[i].nmani << dati[i].tot_punt <<   " } "<< endl;}
        }

}

void merge_giocatore_decr(giocatore* data, int i, int m, int f) {
    int j, k, z;
    giocatore* tmp; 
    tmp = new giocatore[f - i + 1];

    j = i; // indice del primo sottovettore
    k = m + 1; // indice del secondo sottovettore
    z = 0; // indice di tmp

    while (j <= m && k <= f) {
        if (data[j].tot_punt >= data[k].tot_punt) { // Cambiato da <= a >= per l'ordinamento decrescente
            tmp[z] = data[j];
            j++;
        } else {
            tmp[z] = data[k];
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++) {
            tmp[z] = data[k];
            z++;
        }
    } else {
        for (j; j <= m; j++) {
            tmp[z] = data[j];
            z++;
        }
    }

    // ricopia tmp in data
    z = 0;
    for (z; z < f - i + 1; z++) {
        data[i + z] = tmp[z];
    }

    delete[] tmp;
    tmp = NULL;
}

void merge_sort_decr_giocatore (giocatore* data, int i, int f) {
    if (i < f) {
        int m = i + (f - i) / 2;

        merge_sort_decr_giocatore(data, i, m);
        merge_sort_decr_giocatore(data, m + 1, f);

        merge_giocatore_decr(data, i, m, f);
    }
}

void stampa_giocatore ( giocatore* dati , int d ){
    cout  << endl ;
    for (int i = 0; i < d; i++) {
         if ( dati[i].is_pro == true ) {
        cout  <<"{ " << dati[i].cod << " , pro" << dati[i].nmani << dati[i].tot_punt <<   " } "<< endl;         }
        else { cout  <<"{ " << dati[i].cod << " , ama" << dati[i].nmani << dati[i].tot_punt <<   " } "<< endl;}
    }
}

void update_status_classifica (my_array_mano classifica ,  my_array_giocatore g){
    for (int i = 0; i < classifica.size; i++)
    {
        for (int k = 0; k < g.size; k++)
        {
            if( classifica.raw[i].cod == g.raw[k].cod and g.raw[k].nmani > 5 ){
                
                classifica.raw[i].punti = g.raw[i].tot_punt + classifica.raw[i].punti ;
            }
        }
    }
}

void merge_classifica_decr(mano* data, int i, int m, int f) {
    int j, k, z;
    mano* tmp; 
    tmp = new mano[f - i + 1];

    j = i; // indice del primo sottovettore
    k = m + 1; // indice del secondo sottovettore
    z = 0; // indice di tmp

    while (j <= m && k <= f) {
        if (data[j].punti >= data[k].punti) { // Cambiato da <= a >= per l'ordinamento decrescente
            tmp[z] = data[j];
            j++;
        } else {
            tmp[z] = data[k];
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++) {
            tmp[z] = data[k];
            z++;
        }
    } else {
        for (j; j <= m; j++) {
            tmp[z] = data[j];
            z++;
        }
    }

    // ricopia tmp in data
    z = 0;
    for (z; z < f - i + 1; z++) {
        data[i + z] = tmp[z];
    }

    delete[] tmp;
    tmp = NULL;
}

void merge_sort_decr_classifica (mano* data, int i, int f) {
    if (i < f) {
        int m = i + (f - i) / 2;

        merge_sort_decr_classifica(data, i, m);
        merge_sort_decr_classifica(data, m + 1, f);

        merge_classifica_decr(data, i, m, f);
    }
}

void stampa_classifica (mano* dati , int d ){
    cout  << endl ;
    for (int i = 0; i < d; i++) {
        cout  <<"posizione: "<< i+1 << " partecipante : " << dati[i].cod <<  " con punteggio: "<< dati[i].punti << endl;         }
    } 




