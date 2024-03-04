#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void inizializza(int vp[],int n){
    for(short i=0;i<n;i++)
        vp[i] = -1;
}

void init(int v[],int vp[],int n){
    int contaPari = 0;
    for(short i=0;i<n;i++)
        if(v[i]%2 == 0)
            vp[contaPari++] = v[i];
}

int main(){
    srand(time(0));
    const int DIM = 10;
    int vettore[DIM];
    int vettorePari[DIM];

    inizializza(vettorePari,DIM);

    for(short i=0;i<DIM;i++)
        vettore[i] = rand()%20+1;

    cout<<endl<<"Vettore generato: ";
    for(short i=0;i<DIM;i++)
        cout<<vettore[i]<<" ";
    cout<<endl;

    init(vettore,vettorePari,DIM);

    cout<<endl<<"Vettore pari: ";
    for(short i=0;i<DIM;i++){
        if(vettorePari[i] == -1)
            break;
        cout<<vettorePari[i]<<" ";
    }
    cout<<endl;
}
