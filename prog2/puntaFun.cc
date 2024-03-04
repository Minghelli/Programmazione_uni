#include <iostream>
using namespace std;

double f1(int n1,int n2){
    return n1+n2;
}

double f2(int n1,int n2){
    return n1-n2;
}

double f3(int n1,int n2){
    return n1*n2;
}

double f4(int n1,int n2){
    return n1/n2;
}

int main(){
    int scelta,n1,n2;
    cout<<"Inserisci numeri: "<<endl;
    cin>>n1;
    cin>>n2;
    cout<<"Operazione: "<<endl;
    cin>>scelta;
    
    double (*puntatore[4])(int,int) = {f1,f2,f3,f4};
    
    cout<<puntatore[scelta](n1,n2)<<endl;
}