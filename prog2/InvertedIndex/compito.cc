#include <iostream>
#include <fstream>
#include <cstring>
#include "tipo.h"
#include "liste.h"
#include "parola.h"
using namespace std;

parola_t* load(int& dim){
    ifstream in("inverted.txt");
    
    int nDoc = 0;
    char par[80];
    in>>dim;

    parola_t* parole = new parola_t[dim];
    for(int i=0;i<dim;i++){
        in>>par;
        in>>nDoc;
        strcpy(parole[i].parola,par);
        parole[i].nDoc = nDoc;
        parole[i].l = NULL;
        for(int j=0;j<nDoc;j++){
            int doc;
            in>>doc;
            elem_t* elem = new elem_t;
            elem = nuovoElemento(doc);
            parole[i].l = inserisci(parole[i].l,elem);
        }
    }
    in.close();
    return parole;
}

void stampa(parola_t* p,int dim){
    for(int i=0;i<dim;i++){
        cout<<p[i].parola<<endl;
        lista l = p[i].l;
        while(l != NULL){
            cout<<head(l)<<endl;
            l = tail(l);
        }
    }
    cout<<endl;
}

void update(parola_t* &p,char file[],int& n){
    ifstream in(file);
    int id = 0;
    in>>id;

    while(in.good()){
        char par[80];
        in>>par;
        int i = 0;
        bool pres = false;
        while(i < n && !pres){
            if(strcmp(par,p[i].parola) == 0){
                elem_t* newElem = new elem_t;
                p[i].l = inserisci(p[i].l,nuovoElemento(id));
                pres = true;
            }
            i++;
        }
        if(!pres){
            n++;
            parola_t* temp = new parola_t[n];
            for(int i=0;i<n-1;i++){
                temp[i] = p[i];
            }
            p = new parola_t[n];
            for(int i=0;i<n-1;i++){
                p[i] = temp[i];
            }
            delete[] temp;
            strcpy(p[i].parola,par);
            p[i].nDoc = 1;
            p[i].l = NULL;
            p[i].l = inserisci(p[i].l,nuovoElemento(id));
        }
    }
}

void AND(parola_t* p,char w1[],char w2[],int n){
    lista occorrenzeW1 = NULL;
    lista occorrenzeW2 = NULL;
    for(int i=0;i<n;i++){
        if(strcmp(p[i].parola,w1) == 0)
            occorrenzeW1 = p[i].l;
        if(strcmp(p[i].parola,w2) == 0)
            occorrenzeW2 = p[i].l;
    }
    while(occorrenzeW2 != NULL){
        if(search(occorrenzeW1,head(occorrenzeW2) != NULL))
            cout<<head(occorrenzeW2)<<" ";
        occorrenzeW2 = tail(occorrenzeW2);
    }
}

int main(){
    int dimensione;

    parola_t* invertedIndex = load(dimensione);
    stampa(invertedIndex,dimensione);

    char file[256] = "doc.txt";
    update(invertedIndex,file,dimensione);
    stampa(invertedIndex,dimensione);

    char par1[80],par2[80];
    cout<<"Inserisci prima parola da cercare: ";
    cin>>par1;
    cout<<"Inserisci seconda parola da cercare: ";
    cin>>par2;
    AND(invertedIndex,par1,par2,dimensione);

}