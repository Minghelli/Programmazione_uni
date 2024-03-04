#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int riversamento(int[],int[],const int);

int main(){
    srand(time(0));
    const int MAXELEM = 10;
    int array[MAXELEM], arrayPari[MAXELEM];
    int dimensionePari,max;

    cout<<"Inserire valore massimo:"<<endl;
    cin>>max;


    for(short i=0;i<MAXELEM;i++){
        array[i] = rand()%max;
    }

    cout<<"Vettore totale: ";
    for(short i=0;i<MAXELEM;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

    dimensionePari = riversamento(array,arrayPari,MAXELEM);

    cout<<"Vettore pari: ";
    for(short i=0;i<dimensionePari;i++){
        cout<<arrayPari[i]<<" ";
    }
    cout<<endl;
}

int riversamento(int array[],int arrayPari[],const int dim){
    int dimPari = 0;
    for(short i=0;i<dim;i++){
        if(array[i]%2 == 0){
            arrayPari[dimPari] = array[i];
            dimPari++;
        }
    }
    return dimPari;
}