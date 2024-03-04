#include <iostream>
using namespace std;

void hanoi(int n,char s,char d,char a){
    if(n == 1)
        cout<<"Muovi dal piolo "<<s<<" al piolo "<<d;
    else{
        hanoi(n-1,s,a,d);
        cout<<"Muovi dal piolo "<<s<<" al piolo "<<d;
        hanoi(n-1,a,d,s);
    }
}

int main(){
    int n;
    cout<<"Inserisci numero di dischi: ";
    cin>>n;
    while(n<=0){
        hanoi(n,'S','A','D');
    }
}