#include"lib.h"

void stampa_pos ( misura* dati , int d ){

    for (int i = 0; i < d; i++)
    {
        if (dati[i].carica > 0) {
            cout  << "{ " << dati[i].p[0] << " , " <<dati[i].p[1] << " , " <<dati[i].p[2] << " , "  <<dati[i].p[3]  << " , "  <<dati[i].carica <<  " } "<< endl;
    }}
    
}

void stampa_neut ( misura* dati , int d ){

    for (int i = 0; i < d; i++)
    {
        if (dati[i].carica == 0) {
            cout  << "{ " << dati[i].p[0] << " , " <<dati[i].p[1] << " , " <<dati[i].p[2] << " , "  <<dati[i].p[3]  << " , "  <<dati[i].carica << " "<<dati[i].eta<<  " } "<< endl;
    }}
    
}

misura* inizializza_misura (int& n_dati , string directory, int& error_code) {
    misura* vettore; 
    ifstream data ;
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
    }
    
    double p[4]; // energia-momento (E, px, py, pz)
    int carica; // carica elettrica
    double eta; // rapidita'
    n_dati = 1 ; 
    data >> p[0]>> p[1]>> p[2]>> p[3] >> carica ;
    
    while (!data.eof()) {
        n_dati++ ;
    data >> p[0]>> p[1]>> p[2]>> p[3] >> carica  ;
    }
     data.close () ;

    vettore = new misura [n_dati];
    
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
    data >> vettore[k].p[0];
    data >> vettore[k].p[1];
    data >> vettore[k].p[2];
    data >> vettore[k].p[3];
    data >> vettore[k].carica;
    //data >> vettore[k].eta;
    //data >> vettore[k].stato;
    }

    data.close () ;

    error_code = 0; 
    return vettore; 
}

int conta_neg (my_array_misura dati) {
    int conta = 0;
    for (int i = 0; i < dati.used; i++)
    {
     if ( dati.raw[i].carica < 0 ) {
        conta++;
     }
    }
    return conta;
}

int conta_pos (my_array_misura dati) {
    int conta = 0;
    for (int i = 0; i < dati.used; i++)
    {
     if ( dati.raw[i].carica > 0 ) {
        conta++;
     }
    }
    return conta;
}

double calcola_eta (misura dato){
    return 0.5*log((dato.p[0]+dato.p[3])/(dato.p[0]-dato.p[3]));
}

void inizzializa_eta ( my_array_misura dati ){

    for (int i = 0; i < dati.size; i++)
    {
        dati.raw[i].eta = calcola_eta (dati.raw[i]);
   }}
    
void print_array_misura (misura* dati , int n , int used) {

    for (int i = 0; i < n; i++) {
         cout  << "eta numero: "  << i+1 << " " << dati[i].eta << endl;
    }
     /*for (int i = used-1 ; i > used - n -1 ; i--) {
         cout  << "eta numero: "  << i+1 << " " << dati[i].eta << endl;
        }*/

}


void merge_misura (misura* data, int i, int m, int f){
    int j, k, z;
    misura* tmp ;//= NULL; 
    tmp = new misura[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j].eta <= data[k].eta) {
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

void merge_sort_misura(misura* data, int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_misura (data, init, m);
        merge_sort_misura(data, m+1, final);
        merge_misura(data, init, m, final);
    }
}



void print_array_misura_3 (misura* dati , int n , int used) {
    cout  << endl ;
    for (int i = 0; i < n; i++) {
         cout  <<"{ " << dati[i].p[0] << " , " <<dati[i].p[1]  << " , " <<dati[i].p[2]  <<" , " <<dati[i].p[3]  << " , " <<dati[i].carica  <<" , " << dati[i].eta  <<   " } "<< endl;
    }
     cout  << endl ;
     for (int i = used-1 ; i > used - n -1 ; i--) {
         cout   << "{ " << dati[i].p[0] << " , " <<dati[i].p[1]  << " , " <<dati[i].p[2]  <<" , " <<dati[i].p[3]  << " , " <<dati[i].carica  <<" , " << dati[i].eta  <<   " } "<< endl;
        }

}


void calcolaStats_misura (misura* dati, int n_dati ) {
cout << endl <<"valore minimo " << dati[posmin_double_misura(dati , 0 , n_dati)].eta;
cout << endl <<"valore max " <<  dati[posmax_double_misura(dati, 0 , n_dati)].eta;
cout << endl <<"mediana " <<  mediana_double_misura(dati, n_dati);
cout << endl <<"media " <<  media_array_double_misura(dati, n_dati);
cout << endl <<"standard dev " << stnd_double_misura(dati, n_dati, media_array_double_misura(dati, n_dati)) << endl;
}


double media_array_double_misura (misura* valori, int N) {
    double somma = 0 ;
    double res ;
    for (int i = 0; i < N; i++)
    {
     somma = somma + valori[i].eta ;
    }
    res = (double)somma / N ;

    return res ; 
} 

double stnd_double_misura(misura* value, int ndati, double media) {
    double dev ;
    double scarto = 0;
    double somma = 0 ;
    for( int i = 0; i < ndati ; i++) {
        scarto = ( value[i].eta-media )  ;
        somma = somma + pow(scarto , 2 ) ;
    }
    dev = sqrt (somma / (ndati-1));
    return dev;
}

double mediana_double_misura (misura* dati, int n_dati) {
    double mediana; 
    if (n_dati % 2 == 0){
        mediana = (dati[n_dati/2].eta +dati[(n_dati/2)-1].eta)/2 ;
    } else {
        mediana = dati[(n_dati-1)/2].eta ; 
    }
    return mediana ;
}

int posmax_double_misura (misura* a, int p, int j) {
    double s = a[p].eta;
    int posmax = p;
    for (int i = p ; i < j; i++) {
        if (s < a[i].eta) {
            s = a[i].eta;
            posmax = i;
        }
    }
    return posmax;
}

int posmin_double_misura (misura* a, int p, int j) {
    double s = a[p].eta;
    int posmin = p;
    for (int i = p ; i < j; i++) {
        if (s > a[i].eta) {
            s = a[i].eta;
            posmin = i;
            
        }
    }
    return posmin;
}

misura* copia_neg ( misura* dati , int ndati , int negativi) {
    misura* vettore = new misura [negativi];
    int k = 0 ;
    for (int i =0 ; i < ndati; i++) {
        if (dati[i].carica < 0)
        {
        vettore[k].p[0] = dati[i].p[0]  ;
        vettore[k].p[1] =  dati[i].p[1];
        vettore[k].p[2] =  dati[i].p[2];
        vettore[k].p[3] =  dati[i].p[3];
        vettore[k].carica =  dati[i].carica;
        vettore[k].eta = dati[i].eta;
        k++;
        }
        
    }
return vettore;
}

misura* copia_pos ( misura* dati , int ndati , int negativi) {
 misura* vettore = new misura [negativi];
    int k = 0 ;
    for (int i =0 ; i < ndati; i++) {
        if (dati[i].carica > 0)
        {
        vettore[k].p[0] = dati[i].p[0]  ;
        vettore[k].p[1] =  dati[i].p[1];
        vettore[k].p[2] =  dati[i].p[2];
        vettore[k].p[3] =  dati[i].p[3];
        vettore[k].carica =  dati[i].carica;
        vettore[k].eta = dati[i].eta;
        k++;
        }
        
    }
    return vettore;
}

misura* copia_neut ( misura* dati , int ndati , int negativi) {
    misura* vettore = new misura [negativi];
    int k = 0 ;
    for (int i =0 ; i < ndati; i++) {
        if (dati[i].carica == 0)
        {
        vettore[k].p[0] = dati[i].p[0]  ;
        vettore[k].p[1] =  dati[i].p[1];
        vettore[k].p[2] =  dati[i].p[2];
        vettore[k].p[3] =  dati[i].p[3];
        vettore[k].carica =  dati[i].carica;
        vettore[k].eta = dati[i].eta;
        k++;
        }
        
    }
    return vettore;
}


