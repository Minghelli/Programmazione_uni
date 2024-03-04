#include <iostream>
using namespace std;

struct elem_t {
    int elemento;
    elem_t* next;
};

typedef elem_t* lista;

int testa(lista l){
    return l->elemento;
}

lista coda(lista l){
    return l->next;
}

lista inserisci(lista l,elem_t* ele){
    ele->next = l;
    return ele;
}

elem_t* search(lista l,int val){
    while(l != NULL)
        if(testa(l) == val)
            return l;
        else
            l = coda(l);
    return NULL;
}

lista cancella(lista l,elem_t* ele){
    if(ele==l)
        l = coda(l);
    else{
        lista l1 = l;
        while(ele != coda(l1))
            l1 = coda(l1);
        l1->next = coda(ele);
    }
    delete ele;
    return l;
}

void stampa(lista l){
    while(l != NULL){
        cout<<testa(l)<<" ";
        l = coda(l);
    }
    cout<<endl;
}

lista creaLista(int n){
    lista nuova = NULL;
    for(int i=0;i<n;i++){
        elem_t* nuovoElemento = new elem_t;
        cout<<"Elemento: "<<i+1<<": ";
        cin>>nuovoElemento->elemento;
        nuova = inserisci(nuova,nuovoElemento);
    }
    return nuova;
}

void eliminaLista(lista &l){
    while(l != NULL)
        l = cancella(l,l);
}

lista sommaElemento(lista& l,int pos){
    elem_t* l1 = l;
    elem_t* l2 = l;
    int v;
    for(int i=0;i<pos;i++)
        l1 = coda(l1);
    v = testa(l1);
    while(l != NULL){
        l->elemento += v;
        l = coda(l);
    }
    return l2;
}

int main(){
    int scelta;
    lista miaLista;
    while(true){
        cout<<"1 Crea."<<endl
            <<"2 Stampa."<<endl
            <<"3 Elimina."<<endl
            <<"4 Elminia lista."<<endl
            <<"5 Somma elemento."<<endl
            <<"6 Esci."<<endl;
        cin>>scelta;
        switch(scelta){
            case 1:
                int numElementi;
                cout<<"Numero di elementi: ";
                cin>>numElementi;
                miaLista = creaLista(numElementi);
                cout<<endl;
                break;
            case 2:
                stampa(miaLista);
                cout<<endl;
                break;
            case 3:
                int valore;
                cout<<"Valore dell'elemento da eliminare: ";
                cin>>valore;
                miaLista = cancella(miaLista,search(miaLista,valore));
                cout<<endl;
                break;
            case 4:
                eliminaLista(miaLista);
                cout<<endl<<"Lista cancellata."<<endl<<endl;
                break;
            case 5:
                miaLista = sommaElemento(miaLista,2);
                cout<<"Nuova lista: ";
                stampa(miaLista);
                break;
            case 6:
                return 0;
            default:
                cout<<"brooo";
        }
    }
}