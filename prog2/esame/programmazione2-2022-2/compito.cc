#include <iostream>
#include <fstream>
#include "tipo.h"
#include "grafo.h"
using namespace std;



/**
 * @brief Crea un grafo g di v nodi vuoto;
 * 
 * @param g 
 * @param v 
 */
void crea(graph& g,int v){
    g = new_graph(v);
}

/**
 * @brief Aggiunge un arco orientato nel grafo dal nodo A al nodo B con peso w,
 *          ogni arco è un pagamento.
 * 
 * @param g 
 * @param A 
 * @param B 
 * @param w 
 */
void aggiungi(graph& g,int A,int B,float w){
    add_arc(g,A,B,w);  
}

/**
 * @brief Stampa ogni nodo del grafo (Persona), con ogni pagamento che ha effettuato
 * 
 * @param g 
 */
void stampa(graph g){
    adj_list liste;                             //<--Puntatore per liste di adiacenza
    for(int i=1;i<=get_dim(g);i++){          
        liste = get_adjlist(g,i);             //<--Testa della lista
        cout<<i<<": ";
        //Scorro la lista di ogni nodo;
        while(liste != NULL){
            cout<<get_adjweight(liste)<<" euro a "<<get_adjnode(liste)<<", ";
            liste = get_nextadj(liste);
        }
        cout<<endl;
    }
    cout<<endl;
}

/**
 * @brief Trova la persona con il numero minimo di pagamenti e quella con il numero massimo
 * 
 * @param g 
 */
void estremi(graph g){
    //Vettore contenente la somma dei pagamenti per ogni nodo
    int somme[get_dim(g)];
    for(int i=0;i<get_dim(g);i++)
        somme[i] = 0;

    //Somma dei pesi per ogni nodo nella rispettiva posizione del vettore
    adj_list liste;
    for(int i=0;i<get_dim(g);i++){
        liste = get_adjlist(g,i+1);
        while(liste != NULL){
            somme[i] += get_adjweight(liste);
            liste = get_nextadj(liste);
        }
    }

    //Ricerca dei valori minimo e massimo nel vettore (Con conteggio della posizione)
    int min = somme[0], posizioneMin;
    int max = somme[0], posizioneMax;
    for(int i=0;i<get_dim(g);i++){
        if(somme[i] > max){
            max = somme[i];
            posizioneMax = i+1;
        }
        if(somme[i] < min){
            min = somme[i];
            posizioneMin = i+1;
        }
    }

    //Stampa
    cout<<"Minimo: "<<posizioneMin<<" - "<<min<<" pagamenti"<<endl;
    cout<<"Massimo: "<<posizioneMax<<" - "<<max<<" pagamenti"<<endl;
}

int main(){
    ifstream file("spese.txt");
    graph mainGraph;
    int numNodi;

    //Punto 1
    file>>numNodi;
    crea(mainGraph,numNodi);

    int primoNome,secondoNome,somma;
    while(file>>primoNome>>secondoNome>>somma)
        aggiungi(mainGraph,primoNome,secondoNome,somma);
    
    stampa(mainGraph);

    //Punto 2
    estremi(mainGraph);
}