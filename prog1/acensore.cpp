#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
enum dir {up, down};

const short POSMAX = 20;
const short POSMIN = -20;

float singoloImpulso(float pos,dir direz){
    if(direz == down)
        return pos-0.1;
    return pos+0.1;
}

int main(){
    float posizione = 0;
    short spostamento;
    dir direzione;

    cout<<"Inserisci spostamenti: ";
    while(true){
        cin>>spostamento;

        direzione = spostamento < 0 ? down : up;

        for(short i=0;i<abs(spostamento);i++)
            posizione=singoloImpulso(posizione,direzione);

        if(posizione > POSMAX)
            posizione = POSMAX;
        if(posizione < POSMIN)
            posizione = POSMIN;

        cout<<"Posizione attuale: "<<setprecision(2)<<posizione<<endl;
        if(posizione < 1.01 && posizione > -0.01)
            cout<<"Non staccare le funi."<<endl;
        else
            cout<<"Puoi staccare le funi."<<endl;
    }
}