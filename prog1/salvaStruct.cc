#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const char file[] = "dati.bin";
const int MAX = 20;

struct studente_t{
    char nome[MAX];
    char cognome[MAX];
    int matricola;
};

int main(){
    studente_t stud1 = {"Bughino","Ganino",1345};
    studente_t stud2 = {"Bugone","Ganone",1654};

    ofstream outFile(file);

    outFile.write(reinterpret_cast<char*>(&stud1),sizeof(studente_t));
    outFile.write(reinterpret_cast<char*>(&stud2),sizeof(studente_t));

    outFile.write(reinterpret_cast<char*>(&stud2.matricola),sizeof(stud2.matricola));
    outFile.write(stud2.nome,sizeof(stud2.nome));
    outFile.write(stud2.cognome,sizeof(stud2.cognome));

    outFile.close();

    ifstream inFile(file);

    inFile.read(reinterpret_cast<char*>(&stud1),sizeof(studente_t));
    inFile.read(reinterpret_cast<char*>(&stud2),sizeof(studente_t));

    cout<<"Nome 1 : "<<stud1.nome<<endl;
    cout<<"Cognome 1 : "<<stud1.cognome<<endl;
    cout<<"Matricola 1 : "<<stud1.matricola<<endl;
    cout<<"Nome 2 : "<<stud2.nome<<endl;
    cout<<"Cognome 2 : "<<stud2.cognome<<endl;
    cout<<"Matricola 2 : "<<stud2.matricola<<endl;
}