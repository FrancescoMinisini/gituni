#include"lib.h"


voto* inizializza_voto (int& n_dati , string directory, int& error_code) {
    voto* vettore; 
    ifstream data ;
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
    }
    int cod; //codice esame
    int cre; //numero crediti esame
    int matr; //matricola studente
    int val; //voto conseguito
    n_dati = 0 ; 
    data >> cod >> cre >> matr >> val ;
    
    while (!data.eof()) {
        n_dati++ ;
    data >> cod >> cre >> matr >> val ;
    }
     data.close () ;

    vettore = new voto [n_dati];
    
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
    data >> vettore[k].cre;
    data >> vettore[k].matr;
    data >> vettore[k].val;
    }

    data.close () ;

    error_code = 0; 
    return vettore; 
}


studente* inizializza_studente (int& n_dati , string directory, int& error_code) {
    studente* vettore; 
    ifstream data ;
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
    }
int matr; //matricola studente
int cre; //numero crediti conseguiti
float wm; //media pesata
int nfails; //numero esami falliti
bool is_out; //true: espulso

    n_dati = 0 ; 
    data >> matr >> cre >> wm >> nfails ;
    
    while (!data.eof()) {
        n_dati++ ;
    data >> matr >> cre >> wm >> nfails ;
    }
     data.close () ;

    vettore = new studente [n_dati];
    
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
    data >> vettore[k].matr;
    data >> vettore[k].cre;
    data >> vettore[k].wm;
    data >> vettore[k].nfails;
    if ( vettore[k].nfails >= 5) {
        vettore[k].is_out = true ;
    }
    else {        
        vettore[k].is_out = false ;
    }
    }

    data.close () ;

    error_code = 0; 
    return vettore; 
}


int conta_suf (my_array_voto dati) {
    int conta = 0;
    for (int i = 0; i < dati.used; i++)
    {
     if ( dati.raw[i].val >= 18) {
        conta++;
     }
    }
    return conta;
}

int conta_insuf (my_array_voto dati) {
    int conta = 0;
    for (int i = 0; i < dati.used; i++)
    {
     if ( dati.raw[i].val < 18) {
        conta++;
     }
    }
    return conta;
}

void print_array_voto_3 (voto* dati , int n , int used) {

    cout  << endl ;
    for (int i = 0; i < n; i++) {
        
        cout  <<"Codice: " << dati[i].cod << " , crediti: " << dati[i].cre << " , numero matricola: " << dati[i].matr << " , voto: " << dati[i].val << endl;         
        }
    
     cout  << endl ;
     for (int i = used-1 ; i > used - n -1 ; i--) {

        cout  <<"Codice: " << dati[i].cod << " , crediti: " << dati[i].cre << " , numero matricola: " << dati[i].matr << " , voto: " << dati[i].val << endl;         
        }

}


int conta_espulso (my_array_studente dati) {
    int conta = 0;
    for (int i = 0; i < dati.used; i++)
    {
     if ( dati.raw[i].is_out == true ) {
        conta++;
     }
    }
    return conta;
}


int conta_ammesso (my_array_studente dati) {
    int conta = 0;
    for (int i = 0; i < dati.used; i++)
    {
     if ( dati.raw[i].is_out == false ) {
        conta++;
     }
    }
    return conta;
}

void print_array_studente_fuori (studente* dati , int n ) {
    cout  << endl ;
    for (int i = 0; i < n; i++) {
         if ( dati[i].is_out == true ) {
        cout  <<"numero matricola: " << dati[i].matr << " , crediti: " << dati[i].cre << " , media pesata: " << dati[i].matr << " , esami falliti: " << dati[i].nfails << " , stato: fuori"<<  endl;         
         }

    }
}


void remove (my_array_studente dati , int pos) {
    for (int i = pos; i < dati.used -1; i++)
    {
        dati.raw[i] = dati.raw[i+1];
    }
    (dati.used)--;
    //cout << endl << dati.used;
}


void clean (my_array_studente dati) {
    for (int i = 0; i < dati.used; i++)
    {
        if (dati.raw[i].is_out == true) {
            remove(dati , i);
            i--; 
            //cout << endl << ""<<i;
        }
    }
} 


void merge_studente (studente* data, int i, int m, int f){
    int j, k, z;
    studente* tmp ;//= NULL; 
    tmp = new studente[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j].matr <= data[k].matr) {
            tmp[z] = data[j];
            j++;
        } else {
            tmp[z] = data[k];
            k++;
        }
        z++;
    }

    if (j > m) {
        for (k; k <= f; k++){
            tmp[z] = data[k];
            z++;
        }
    } else {
        for (j; j <= m; j++){
            tmp[z] = data[j];
            z++;
        }
    }

    //ricopia tmp in data
    z = 0;
    for (z; z < f-i+1; z++){
        data[i+z] = tmp[z];
    }

    delete []tmp;
    tmp = NULL;
}

void merge_sort_studente (studente* data, int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_studente(data, init, m);
        merge_sort_studente(data, m+1, final);
        merge_studente(data, init, m, final);
    }
}


void print_array_studente_3 (studente* dati , int n , int used) {

    cout  << endl ;
    cout<< endl <<"descrizione primi 3 studenti : " << endl ;

    for (int i = 0; i < n; i++) {
        if (dati[i].is_out ==true ){
        cout  <<"numero matricola: " << dati[i].matr << " , crediti: " << dati[i].cre << " , media pesata: " << dati[i].matr << " , esami falliti: " << dati[i].nfails << " , stato: fuori"<<  endl;         
        } else {
        cout  <<"numero matricola: " << dati[i].matr << " , crediti: " << dati[i].cre << " , media pesata: " << dati[i].matr << " , esami falliti: " << dati[i].nfails << " , stato: dentro"<<  endl;         
        }
    }
     cout  << endl ;
    cout<< endl <<"descrizione ultimi 3 studenti : " << endl ;

     for (int i = used-1 ; i > used - n -1 ; i--) {
        if (dati[i].is_out ==true ){
        cout  <<"numero matricola: " << dati[i].matr << " , crediti: " << dati[i].cre << " , media pesata: " << dati[i].matr << " , esami falliti: " << dati[i].nfails << " , stato: fuori"<<  endl;         
        } else {
        cout  <<"numero matricola: " << dati[i].matr << " , crediti: " << dati[i].cre << " , media pesata: " << dati[i].matr << " , esami falliti: " << dati[i].nfails << " , stato: dentro"<<  endl;         
        }
    }       
     }


void update_status_studente (my_array_studente studenti ,  my_array_voto voti , int& nespulsi){
    for (int i = 0; i < studenti.size; i++)
    {
        for (int k = 0; k < voti.size; k++)
        {
            if( studenti.raw[i].matr == voti.raw[k].matr ){
                if (voti.raw[k].val >= 18 )
                {
                    update_media (studenti.raw[i] , voti.raw[k]);
                studenti.raw[i].cre = studenti.raw[i].cre + voti.raw[k].cre ;
                
                } else {
                    studenti.raw[i].nfails++ ;
                    
                }
                
            }
        
        }
    }
    update_status ( studenti , nespulsi);
}


void update_media ( studente stud , voto vot) {
//float res = 0;
    float c_n1 = (float)(stud.cre + vot.cre) , c_n = (float)(stud.cre);
    float v_n1 = (float)(vot.val);
    float m_n = stud.wm;

    if ( stud.cre == 0){
        stud.wm = 0;
        } else {
       stud.wm = ( (float)c_n1*(float)v_n1 + (float)m_n*(float)c_n)/( (float)c_n + (float)c_n1 );

    }
}


void update_status ( my_array_studente dati , int& nespulsi) {
int conta = 0;
cout<< endl <<"descrizione studenti espulsi nella sessione: " << endl ;
for ( int i = 0 ; i< dati.size ; i++) {
    if ( dati.raw[i].nfails >= 5 ) {
        dati.raw[i].is_out = true ;
        cout  <<"numero matricola: " << dati.raw[i].matr << " , crediti: " << dati.raw[i].cre << " , media pesata: " << dati.raw[i].matr << " , esami falliti: " << dati.raw[i].nfails << " , stato: fuori"<<  endl;         
        conta++;
    }
    else {        
        dati.raw[i].is_out = false ;
    }
    }
    cout<< endl <<"studenti epulsi nella sessione: "<< conta << endl ;
    nespulsi = conta ;
}






void stampa ( studente* dati , int d ){
cout << endl;
    for (int i = 0; i < d; i++) {
        if (dati[i].is_out ==true ){
        cout  <<"numero matricola: " << dati[i].matr << " , crediti: " << dati[i].cre << " , media pesata: " << dati[i].wm << " , esami falliti: " << dati[i].nfails << " , stato: fuori"<<  endl;         
        } else {
        cout  <<"numero matricola: " << dati[i].matr << " , crediti: " << dati[i].cre << " , media pesata: " << dati[i].wm << " , esami falliti: " << dati[i].nfails << " , stato: dentro"<<  endl;         
        }
    }
    }

void stampa_file ( studente* dati, string directory , int d ){
    cout << endl;
    ofstream output;
    output.open(directory);
    if (output.fail()) {
        cout << "failed to read file" << endl ;
    }
    for (int i = 0; i < d; i++) {
        output  <<"     " << dati[i].matr << "     " << dati[i].cre << "     " << dati[i].wm << "     " << dati[i].nfails << "        "<< dati[i].is_out<<  endl;   
    }
    output.close();
    }

