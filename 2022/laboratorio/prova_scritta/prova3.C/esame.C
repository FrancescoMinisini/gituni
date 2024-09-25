#include<iostream>
using namespace std ; 
#include<cmath>
#include<cstring>
#include<fstream>
#include"librerie/funzioni/funzioni.h"

void right_shift ( int*v , int pos, int& used);
void left_shift ( int*v , int pos, int& used);
bool is_even ( int d) ;
int*set (int*v , int d);
int* unione ( int* A, int da, int* B, int db );
int* merge ( int* v , int dv ,int* b , int db);
void swap ( int*v , int pos1 , int pos2);
int find_min_p (int* v, int d , int index , int p);
void ord (int* v , int d, int p);

int main(){
    int v[10];
    //int c[6];
    define_array ( v, 10);
    //define_array ( c, 6);
    /*for (int i = 0; i < used; i++)
    {
        if (is_even(v[i]))
        {
            right_shift (v , i , used);
            i++;
        } else {
            left_shift( v, i , used);
            i--;
        }
    }*/
    //int* result ;
    //result = set ( v , 10);

    //print_array_int ( unione ( v, 10 , c , 6), 16 );
    ord(v, 10 , 1);
    print_array_int ( v, 10 );

    
    return 0;
}

int* unione ( int* A, int da, int* B, int db ){
    int*result = merge( A , da , B ,db);
    result = set(result , da +db);   
    return result;
}

int* merge ( int* v , int dv ,int* b , int db){
    int* result = new int [ dv+db];
    for (int i = 0; i < dv; i++)
    {
        result[i] = v[i];
    }
    for (int i = 0; i < db; i++)
    {
       result[dv + i]  = b [i];
    }
    return result;
}

int*set (int*v , int d){
    int conta = 0 , used = d; 
    for (int i = 0; i < used; i++)
    {
        for (int k = i+1 ; k < used ; k++) {
            if (v[i] == v[k]){
                left_shift (v,k,used);
                k--;
            }
        }
    }
    int* result = new int [used];
    for (int i = 0; i < used; i++)
    {
        result[i] = v [i];
    }
    
    return result;
}

void right_shift ( int*v , int pos, int& used){
    for (int i =  used - 1; i >= pos ; i--)
    {
       v[i+1] = v[i];
    }
    used++;
}


void left_shift ( int*v , int pos, int& used){
    for (int i =  pos; i < used ; i++)
    {
       v[i] = v[i+1];
    }
    used--;
}

bool is_even ( int d) {
    if(d%2 == 0){
        return true;
    }
    else return false;
}

void swap ( int*v , int pos1 , int pos2){
    int appo; 
    appo = v[pos1] ; 
    v[pos1] = v[pos2] ;
    v[pos2] = appo ; 
}

int find_min_p (int* v, int d , int index , int p){
    int appo = index*p;
    for (int i = index; i*p < d ; i++){ 
        if ( v [i*p] < v[appo]) {
            appo = i; 
        }
}
return appo;
}

void ord (int* v , int d, int p) {
    int temp;
    for (int i = 0; i*p < d; i++)
    {
        temp = find_min_p (v , d, i , p);
        swap ( v , temp*p , i*p);
    }
}


