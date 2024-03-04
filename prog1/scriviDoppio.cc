#include <iostream>
#include <fstream>
using namespace std;

int main(){
    const int dim = 5;
    double vettore[dim] = {3.4,4.5,6,2,3.8};

    //Creazione file di testo
    ofstream outFileTxt("dati.txt");
    if(!outFileTxt){
        cerr<<"Errore creazione file output!"<<endl;
        return -1;
    }

    //Riempimento file di testo
    for(short i=0;i<dim;i++)
        outFileTxt<<vettore[i]<<" ";

    //Creazione file binario
    ofstream outFileBin("dati.bin");
    if(!outFileBin){
        cerr<<"Errore creazione file output!"<<endl;
        return -1;
    }

    //Riempimento file binario
    outFileBin.write(reinterpret_cast<char*>(vettore),sizeof(double)*dim);

    //Chiusura entrambi file
    outFileTxt.close();
    outFileBin.close();

    //Creazione file di lettura
    ifstream inFileTxt("dati.txt");
    ifstream inFileBin("dati.bin");
    if(!inFileTxt || !inFileBin){
        cerr<<"Errore lettura file!"<<endl;
        return -1;
    }

    //lettura file di testo
    double num;
    while(inFileTxt>>num)
        cout<<num<<" ";
    cout<<endl;

    //Lettura file binario
    double buffer[dim];
    inFileBin.read(reinterpret_cast<char*>(buffer),sizeof(double)*dim);

    for(short i=0;i<dim;i++)
        cout<<buffer[i]<<" ";
    cout<<endl;
    return 0;
}