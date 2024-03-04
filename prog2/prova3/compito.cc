#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include "tipo.h"
#include "liste.h"
#include "grafo.h"
using namespace std;

/**
 * @brief Carica una lista di punti di interesse
 * 
 * @param pi 
 * @return int 
 */
int carica(lista& pi){
    ifstream f("PI.txt");
    int cont = 0;
    tipo_inf e;
    int id;
    char nome[20],tipo;
    
    while(f>>id){
        f.ignore();
        f.getline(nome,20);
        f>>tipo;
        e.id = id;
        strcpy(e.nome,nome);
        e.tipo = tipo;

        pi = ord_insert_elem(pi,new_elem(e));
        cont++;
    }
    f.close();
    return cont;
}

/**
 * @brief Ritorna il PI che ha l identificativo id nella lista pi
 * 
 * @param pi 
 * @param id 
 * @return tipo_inf 
 */
tipo_inf searchPI(lista pi,int id){
    for(int i=1;i<id;i++)
        pi = tail(pi);
    return head(pi);
}

/**
 * @brief Carica e ritorna la mappa dei percorsi tra i PI
 * 
 * @param n 
 * @return graph 
 */
graph carMappa(int n){
    ifstream f("G.txt");

    graph g = new_graph(n);
    int s,d;
    while(f>>s>>d)
        add_edge(g,s,d,1.0);
    return g;
}

/**
 * @brief Stampa la mappa
 * 
 * @param pi 
 * @param m 
 */
void stampaMappa(lista pi,graph m){
    adj_list liste;
    tipo_inf a;
    for(int i=1;i<=get_dim(m);i++){
        liste = get_adjlist(m,i);
        a = searchPI(pi,i);
        cout<<a.nome<<" connesso a: ";
        while(liste != NULL){
            int id = get_adjnode(liste);
            a = searchPI(pi,id);
            cout<<a.nome<<", ";
            liste = get_nextadj(liste);
        }
        cout<<endl;
    }
    cout<<endl;
    
}

void stampa(lista l){
    while(l != NULL){
        print(head(l));
        l = tail(l);
    }
}

int main(){
    lista pi = NULL;
    int PItot;

    PItot = carica(pi);
    //stampa(pi);

    int id;
    tipo_inf punto;
    cout<<"Inserire ID dei pinti che si vogliono ricercare (premere e per stop)"<<endl;
    while(cin>>id){
        punto = searchPI(pi,id);
        print(punto);
    }

    graph mappa = carMappa(PItot);
    stampaMappa(pi,mappa);
}