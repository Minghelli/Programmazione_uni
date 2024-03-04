#include <iostream>
#include <cstring>
#include "tipo.h"
using namespace std;

int compare(tipo_inf s1,tipo_inf s2){
    return s1-s2;
}

void copy(tipo_inf& dest,tipo_inf sor){
    dest = sor;
}

void print(tipo_inf s){
    cout<<s<<" ";
}