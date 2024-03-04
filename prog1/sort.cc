#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void sort(double v[],const int m){
    bool end;
    do{
        end = true;
        for(short i=0;i<m-1;i++){
            if(v[i] > v[i+1]){
                int aus = v[i];
                v[i] = v[i+1];
                v[i+1] = aus;
                end = false;
            }
        }
    }while(!end);
}

int main(){
    srand(time(0));
    const int MAX = 5;
    double vettore[MAX];
    short i;

    for(i=0;i<MAX;i++){
        vettore[i] = rand()%10+1;
    }

    cout<<"Vettore generato: ";
    for(i=0;i<MAX;i++){
        cout<<vettore[i]<<" ";
    }
    cout<<endl;

    sort(vettore,MAX);

    cout<<"Vettore ordinato: ";
    for(i=0;i<MAX;i++){
        cout<<vettore[i]<<" ";
    }
    cout<<endl;
}