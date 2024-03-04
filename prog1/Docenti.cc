#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const char file[] = "dati.txt";
const int MAX = 10;
const int GG = 7;

struct docente_t {
    char nome[MAX];
    char turni[GG];
};

struct lavoro_t {
    docente_t * insegnanti;
    int N = 0;
};

bool inizializza(lavoro_t &l,int dim){
    if(dim <= 0)
        return false;
    if(dim != l.N && l.N > 0){
        delete[] l.insegnanti;
        l.N = 0;
    }

    l.N = dim;
    l.insegnanti = new docente_t[dim];
    
    cout<<"Inserisci nomi insegnanti:"<<endl;
    for(int i=0;i<l.N;i++){
        cout<<i+1<<": ";
        cin>>l.insegnanti[i].nome;
        for(int j=0;j<GG;j++)
            l.insegnanti[i].turni[j] = '-';
    }

    return true;
}

void stampa(lavoro_t l){
    cout<<"LMMGVSD"<<endl;
    for(int i=0;i<l.N;i++){
        cout<<l.insegnanti[i].turni<<" ";
        cout<<l.insegnanti[i].nome<<endl;
    }
}

int trova(lavoro_t &l, char nome[]){
    for(int i=0;i<l.N;i++)
        if(strcmp(l.insegnanti[i].nome,nome) == 0)
            return i;
    return -1;
}

bool aggiorna(lavoro_t &l,char nome[],char giorni[]){
    for(int i=0;i<l.N;i++)
        if(strcmp(l.insegnanti[i].nome,nome) == 0)
            for(int j=0;j<GG;j++)
                if(giorni[j] == '+')
                    l.insegnanti[i].turni[j] = '*';
    return true;
}

bool salva(lavoro_t &l){
    ofstream f(file);
    if(!f)
        return false;

    f<<l.N<<endl;
    /*for(int i=0;i<l.N;i++){
        f<<l.insegnanti[i].nome<<" ";
    }
    f<<endl;*/
    for(int i=0;i<l.N;i++){
        f<<l.insegnanti[i].turni<<" ";
    }
    return static_cast<bool>(f);
}

bool carica(lavoro_t &l){
    int dim;
    ifstream f(file);
    if(!f)
        return false;

    f>>dim;

}

int main(){
    lavoro_t lavoratori;
    char giorni[] = "LMMGVSD";
    int scelta;
    while(true){
        
        cout<<endl<<"1. Inizializza"<<endl
            <<"2. Stampa."<<endl
            <<"3. Trova Indice"<<endl
            <<"4. Aggiorna."<<endl
            <<"5: Salva"<<endl
            <<"6. Carica"<<endl
            <<"7. Minimizza"<<endl
            <<"8. Esci"<<endl<<endl;
            cin>>scelta;

            switch (scelta)
            {
            case 1:
                int numero;
                cout<<endl<<"Quanti lavoratori bisogna registrare? ";
                cin>>numero;
                if(!inizializza(lavoratori,numero))
                    cout<<"Errore."<<endl;
                else
                    cout<<"OK."<<endl;
                break;
            case 2:
                if(lavoratori.N == 0){
                    cout<<"Nessun Insegnante."<<endl;
                    break;
                }
                stampa(lavoratori);
                break;
            case 3:
                if(lavoratori.N == 0){
                    cout<<"Nessun Insegnante."<<endl;
                    break;
                }
                char lavDaTrovare[MAX];
                cout<<"Lavoratore da trovare: ";
                cin>>lavDaTrovare;
                if(trova(lavoratori,lavDaTrovare) == -1)
                    cout<<"lavoratore non trovato."<<endl;
                else
                    cout<<"Lavoratore presente in posizione: "<<trova(lavoratori,lavDaTrovare)<<"."<<endl;
                break;
            case 4:
                if(lavoratori.N == 0){
                    cout<<"Nessun Insegnante."<<endl;
                    break;
                }
                char nuoviTurni[GG];
                cout<<"Inserisci lavoratore al quale aggiornare i turni: ";
                cin>>lavDaTrovare;
                cout<<"Aggiorna con - o +"<<endl;
                for(int i=0;i<GG;i++){
                    cout<<giorni[i]<<": ";
                    cin>>nuoviTurni[i];
                }
                if(!aggiorna(lavoratori,lavDaTrovare,nuoviTurni))
                    cout<<"Errore."<<endl;
                else
                    cout<<"OK."<<endl;
                break;
            case 5:
                if(lavoratori.N == 0){
                    cout<<"Nessun Insegnante."<<endl;
                    break;
                }
                if(!salva(lavoratori))
                    cout<<"Errore."<<endl;
                else
                    cout<<"OK."<<endl;
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                return 0;
                break;
            default:
                break;
            }
    }
}