#include <iostream>

#include <cstring>
#include "carta.h"
#include "bst.h"
using namespace std;

int totPunti(bst a,int in,int sup){
    int tot = 0;
    while(a != NULL && get_key(a) > in){
        a = get_left(a);
    }

	while(a != NULL && get_key(a) <= sup){
        tot += get_value(a).punti;
        a = get_right(a);
    }
	return tot;
}

bool aggiorna(bst a,int c,int p){
    bnode* n = bst_search(a,c);
    if(n == NULL)
        return false;

    n->inf.punti += p;
    return true;
}

int main(){
    //Punto 1
    int n;
    cout<<"Numero di carte da inserire: ";
    cin>>n;

    bst albero = NULL;
    tipo_inf dati;
    tipo_key codice;
    for(int i=0;i<n;i++){
        cout<<"Codice carta "<<i+1<<": ";
        cin>>codice;
        cout<<"Nome e cognome: ";
        cin.ignore();
        cin.getline(dati.nominativo,40);
        cout<<"Tot. punti: ";
        cin>>dati.punti;

        bnode* n = bst_newNode(codice,dati);
        bst_insert(albero,n);
    }

    //Punto 2
    stampa(albero);

    //Punto 2b
    int n1,n2;
    cout<<"Inserisci 2 numeri di carte:"<<endl;
    cin>>n1>>n2;

    cout<<totPunti(albero,n1,n2)<<endl;

    //Punto 3
    
    int punti,i=0;
    int acquisti[n];

    for(int i=0;i<n;i++){
        acquisti[i] = 0;
    }

    cout<<"Inserire dati d'acquisto (Premere 'e' per terminare):"<<endl;
    while(cin>>codice){
        cin>>punti;
        if(!aggiorna(albero,codice,punti))
            cout<<"Errore, carta non presente."<<endl;
        else
            acquisti[i++] = codice;
    }

    stampa(albero);

    //Punto 4;
    cout<<"Carte che non hanno fatto acquisti:"<<endl;
    stampaNonAggiornati(albero,acquisti,n);
}