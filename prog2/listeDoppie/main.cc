#include <iostream>
#include "tipo.h"
#include "liste.h"
#include "funzioniApp.h"
using namespace std;

int main(){
    int scelta;
    lista miaLista;
    while(true){
        cout<<"1 Crea."<<endl
            <<"2 Stampa."<<endl
            <<"3 Elimina."<<endl
            <<"4 Elminia lista."<<endl
            <<"5 Palindroma e altri"<<endl
            <<"6 Esci."<<endl<<endl;
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
                cout<<"Stampa normale:"<<endl;
                stampa(miaLista);
                cout<<"Stampa ricorsiva:"<<endl;
                stampaRic(miaLista);
                break;
            case 3:
                int valore;
                cout<<"Valore dell'elemento da eliminare: ";
                cin>>valore;
                miaLista = cancella(miaLista,valore);
                cout<<endl;
                break;
            case 4:
                eliminaLista(miaLista);
                cout<<endl<<"Lista cancellata."<<endl<<endl;
                break;
            case 5:
                if(palindroma(miaLista))
                    cout<<"Lista Palindroma."<<endl<<endl;
                else
                    cout<<"Lista non palindroma."<<endl<<endl;
                break;
            case 6:
                return 0;
            default:
                cout<<"brooo";
        }
    }
}