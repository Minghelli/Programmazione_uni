#include <iostream>
#include <cmath>
using namespace std;

int main(){
    short nEquazioni;
    cout<<"Numero equazioni: ";
    cin>>nEquazioni;

    for(short i;i<nEquazioni;i++){
        double a,b,c,delta,radice1,radice2;

        cout<<"Inserisci i 3 coefficenti:"<<endl;
        cin>>a>>b>>c;

        delta = b*b-4*a*c;

        radice1 = (-b+sqrt(delta))/(2*a);
        radice2 = (-b-sqrt(delta))/(2*a);

        if(static_cast<int>(sqrt(delta)) == sqrt(delta))
            cout<<"L'equazione è degenere."<<endl;

        if(delta<0)
            cout<<"L'equazione non ha radici reali."<<endl;
        else if(radice1 == radice2)
            cout<<"L'equazione ha una radice: "<<radice1<<"."<<endl;
        else{ 
            cout<<"L'equazione ha 2 radici:"<<endl;
            cout<<"1: "<<radice1<<endl;
            cout<<"2: "<<radice2<<endl;
        }
    }
}