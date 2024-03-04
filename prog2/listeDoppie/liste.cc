#include <iostream>
#include "tipo.h"
#include "liste.h"
using namespace std;

/**
 * @brief Crea un nuovo elemento e ne riempie il campo informativo con il valore val
 * 
 * @param val 
 * @return elem_t* 
 */
elem_t* nuovoElemento(tipoInf val){
    elem_t* elemento = new elem_t;
    copy(elemento->elemento,val);
    elemento->next = elemento->prev = NULL;
    return elemento;
}

/**
 * @brief Cerca il valore val nela lista l e ritorna il puntatore alla sua prima occorrenza in essa.
 *        Se il valore non è presente ritorna NULL
 * 
 * @param l 
 * @param val 
 * @return elem_t* 
 */
elem_t* search(lista l,tipoInf val){
    while(l != NULL)
        if(compare(head(l),val) == 0)
            return l;
        else  
            l = tail(l);
    return NULL;
}

/**
 * @brief inserisce l'elemento ele nella lista l. Ritorna la testa della lista aggiornata
 * 
 * @param l 
 * @param ele 
 * @return lista 
 */
lista inserisci(lista l,elem_t* ele){
    ele->next = l;
    if(l!=NULL)
        l->prev = ele;
    ele->prev = NULL;
    return ele;
}

/**
 * @brief Rimuove l'elemento ele dalla lista l. Ritorna la testa della lista aggiornata
 * 
 * @param l 
 * @param ele 
 * @return lista 
 */
lista elimina(lista l,elem_t* ele){
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

tipoInf head(lista l){
    return l->elemento;
}

elem_t* tail(lista l){
    return l->next;
}

elem_t* prev(lista l){
    return l->prev;
}