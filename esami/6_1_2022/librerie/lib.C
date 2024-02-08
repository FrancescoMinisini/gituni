#include"lib.h"

my_array_evento inizializza_evento ( string directory, int& error_code) {
    int n_dati = 0; 
    evento* vettore;
    my_array_evento result; 
    ifstream data ;
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
    }
    
    double p1[4]; // energia-momento particella 1 (E1, p1x, p1y, p1z)
    double p2[4]; // energia-momento particella 2 (E2, p2x, p2y, p2z)
    bool segnale; // Segnale se 1|true, background se 0|false
    double massainv; // Massa invariante    

    n_dati = 1 ; 
    data >> p1[0] >> p1[1] >> p1[2] >> p1[3] >> p2[0] >> p2[1] >> p2[2] >> p2[3] >> segnale;
    
    while (!data.eof()) {
        n_dati++ ;
        data >> p1[0] >> p1[1] >> p1[2] >> p1[3] >> p2[0] >> p2[1] >> p2[2] >> p2[3] >> segnale;
     }
     data.close () ;

    vettore = new evento [n_dati];
    
    if (vettore == NULL) {
        error_code= -2;
        return result;
    }
    
    data.open(directory) ;
    
    if (data.fail()) {
        cout << "failed to read file" << endl ;
        data.close () ;
        error_code = -1; 
    } 

    for (int k = 0 ; k< n_dati ; k++){
    data >> vettore[k].p1[0];
    data >> vettore[k].p1[1];
    data >> vettore[k].p1[2];
    data >> vettore[k].p1[3];
    data >> vettore[k].p2[0];
    data >> vettore[k].p2[1];
    data >> vettore[k].p2[2];
    data >> vettore[k].p2[3];
    data >> vettore[k].segnale;
    }

    data.close () ;
    result.raw = vettore;
    result.size = n_dati;
    result.used = n_dati;
    error_code = 0; 
    return result; 
}

int conta_segnale ( evento* dati , int n_dati) {
    int res = 0 ; 
    for (int i = 0 ; i < n_dati  ; i++)   {
        if ( dati[i].segnale == true){
        res++ ;}
    }  

    return res ; 
}


int conta_background ( evento* dati , int n_dati) {
    int res = 0 ; 
    for (int i = 0 ; i < n_dati  ; i++)   {
        if ( dati[i].segnale == false){
        res++ ;}
    }  

    return res ; 
}

void massainv (my_array_evento dato){
    for (int i = 0; i < dato.size; i++)
    {
        dato.raw[i].massainv = sqrt ( pow (dato.raw[i].p1[0] +  dato.raw[i].p2[0], 2) - (pow ( dato.raw[i].p1[1] + dato.raw[i].p2[1] , 2) + pow ( dato.raw[i].p1[2] + dato.raw[i].p2[2] , 2) + pow ( dato.raw[i].p1[3] + dato.raw[i].p2[3] , 2)));
    }
}

void print_array_evento_10 (evento* dati , int n , int used) {

    for (int i = 0; i < n; i++) {
         cout  << "{ " << dati[i].p1[0] << " , " << dati[i].p1[1]<<" , " << dati[i].p1[2]<<" , " << dati[i].p1[3]<<" , " << dati[i].p2[0]<< " , " <<dati[i].p2[1] << " , " <<dati[i].p2[2] << " , " <<dati[i].p2[3] <<" , " << dati[i].segnale << " , " <<dati[i].massainv <<  " } "<< endl;
    }
     /*for (int i = used-1 ; i > used - n -1 ; i--) {
         cout  << "{ " << dati[i].time << " , " <<dati[i].db << " , " <<dati[i].dato <<  " } "<< endl;
    }*/

}

void print_array_evento_4 (evento* dati , int n , int used) {

    for (int i = 0; i < n; i++) {
         cout  << "{ " << dati[i].p1[0] << " , " << dati[i].p1[1]<<" , " << dati[i].p1[2]<<" , " << dati[i].p1[3]<<" , " << dati[i].p2[0]<< " , " <<dati[i].p2[1] << " , " <<dati[i].p2[2] << " , " <<dati[i].p2[3] <<" , " << dati[i].segnale << " , " <<dati[i].massainv <<  " } "<< endl;
    }
     for (int i = used-1 ; i > used - n -1 ; i--) {
         cout  << "{ " << dati[i].p1[0] << " , " << dati[i].p1[1]<<" , " << dati[i].p1[2]<<" , " << dati[i].p1[3]<<" , " << dati[i].p2[0]<< " , " <<dati[i].p2[1] << " , " <<dati[i].p2[2] << " , " <<dati[i].p2[3] <<" , " << dati[i].segnale << " , " <<dati[i].massainv <<  " } "<< endl;
    }

}



void merge_evento (evento data[], int i, int m, int f){
    int j, k, z;
    evento* tmp ;//= NULL; 
    tmp = new evento[f-i+1];

    j = i; //indice del primo sottovettore
    k = m+1; //indice del secondo sottovettore
    z = 0; //indice di tmp

    while (j <= m && k <= f){
        if (data[j].massainv <= data[k].massainv) {
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

void merge_sort_evento (evento data[], int init, int final){
    int m;
    if (init < final){
        m = init + (final - init)/2;
        merge_sort_evento(data, init, m);
        merge_sort_evento(data, m+1, final);
        merge_evento(data, init, m, final);
    }
}

double media_array_double (evento* dato, int N) {
    double somma = 0 ;
    double res ;
    for (int i = 0; i < N; i++)
    {
     somma = somma +  dato[i].massainv ;
    }
    res = (double)somma / N ;

    return res ; 
} 

double stnd_double (evento* dato , int ndati, double media) {
    double dev ;
    double scarto = 0;
    double somma = 0 ;
    for( int i = 0; i < ndati ; i++) {
        scarto = ( dato[i].massainv-media )  ;
        somma = somma + pow(scarto , 2 ) ;
    }
    dev = sqrt (somma / (ndati-1));
    return dev;
}

double media_array_double_segnale (evento* dato, int N) {
    double somma = 0 ;
    double res ;
    for (int i = 0; i < N; i++)
    { if ( dato[i].segnale == true){
     somma = somma +  dato[i].massainv ;
    }}
    res = (double)somma / conta_segnale (dato , N) ;

    return res ; 
} 

double stnd_double_segnale (evento* dato , int ndati, double media) {
    double dev ;
    double scarto = 0;
    double somma = 0 ;
    for( int i = 0; i < ndati ; i++) {
        if ( dato[i].segnale == true ){
        scarto = ( dato[i].massainv-media )  ;
        somma = somma + pow(scarto , 2 ) ;
    }}
    dev = sqrt (somma / (conta_segnale(dato , ndati) -1));
    return dev;
}

int posmax(evento* a, int p, int j) {
    int s = a[p].massainv;
    int posmax = p;
    for (int i = p + 1; i < j; i++) {
        if (s < a[i].massainv) {
            s = a[i].massainv;
            posmax = i;
        }
    }
    return posmax;
}

int posmin(evento a[], int p, int j) {
    int s = a[p].massainv;
    int posmin = p;
    for (int i = p + 1; i < j; i++) {
        if (s > a[i].massainv) {
            s = a[i].massainv;
            posmin = i;
        }
    }
    return posmin;
}


int posmax_segnale (evento* a, int p, int j) {
     do {p++;} 
    while (a[p].segnale == false );
    int s = a[p].massainv;
    int posmax = p;
    for (int i = p + 1; i < j; i++) {
        if (s < a[i].massainv and a[i].segnale == true) {
            s = a[i].massainv;
            posmax = i;
        }
    }
    return posmax;
}

int posmin_segnale (evento a[], int p, int j) {
    do {p++;} 
    while (a[p].segnale == false );
    int s = a[p].massainv;

    int posmin = p;
    for (int i = p + 1; i < j; i++) {
        if (s > a[i].massainv and a[i].segnale == true) {
            s = a[i].massainv;
            posmin = i;
        }
    }
    return posmin;
}

void istogramma(float min, float max, int nbins, float data[], int used, char pixel, int max_n){
    float delta = (max - min) / nbins;
    int* counters;
    
    //crea vettore di contatori
    counters = new int[nbins];
    for (int i = 0; i<nbins; i++){
        counters[i] = 0;
    }

    //conta le frequenze di dati
    for (int i = 0; i<used; i++){
        int k = 1;
        while (min+k*delta < data[i]){
            k++;
        }
        counters[k-1]++;
    }

    //resize se uno dei counters e' maggiore di n_max
    for (int i = 0; i< nbins; i++){
        if (counters[i]> max_n){
            for (int i = 0; i<nbins; i++){
                counters[i] = counters[i]/2 + 1; // in modo da fare per eccesso
            }
        }
    }
    
    //printa l'instogramma
    for (int i = 0; i<nbins; i++){
        cout << "( " << min + i*delta << ", " << min + (i+1)*delta << " ] ";
        for (int j = 0; j < counters[i]; j++){
            cout << pixel;
        }
        cout << endl;
    }
}


