#include <iostream>
#include "tipo.h"
#include "albero.h"
using namespace std;


int main(){
    albero root;

    root = newNode(1);
    
    nodo* p = newNode(2);
    
    insertChild(root,p);

    nodo* e = newNode(3);
    nodo* s = newNode(4);

    insertChild(p,e);
    insertSibling(e,s);
    
    nodo* m = newNode(5);
    nodo* l = newNode(6);
    insertSibling(p,m);
    insertChild(m,l);
    nodo* a = newNode(7);
    insertSibling(m,a);
    
    serializza(root);
    cout<<endl;
    cout<<"Altezza = "<<altezza(root)<<endl;
    cout<<path(root,9)<<endl;
}