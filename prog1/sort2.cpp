#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int calcoloSomma(int [],const int);

int main(){
    const int M = 6;
    const int N = 4;

    int vett1[M] = {3,5,7,12,18,23};
    int vett2[N] = {4,6,8,9};
    int vettTot[M+N];

    for(short i=0;i<M+N;i++){
        if(i > M)
            vettTot[i] = vett2[i-M];
        else
            vettTot[i] = vett1[i];
        
    }
    
    for(short i=0;i<M+N;i++)
        cout<<vettTot[i]<<" ";
    cout<<endl;
}
