#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int contaVolte(int x,int v[],int n){
    int conta = 0;
    for(short i=0;i<n;i++){
        if(v[i] == x)
            conta++;
    }
    return conta;
}

int creaUnici(int v[],int vu[],int n){
    int nUnici = 0;
    for(short i=0;i<n;i++)
        if(contaVolte(v[i],v,n) == 1)
            vu[nUnici++] = v[i];
    return nUnici;
}

int main(){
    srand(time(0));
    const int DIM = 10;
    int vettore[DIM];
    int vettoreUnici[DIM];
    short dimVettoreUnici;

    for(short i=0;i<DIM;i++)
        vettore[i] = rand()%20+1;

    cout<<endl<<"Vettore generato: ";
    for(short i=0;i<DIM;i++)
        cout<<vettore[i]<<" ";
    cout<<endl;

    dimVettoreUnici = creaUnici(vettore,vettoreUnici,DIM);

    cout<<"Vettore elementi unici: ";
    for(short i=0;i<dimVettoreUnici;i++){
        cout<<vettoreUnici[i]<<" ";
    }
    cout<<endl<<endl;
}