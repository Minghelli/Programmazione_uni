#include <iostream>
#include "bfs.h"
using namespace std;

listaBFS newQueue(){
    listaBFS l = {NULL,NULL};
    return l; 
}

static elemBFS* newElem(int n){
    elemBFS* newElem = new elemBFS;
    newElem->elem = n;
    newElem->next = NULL;
    return newElem;
}

listaBFS enqueue(listaBFS l,int n){
    elemBFS* e = newElem(n);
    if(l.tail != NULL)
        l.tail->next = e;
    l.tail = e;
    if(l.head == NULL)
        l.head = l.tail;
    return l;
}

int dequeue(listaBFS& l){
    int e = l.head->elem;
    l.head = l.head->next;
    return e;
}

int first(listaBFS l){
    return l.head->elem;
}

bool isEmpty(listaBFS l){
    if(l.head == NULL)
        return true;
    return false;
}