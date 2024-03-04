#include <iostream>
#include "tipo.h"
using namespace std;

int compare(tipo_inf c1,tipo_inf c2){
    if(c1.seme == c2.seme)
        return c1.valore - c2.valore;
    else if(c1.seme > c2.seme)
        return 1;
    else 
        return -1;
}

void copy(tipo_inf& d,tipo_inf s){
    d = s;
}

void print(tipo_inf c){
    
}