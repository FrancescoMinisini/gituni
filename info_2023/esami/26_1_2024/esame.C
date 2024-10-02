#include"librerie/lib.h"


int main(){
    int n_dati_g = 0, n_dati_m =0,  error_code = 0, n_dati_m2 = 0 ; 
    string directory1 = "iscritti.dat";
    string directory2 = "punteggi.dat";
    string directory3 = "classifica.dat";
    
    giocatore* vettore_g = inizializza_giocatore ( n_dati_g ,  directory1,  error_code) ; 
    my_array_giocatore dati_g;
    dati_g.raw = vettore_g ;
    dati_g.size = n_dati_g;
    dati_g.used = n_dati_g;
    mano* vettore_m = inizializza_mano ( n_dati_m ,  directory2,  error_code);
    my_array_mano dati_m;
    dati_m.raw = vettore_m ;
    dati_m.size = n_dati_m;
    dati_m.used = n_dati_m;

    cout<< endl <<"numero iscritti : "<<n_dati_g << endl;
    cout<< endl <<"numero professionisti : "<<conta_pro (dati_g) << endl;
    cout<<endl << "numero professionisti : "<<conta_ama (dati_g)<< endl ;
    print_array_giocatore_3 ( dati_g.raw , 3, dati_g.size) ;

    cout<< endl <<"numero mani : "<< dati_m.size << endl; 
    print_array_mano_3 ( dati_m.raw ,  3,  dati_m.size) ;
    update_status (dati_g , dati_m);
    print_array_giocatore_3_update( dati_g.raw , 3, dati_g.size);
    merge_sort_decr_giocatore( dati_g.raw ,  0,  dati_g.size -1) ;
    stampa_giocatore ( dati_g.raw , dati_g.size );

    mano* vettore_m2 = inizializza_mano ( n_dati_m2 ,  directory3,  error_code);
    my_array_mano classifica_n;
    classifica_n.raw = vettore_m2 ;
    classifica_n.size = n_dati_m2;
    classifica_n.used = n_dati_m2;
    update_status_classifica ( classifica_n , dati_g );

    merge_sort_decr_classifica( classifica_n.raw ,  0, classifica_n.size -1) ;
    stampa_classifica (classifica_n.raw , classifica_n.size );

    if( !(error_code == 0)) {
        cout << endl << "we ce sta un problema" << endl;
    }
    return 0;
}
