#include <iostream>
#include "tipo.h"
#include "albero.h"
using namespace std;

nodo* newNode(tipoInf inf){
    nodo* a = new nodo;
    copy(a->info,inf);
    a->padre = a->figlio = a->fratm = NULL;
    return a;
}

void insertChild(albero p,albero c){
    c->fratm = p->figlio;
    c->padre = p;
    p->figlio = c;
}

void insertSibling(nodo* n,albero f){
    f->fratm = n->fratm;
    f->padre = n->padre;
    n->fratm = f;
}

tipoInf getInfo(albero a){
    return a->info;
}

nodo* getPadre(albero a){
    return a->padre;
}

nodo* getFiglio(albero a){
    return a->figlio;
}

nodo* getFratm(albero a){
    return a->fratm;
}

void serializza(albero a){
    cout<<"(";
    print(getInfo(a));
    albero a1 = getFiglio(a);
    while(a1 != NULL){
        serializza(a1);
        a1 = getFratm(a1);
    }
    cout<<")";
}

int altezza(albero a){
    if(getFiglio(a) == NULL)
        return 0;
    int alt = 0,aus;
    albero a1 = getFiglio(a);
    while(a1 != NULL){
        aus = altezza(a1);
        if(aus > alt)
            alt = aus;
        a1 = getFratm(a1);
    }
    return alt + 1;
}

bool path(nodo* n,tipoInf x){
    if(compare(getInfo(n),x) == 0)
        return true;
    bool ris = false;
    albero a = getFiglio(n);
    while(a != NULL && !ris){
        ris = path(a,x);
        if(!ris)
            a = getFratm(a);
    }
    return ris;
}