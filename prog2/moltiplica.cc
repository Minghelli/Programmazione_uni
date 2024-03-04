#include <iostream>
using namespace std;

void aggiorna(unsigned int &l,unsigned int mas){
    if((l & mas) !=0)
        l = (l^mas);
}

int main(){
    int scelta;
    unsigned int lampioni = 255;
    unsigned int maschera = 0;
    while(true){
        cout<<"1. Guasto."<<endl
            <<"2. Ripara."<<endl
            <<"3. Stampa"<<endl
            <<"4. Risparmio"<<endl<<endl;
        cin>>scelta;

        switch(scelta){
            case 1:
                int posizione;
                cout<<"Posizione lampione guasto: ";
                cin>>posizione;
                maschera = 1<<posizione;
                aggiorna(lampioni,maschera);
                break;
            case 2:
                cout<<"Posizione lampione riparato: ";
                cin>>posizione;
                maschera = 1<<posizione;
                aggiorna(lampioni,maschera);
                break;
            case 3:
                for(int i=0;i<8;i++){
                    if((lampioni & 1<<i) !=0)
                        cout<<i<<" ";
                }
                cout<<endl;
                break;
            case 4:
            default:
                cout<<"brooo"<<endl;
        }
    }
}