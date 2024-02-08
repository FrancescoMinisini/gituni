#include"librerie/lib.h"

int main(){
    int n_dati = 0, error_code = 0 ; 
    string directory = "dati.dat";
    my_array_misura dati , dati_neg , dati_neut , dati_pos;
    dati.raw = inizializza_misura (dati.size , directory , error_code);
    dati.used = dati.size;
    
    
    //1
    cout<< "misure lette :" << dati.size << endl ;
    //cout<< "misure positive :" << endl ;
    //stampa_pos (  dati.raw , dati.size );
    //cout<< "misure negative :"  << endl ;
    //stampa_neg ( dati.raw , dati.size);
    cout<< "misure positive :"<<conta_pos (dati) << " con percentuale " << (float)conta_pos( dati )*100/dati.size << "%"<<  endl;
    cout<< "misure negative :"  <<conta_neg (dati) << " con percentuale " << (float)conta_neg( dati )*100/dati.size << "%"<<  endl;

    //2
    inizzializa_eta ( dati );
    print_array_misura ( dati.raw , 5 , dati.size); 
    //3
    merge_sort_misura( dati.raw,  0,  dati.size -1);
    print_array_misura_3 ( dati.raw ,  3 , dati.size);
    cout << endl << "stats totali " << endl ;
    calcolaStats_misura ( dati.raw, dati.size );
    
    dati_neg.size =conta_neg (dati);
    dati_pos.size =conta_pos (dati);
    dati_neut.size = dati.size - conta_pos (dati) - conta_neg (dati);
    dati_neg.raw = copia_neg (  dati.raw , dati.size ,dati_neg.size );
    dati_pos.raw = copia_pos (  dati.raw , dati.size , dati_pos.size);
    dati_neut.raw = copia_neut (  dati.raw , dati.size , dati_neut.size);
    
    cout << endl << "stats pos " << endl ;
    calcolaStats_misura ( dati_pos.raw, dati_pos.size );
    cout << endl << "stats neg " << endl ;
    calcolaStats_misura ( dati_neg.raw, dati_neg.size );
    cout << endl << "stats neutro " << endl ;
    calcolaStats_misura ( dati_neut.raw, dati_neut.size );

    return 0;
}

