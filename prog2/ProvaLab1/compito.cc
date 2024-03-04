#include <iostream>
#include <fstream>
#include <cstring>
#include "grafi.h"
#include "coda.h"
#include "node.h"
using namespace std;

void stampa(graph g,node* n){
    adj_list l;
    for(int i=1;i<=get_dim(g);i++){
        l = get_adjlist(g,i);
        int val;
        while(l != NULL){
            cout<<n[i-1].cont<<" ";
            val = get_adjnode(l);
            if(n[i-1].tipo == 'U')
                if(n[val-1].tipo == 'U')
                    cout<<"FOLLOW ";
                else
                    cout<<"LIKE ";
            else
                cout<<"OWNER ";
            cout<<n[val-1].cont<<endl;
            l = get_nextadj(l);
        }
        cout<<endl;
    }
}

int* totalLike(graph g,node* n){
    char utente[30],tweet[30];
    int* like = new int[get_dim(g)];

    for(int i=0;i<get_dim(g);i++)
        like[i] = 0;

    for(int i=0;i<get_dim(g);i++){
        if(n[i].tipo == 'U')
            strcpy(utente,n[i].cont);
        else{
            
        }
    }
}

int main(){
    //Punto 1
    ifstream file("graph");

    int dim,sor,des;
    file>>dim;

    graph g = new_graph(dim);
    while(file>>sor>>des)
        add_arc(g,sor,des,1.0);

    file.close();

    //stampa(g);

    //Punto 2
    ifstream file2("node");
    char contenuto[81];
    char tipo;

    node* nodi = new node[dim];
    
    for(int i=0;i<dim;i++){
        file2.ignore();
        file2.getline(contenuto,81);
        strcpy(nodi[i].cont,contenuto);
        file2>>tipo;
        nodi[i].tipo = tipo;
    }
    file2.close();

    stampa(g,nodi);
}