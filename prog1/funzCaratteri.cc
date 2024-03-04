#include <iostream>
#include <cmath>
using namespace std;

bool alfanum(char);
bool alfabetico(char);
bool cifra_dec(char);
bool cifra_esadec(char);
char minuscolo(char);
char maiuscolo(char);

int main(){
    char carattere;
    cin>>carattere;

    cout<<"Alfanumerico: "<<alfanum(carattere)<<endl;
    cout<<"Alfabetico: "<<alfabetico(carattere)<<endl;
    cout<<"Decimale: "<<cifra_dec(carattere)<<endl;
    cout<<"Esadecimale: "<<cifra_esadec(carattere)<<endl;
    cout<<"Minuscolo: "<<minuscolo(carattere)<<endl;
    cout<<"Maiuscolo: "<<maiuscolo(carattere)<<endl;
}

bool alfanum(char c){
    if(c >= '0' && c <= '9' || 
        c >= 'a' && c <= 'z' || 
        c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

bool alfabetico(char c){
    if(c >= 'a' && c <= 'z' || 
        c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

bool cifra_dec(char c){
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}

bool cifra_esadec(char c){
    if(c >= '0' && c <= '9' || c >= 'A' && c <= 'F')
        return 1;
    return 0;
}

char maiuscolo(char c){
    if(c < 'a' || c > 'z')
        return c;
    return c - 'a' + 'A';
}

char minuscolo(char c){
    if(c < 'A' || c > 'Z')
        return c;
    return c - 'A' + 'a';
}