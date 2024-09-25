#include"librerie/lib.h"

int main(){
    int error_code = 0 ;
    double media , stnd , media_segnale , stnd_segnale; 
    string directory = "dati.dat";
    my_array_evento dati ; 
    //1
    dati = inizializza_evento ( directory, error_code) ;
    cout << endl << dati.size << endl ;
    cout << conta_segnale( dati.raw , dati.size) << " con percentuale: "<< (float)conta_segnale( dati.raw , dati.size)*100/dati.size << "%"<<  endl;
    cout << conta_background ( dati.raw , dati.size) << " con percentuale: "<< (float)conta_background( dati.raw , dati.size)*100/dati.size << "%"<<  endl;;
    
    //2
    massainv (dati);
    print_array_evento_10 (dati.raw , 10 , dati.size);
    //3 
    merge_sort_evento ( dati.raw , 0 , dati.size -1 );
    print_array_evento_4 (dati.raw , 4 , dati.size);
    //4
    media = media_array_double(dati.raw , dati.size );
    stnd = stnd_double ( dati.raw , dati.size, media);
    media_segnale = media_array_double_segnale ( dati.raw , dati.size );
    stnd_segnale = stnd_double_segnale ( dati.raw , dati.size , media_segnale);
    cout << media <<" " << stnd << " " << media_segnale << " " << stnd_segnale ;
    cout << endl <<"minimo" << dati.raw[posmin(dati.raw , 0 , dati.size )].massainv << " e massimo " << dati.raw[posmax(dati.raw , 0 , dati.size )].massainv <<endl ;
    cout << endl <<"minimo segnale : " << dati.raw[posmin_segnale(dati.raw , 0 , dati.size )].massainv << " e massimo segnale :" << dati.raw[posmax_segnale(dati.raw , 0 , dati.size )].massainv <<endl ;

    
    
    return 0;
}

