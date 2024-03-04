#include <iostream>
#include <cstring>
#include "tipo.h"
#include "bst.h"
using namespace std;

/**
 * @brief Ritorna 0 se k1 = k2, >0 se k1 > k2, <0 se k1 < k2
 * 
 * @param k1 
 * @param k2 
 * @return int 
 */
int compareKey(tipoKey k1,tipoKey k2){
    return k1 - k2;
}

void copyKey(tipoKey& kd,tipoKey ks){
    kd = ks;
}

void printKey(bnode* n){
    cout<<n->key;
}


/**
 * @brief Ritorna un nodo con chiave key e campo info inf
 * 
 * @param key 
 * @param inf 
 * @return bnode* 
 */
bnode* newNode(tipoKey key,tipoInf inf){
    bnode* n = new bnode;
    copy(n->inf,inf);
    copyKey(n->key,key);
    n->left = n->right = n->parent = NULL;
    return n;
}

/**
 * @brief Restituisce il nodo con chiave key nell'albero t
 * 
 * @param t 
 * @param n 
 * @return bnode* 
 */
bnode* search(btree t,tipoKey n){
    if(compareKey(getKey(t),n) == 0)
        return t;
    if(compareKey(getKey(t),n) < 0){
        t = getLeft(t);
        search(t,n);
    }
    else{
        t = getRight(t);
        search(t,n);
    }
    return NULL;
}

/**
 * @brief Inserisce nell'albero t il nodo n al posto giusto
 * 
 * @param t 
 * @param n 
 */
void bstInsert(btree& t,bnode* n){
    if(t == NULL){
        t = n;
        return;
    }
    if(compareKey(getKey(n),getKey(t)) < 0){
        if(getLeft(t) != NULL){
            t = getLeft(t);
            bstInsert(t,n);
        }
        else{
            t->left = n;
            n->parent = t;
        }
    }
    else{
        if(getRight(t) != NULL){
            t = getRight(t);
            bstInsert(t,n);
        }
        else{
            t->right = n;
            n->parent = t;
        }
    }
}

void printBST(btree t){
    if(getLeft(t) != NULL)
        printBST(getLeft(t));
    printKey(t);
    cout<<" ";
    print(getInf(t));
    cout<<endl;
    if(getRight(t) != NULL)
        printBST(getRight(t));
}

tipoInf getInf(bnode* n){
    return n->inf;
}

tipoKey getKey(bnode* n){
    return n->key;
}

bnode* getLeft(bnode* n){
    return n->left;
}

bnode* getRight(bnode* n){
    return n->right;
}

bnode* getParet(bnode* n){
    return n->parent;
}