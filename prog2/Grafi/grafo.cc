#include <iostream>
#include "grafo.h"
using namespace std;

/**
 * @brief Ritorna una struttura GRAPH con il campo DIM pari al numero di elementi del grafo
 *        ed il vettore delle teste delle liste di adiacenza allocato.
 * 
 * @param num 
 * @return graph 
 */
graph newGraph(int num){
    graph g;
    g.dim = num;
    g.nodes = new listaAd[num];
    for(int i=0;i<num;i++)
        g.nodes[i] = NULL;
    return g;
}

/**
 * @brief Aggiunge un arco orientato dal nodo S al nodo D con il peso W
 * 
 * @param g 
 * @param s 
 * @param d 
 * @param w 
 */
void addArc(graph& g,int s,int d,double w){
    nodo* n = new nodo;
    n->inf = d-1;
    n->weight = w;
    n->next = g.nodes[s-1];
    g.nodes[s-1] = n;
}

/**
 * @brief Aggiunge un arco non orientato dal nodo S al nodo D con il peso W
 * 
 * @param g 
 * @param s 
 * @param d 
 * @param w 
 */
void addEdge(graph& g,int s,int d,double w){
    addArc(g,s,d,w);
    addArc(g,d,s,w);
}

/**
 * @brief Ritorna dimensione del grafo
 * 
 * @param g 
 * @return int 
 */
int getDim(graph g){
    return g.dim;
}

/**
 * @brief Ritorna il puntatore alla testa della lista di adiacenza del nodo n
 * 
 * @param g 
 * @param n 
 * @return listaAd 
 */
listaAd getListaAd(graph g,int n){
    return g.nodes[n];
}

/**
 * @brief Restituisce l' ID del nodo
 * 
 * @param n 
 * @return int 
 */
int getNode(nodo* n){
    return n->inf+1;
}

/**
 * @brief Restituisce il prossimo elemento della lista
 * 
 * @param l 
 * @return listaAd 
 */
listaAd getNext(listaAd l){
    return l->next;
}
