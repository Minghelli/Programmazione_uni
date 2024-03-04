#include <iostream>
#include <cstdlib>
#include <ctime>
#define DIM 15
using namespace std;

int contaVolte(int v[],int x){
    int conta = 0;
    for(short i=0;i<DIM;i++){
        if(v[i] == x)
            conta++;
    }
    return conta;
}

int main(){
    srand(time(0));
    int vettore[DIM];
    int elementoMax,nVolte = 0;

    for(short i=0;i<DIM;i++)
        vettore[i] = rand()%20+1;

    cout<<endl<<"Vettore generato: ";
    for(short i=0;i<DIM;i++)
        cout<<vettore[i]<<" ";
    cout<<endl;

    for(short i=0;i<DIM;i++){
        if(contaVolte(vettore,vettore[i]) > nVolte){
            nVolte = contaVolte(vettore,vettore[i]);
            elementoMax = vettore[i];
        }
    }

    cout<<"L'elemento più ripetuto è: "<<elementoMax<<" con "<<nVolte<<" ripetizioni."<<endl<<endl;
    return 0;
}