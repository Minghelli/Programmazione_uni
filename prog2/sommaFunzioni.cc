#include <iostream>
using namespace std;

int f1(int n){
    return n*2;
}

int somma(int(*punt)(int),int n){
    int cont = 0;
    for(int i=1;i<=n;i++)
        cont += punt(i);
    return cont;
}

int main(){
    int n=10;
    cout<<somma(f1,n)<<endl;
}