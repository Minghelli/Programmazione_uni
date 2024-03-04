#include <iostream>
#include "carta.h"
using namespace std;

void copy(tipo_inf& s1,tipo_inf s2){
    s1 = s2;
}

void print(tipo_inf s){
    cout<<s.nominativo<<" ";
    cout<<s.punti<<endl;
}