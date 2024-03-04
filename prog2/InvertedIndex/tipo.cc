#include <iostream>
#include <cstring>
#include "tipo.h"
using namespace std;

//Liste-tipo

int compare(tipoInf v1,tipoInf v2){
    if(v1 == v2)
        return 0;
    else if(v1 > v2)
        return 1;
    return -1;
}

void copy(tipoInf &des,tipoInf sor){
    des = sor;
}

void print(tipoInf val){
    cout<<val;
}