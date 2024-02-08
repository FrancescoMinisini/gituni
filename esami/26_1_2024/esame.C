#include"librerie/lib.h"

int main(){
    int n_dati_g = 0, n_dati_m =0,  error_code = 0 ; 
    string directory1 = "iscritti.dat";
    string directory2 = "punteggi.dat";
    giocatore* vettore_g = inizializza_giocatore ( n_dati_g ,  directory1,  error_code) ; 
    mano* vettore_m = inizializza_mano ( n_dati_m ,  directory2,  error_code);
    my_array_giocatore dati_g;
    dati_g.raw = vettore_g ;
    dati_g.size = n_dati_g;
    dati_g.used = n_dati_g;
    my_array_mano dati_m;
    dati_m.raw = vettore_m ;
    dati_m.size = n_dati_m;
    dati_m.used = n_dati_m;

    cout<< endl <<"numero iscritti : "<<n_dati_g << endl;
    cout<< endl <<"numero professionisti : "<<conta_pro (dati_g) << endl;
    cout<<endl << "numero professionisti : "<<conta_ama (dati_g)<< endl ;
    print_array_giocatore_3 ( dati_g.raw , 3, dati_g.size) ;


    return 0;
}



/*
void stampa ( struct* dati , int d ){

    for (int i = 0; i < d; i++)
    {
                 cout  << "{ " << dati[i].time << " , " <<dati[i].db << " , " <<dati[i].dato <<  " } "<< endl;
    }}
    
}*/

