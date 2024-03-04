#include <iostream>
#include <cstring>
#include "tipo.h"
using namespace std;

int compare(tipo_inf s1,tipo_inf s2){
    return s1.id - s2.id;
} 

void copy(tipo_inf& s1,tipo_inf s2){
    s1 = s2;
}

void print(tipo_inf s){
    cout<<s.nome<<" "<<s.tipo<<endl;
}