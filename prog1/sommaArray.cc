#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int calcoloSomma(int [],const int);

int main(){
    srand(time(0));
    const int MAXELEM = 10;
    int array[MAXELEM];

    for(short i=0;i<MAXELEM;i++){
        array[i] = rand();
    }

    cout<<"Vettore totale: ";
    for(short i=0;i<MAXELEM;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

    cout<<"Somma del vettore: "<<calcoloSomma(array,MAXELEM)<<endl;
    
}

int calcoloSomma(int array[],const int dim){
    int somma = 0;
    for(short i=0;i<dim;i++){
        somma += array[i];
    }
    return somma;
}