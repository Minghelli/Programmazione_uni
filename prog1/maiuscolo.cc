#include <iostream>
using namespace std;

char stampaMaiuscolo(char min){
    if(min < 'a' || min > 'z')
        return min;
    return min - 'a' + 'A';
}

int main(){
    char minuscolo;
    cout<<"Inserisci un carattere: ";
    cin>>minuscolo;

    cout<<stampaMaiuscolo(minuscolo)<<endl;
    return 0;
}