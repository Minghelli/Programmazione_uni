#include <iostream>
#include <cstring>
#include "tipo.h"
using namespace std;

int compare(tipoInf v1,tipoInf v2){
    return v1 - v2;
}

void copy(tipoInf &des,tipoInf sor){
    des = sor;
}

void print(tipoInf val){
    cout<<val;
}