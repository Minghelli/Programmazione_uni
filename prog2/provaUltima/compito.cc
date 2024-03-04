#include <iostream>
#include "tipo.h"
#include "liste.h"
using namespace std;

void pesca(lista &l){
    tipo_inf e;
    cout<<"Inserisci valore: ";
    cin>>e.valore;
    cout<<"Inserisci seme: ";
    cin>>e.seme;
    l = ord_insert_elem(l,new_elem(e));
}

void stampa(lista g1,lista g2){
    cout<<"giocatore 1: ";
    while(g1 != NULL){
        cout<<head(g1).valore<<head(g1).seme<<" ";
        g1 = tail(g1);
    }
    cout<<endl<<"giocatore 2: ";
    while(g2 != NULL){
        cout<<head(g2).valore<<head(g2).seme<<" ";
        g2= tail(g2);
    }
    cout<<endl;
}

elem* scala(lista c,int& l){
    lista prima = tail(c);
    while(l != NULL){
        if(head(c).seme != head(prima).seme){
            c = tail(c);
            prima = tail(prima);
        }
        else{
            while(head(prima).valore == head(c).valore+1 && head(c).seme == head(prima).seme){
                l++;
                prima = tail(prima);
            }
            return c;
        }
    }
    return NULL;
}

int main(){
    lista giocatore1 = NULL;
    lista giocatore2 = NULL;
    int carte;
    cout<<"Numero di carte per ogni giocatore: ";
    cin>>carte;

    cout<<"Giocatore 1:"<<endl;
    for(int i=0;i<carte;i++)
        pesca(giocatore1);

    cout<<"Giocatore 2:"<<endl;
    for(int i=0;i<carte;i++)
        pesca(giocatore2);

    stampa(giocatore1,giocatore2);

    elem* primaGioc1 = NULL;
    elem* primaGioc2 = NULL;
    int lunghezzaGioc1 = 0, lunghezzaGioc2 = 0;

    primaGioc1 = scala(giocatore1,lunghezzaGioc1);
    primaGioc2 = scala(giocatore2,lunghezzaGioc2);

    cout<<"Giocatore1: ";
    while(primaGioc1 != NULL && tail(primaGioc1)->inf.seme == head(primaGioc1).seme){
        cout<<head(primaGioc1).valore<<head(primaGioc1).seme<<" ";
    }
    cout<<endl;

    cout<<"Giocatore2: ";
    while(primaGioc2 != NULL && tail(primaGioc2)->inf.seme == head(primaGioc2).seme){
        cout<<head(primaGioc2).valore<<head(primaGioc2).seme<<" ";
    }
    cout<<endl;
}
