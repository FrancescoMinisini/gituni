#include"librerie/lib.h"


int main(){
    int n_dati_v = 0, error_code = 0 , n_dati_s = 0 , n_espulsi =0; 
    string directory2 = "dati/studenti.dat";
    string directory1 = "dati/votiGF.dat";
    string directory3 = "dati/studenti_GF.dat";
    //1
    
    voto* vettore_voto =   inizializza_voto ( n_dati_v ,  directory1,  error_code) ;
    my_array_voto dati_v;
    dati_v.raw = vettore_voto;
    dati_v.size = n_dati_v;
    dati_v.used = n_dati_v;

    cout<< endl <<"numero voti : "<< dati_v.size << endl;
    cout<< endl <<"rapporto numero sufficienti   : "<< (float)conta_suf (dati_v)/dati_v.size << endl;
    cout<< endl <<"rapporto numero insufficienti : "<< (float)conta_insuf (dati_v)/dati_v.size << endl;
    print_array_voto_3 ( dati_v.raw , 3, dati_v.size) ;
    
    //2

    studente* vettore_studente =   inizializza_studente ( n_dati_s ,  directory2,  error_code) ;
    my_array_studente dati_s;
    dati_s.raw = vettore_studente;
    dati_s.size = n_dati_s;
    dati_s.used = n_dati_s;

    cout<< endl <<"numero espulsi : "<< conta_espulso(dati_s) << endl;
    cout<< endl <<"numero ammessi : "<< conta_ammesso(dati_s) << endl;
    cout<< endl <<"descrizione studenti espulsi : " << endl ;
    print_array_studente_fuori (dati_s.raw ,dati_s.size );

//3
    clean ( dati_s);
    merge_sort_studente ( dati_s.raw , 0 , dati_s.used-1);
    print_array_studente_3 ( dati_s.raw ,  3 , dati_s.size) ;
    //stampa ( dati_s.raw , dati_s.used );

//4,5

    update_status_studente ( dati_s , dati_v , n_espulsi);
//6

    clean ( dati_s);
    merge_sort_studente ( dati_s.raw , 0 , dati_s.used-1);
    stampa_file ( dati_s.raw, directory3 ,  dati_s.used-n_espulsi);
    

        if( !(error_code == 0)) {
        cout << endl << "we ce sta un problema" << endl;
        }
    return 0;
}

