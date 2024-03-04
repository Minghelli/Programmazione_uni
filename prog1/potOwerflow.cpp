#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const int MAX_INT = 2147483647;

int potenza(int b,int e){
    if(pow(b,e) > MAX_INT)
        return -1;
    else
        return pow(b,e);
}

int main(){
    int base,esponente;
    cout<<"Inserisci base: ";
    cin>>base;
    cout<<"Inserisci esponente non negativo: ";
    do{
        cin>>esponente;
        if(esponente < 0)
            cout<<"Inserisci esponente corretto!!!: ";
    }while(esponente < 0);

    if(potenza(base,esponente) == -1)
        cout<<"ATENZIONE OVERFLOW"<<flush;
    else
        cout<<potenza(base,esponente)<<endl;
}