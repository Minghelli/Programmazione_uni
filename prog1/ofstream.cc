#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    //Creo file
    ofstream scritturaFile("prova.txt");
    if(!scritturaFile)
        cerr<<"errore creazione file!"<<endl;

    cout<<"Inserisci il testo:"<<endl;

    char c;
    while(cin>>noskipws>>c)
        scritturaFile<<c;

    scritturaFile.close();

    ifstream letturaFile("prova.txt");

    if(!letturaFile)
        cerr<<"Errore in apertura file."<<endl;

    while(letturaFile>>noskipws>>c)
        cout<<c;
}