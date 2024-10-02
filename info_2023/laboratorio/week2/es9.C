 #include<iostream>
 using namespace std ;
 int resto (int, int);
 int MCD (int , int) ; 

int MCD ( int p , int q) {
    int mcd, r ;
    do {
        r = resto (p,q) ;
        p = q ; 
        q = r ; 
    } while (q != 0) ; 
    return p ; 
} 


int resto (int Num, int Den) {
    int q, r ;
    q =  Num/Den ; 
    r = Num - q*Den ;
    return r ; 

}



 int main() {
    int a,b,N,D, res ;
    cout << "inserisci il primo valore: " ;
    cin >> a ;
    cout << "inserisci il secondo valore: " ;
    cin >> b ;
     if (a<b){
        N = b ; 
        D = a ;
     }
     if (b<a){
        N = a ; 
        D = b ;
     }
    res = MCD (N,D) ; 
    cout << endl << "il tuo MCD: " << res << endl ; 
    
    return 0 ;

}