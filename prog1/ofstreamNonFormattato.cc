#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream outFile("Testo.txt");
    if(!outFile){
        cerr<<"Errore creazione file."<<endl;
        return -1;
    }

    char c;
    while(cin.get(c)){
        outFile<<c;
    }

    outFile.close();

    ifstream inFile("Testo.txt");
    if(!inFile){
        cerr<<"Errore lettura file."<<endl;
        return -1;
    }

    int righe = 0;
    cout<<endl;
    while(inFile.get(c)){
        cout<<c;
        if(c == '\n')
            righe++;
    }

    cout<<endl<<righe<<" righe."<<endl;
    return 0;
}