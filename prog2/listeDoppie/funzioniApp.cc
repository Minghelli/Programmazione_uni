#include <iostream>
#include "tipo.h"
#include "liste.h"
#include "funzioniApp.h"
using namespace std;

/**
 * @brief Crea una nuova lista di num elementi.
 *        Ritorna la testa della lista.
 * 
 * @param num 
 * @return lista 
 */
lista creaLista(int num){
    int val;
    lista nuova = NULL;
    for(int i=0;i<num;i++){
        cout<<"Elemento "<<i+1<<": ";
        cin>>val;
        nuova = inserisci(nuova,nuovoElemento(val));
    }
    return nuova;
}

/**
 * @brief Cancella la lista l.
 * 
 * @param l 
 */
void eliminaLista(lista &l){
    while(l != NULL)
        l = elimina(l,l);
}

/**
 * @brief elimina tutti gli elementi con campo informativo val dalla lista.
 *        Ritorna la testa della lista aggiornata
 * 
 * @param l 
 * @param val 
 * @return lista 
 */
lista cancella(lista l,tipoInf val){
    elem_t* ele;
    while((ele=search(l,val)) != NULL)
        l = elimina(l,ele);
    cout<<"Elementi con valore "<<val<<" cancellati."<<endl;
    return l;
}

void stampa(lista l){
    while(l != NULL){
        cout<<head(l)<<" ";
        l = tail(l);
    }
    cout<<endl;
}

void stampaRic(lista l){
    if(l != NULL){
        stampaRic(tail(l));
        cout<<head(l)<<" ";
    }
    cout<<endl;
}

bool palindroma(lista l){
    lista l1 = l;
    while(tail(l1) != NULL)
        l1 = tail(l1);
    while(l != NULL || l1 != NULL){
        if(head(l) == head(l1)){
            l = tail(l);
            l1 = prev(l1);
        }else
            return false;
    }
    return true;
}

bool max(elem_t* e){
    elem_t* app = e->prev;
    while(app != NULL){
        if(app->elemento > e->elemento)
            return true;
        app = app->prev;
    }
    app = e->next;
    while(app != NULL){
        if(app->elemento > e->elemento)
            return true;
        app = app->next;
    }
    return false;
}

int magg(elem_t* e){
    int num = 0;
    int val = e->elemento;
    lista l = e->next,l1 = e->prev;
    while(l != NULL || l1 != NULL){
        if(l->next != NULL){
            if(l->elemento > val)
                num++;
            l = l->next;
        }
        if(l1->prev != NULL){
            if(l1->elemento > val)
                num++;
            l = l->prev;
        }
    }
    return num;
}