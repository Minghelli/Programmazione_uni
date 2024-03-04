#include <iostream>
#include "tipo.h"
#include "albero.h"
#include "codaBFS.h"
using namespace std;

listaBFS newQueue(){
    listaBFS l = {NULL,NULL};
    return l;
}

static elemBFS* newElem(nodo* n){
    elemBFS* newElem = new elemBFS;
    newElem->elem = n;
    newElem->next = NULL;
    return newElem;
}

listaBFS enqueue(listaBFS l,nodo* n){
    elemBFS* e = newElem(n);
    if(l.tail != NULL)
        l.tail->next = e;
    l.tail = e;
    if(l.head == NULL)
        l.head = l.tail;
    return l;
}

nodo* dequeue(listaBFS &l){
    nodo* n = (l.head)->elem;
    l.head = (l.head)->next;
    return n;
}

nodo* first(listaBFS l){
    return (l.head)->elem;
}

bool isEmpty(listaBFS l){
    if(l.head == NULL)
        return true;
    return false;
}