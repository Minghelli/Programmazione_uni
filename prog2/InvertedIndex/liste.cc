#include <iostream>
#include "tipo.h"
#include "liste.h"
using namespace std;

//Liste

tipoInf head(lista l){
    return l->elemento;
}

lista nuovoElemento(tipoInf ele){
    lista elemento = new elem_t;
    copy(elemento->elemento,ele);
    elemento->next = elemento->prev = NULL;
    return elemento;
}

lista search(lista l,tipoInf val){
    while(l != NULL)
        if(compare(head(l),val) == 0)
            return l;
        else  
            l = tail(l);
    return NULL;
}


lista tail(lista l){
    return l->next;
}

lista prev(lista l){
    return l->prev;
}

lista inserisci(lista l,lista ele){
    ele->next = l;
    if(l!=NULL)
        l->prev = ele;
    ele->prev = NULL;
    return ele;
}

lista elimina(lista l,lista ele){
    if(ele == l)
        l = tail(l);
    else{
        (ele->prev)->next = ele->next;
        if(ele->next != NULL)
            (ele->next)->prev = ele->prev;
    }
    delete ele;
    return l;
}