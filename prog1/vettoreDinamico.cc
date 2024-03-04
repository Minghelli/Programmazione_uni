#include <iostream>
using namespace std;

int * fun(int &d){
    cin>>d;
    int * p = new int[d];
    for(short i=0;i<d;i++)
        cin>>p[i];
    return p;
}

int main(){
    int * vett;
    int dim;
    vett = fun(dim);
    for(short i=0;i<dim;i++)
        cout<<vett[i]<<" ";
    cout<<endl;
    delete[] vett;
}