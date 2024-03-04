#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX_NOME = 30;
const int MAX = 100;

struct partecipante{
        char nominativo[MAX_NOME];
        int tempo;
    } persone[MAX],scambio;

void ordinamentoAlfa(int dim){
    bool controllo;
    do{
        controllo = true;
        for(short i=0;i<dim-1;i++){
            if(strcmp(persone[i].nominativo,persone[i+1].nominativo) > 0){
                scambio = persone[i];
                persone[i] = persone[i+1];
                persone[i+1] = scambio;
                controllo = false;
            }
        }
    }while(!controllo);
}
void ordinamentoTempo(int dim){
    bool controllo;
    do{
        controllo = true;
        for(short i=0;i<dim-1;i++){
            if(persone[i].tempo > persone[i+1].tempo){
                scambio = persone[i];
                persone[i] = persone[i+1];
                persone[i+1] = scambio;
                controllo = false;
            }
        }
    }while(!controllo);
}
void disiscrizione(char nome[],int dim){
    for(short i=0;i<dim;i++)
        if(strcmp(nome,persone[i].nominativo) == 0)
            for(short j=i;j<dim-1;j++)
                persone[j] = persone[j+1];
}

void conversione(char nome[]){
    nome[0] = toupper(nome[0]);
    for(short i=1;i<static_cast<short>(strlen(nome));i++)
        nome[i] = tolower(nome[i]);
}

void leggiNome(char nominativo[]){
    char nome[MAX_NOME] = "";
    char cognome[MAX_NOME] = "";

    cout<<"Nome: ";
    cin>>nome;
    cout<<"Cognome: ";
    cin>>cognome;

    conversione(nome);
    conversione(cognome);

    strcpy(nominativo,nome);
    
    nominativo[strlen(nominativo) +1] = '\0';
    nominativo[strlen(nominativo)] = ' ';

    strcat(nominativo,cognome);
}

int main()
{
    srand(time(0));
    int scelta,nPersone=-39,min,sec,contaPersone = 0;
    char nominativo[MAX_NOME];

    while (true) {
        cout<<"Gestione classifica\n";
        cout<<"Menu\n";
        cout<<"1 Inserimento di un nuovo partecipante\n";
        cout<<"2 Disiscrizione di un partecipante\n";
        cout<<"3 Stampa elenco partecipanti\n";
        cout<<"4 Gara\n";
        cout<<"5 Stampa classifica\n";
        cout<<"6 Uscita\n";
        cin>>scelta;
        switch(scelta){
            case 1:
                cout<<endl;
                if(contaPersone > 100){
                    cout<<"Elenco pieno!!"<<endl<<endl;
                    break;
                }
                cout<<"Quanti sono? ";
                cin>>nPersone;
                cout<<endl<<"Inserisci i nomi:"<<endl;
                for(short i=0;i<nPersone;i++){
                    leggiNome(nominativo);
                    strcpy(persone[contaPersone].nominativo,nominativo);
                    contaPersone++;
                }
                cout<<endl;
                break;
            case 2:
                if(contaPersone == 0){
                    cout<<endl<<"Non c'è nessuno!!"<<endl<<endl;
                    break;
                }
                cout<<endl<<"Chi pacca? ";
                leggiNome(nominativo);
                disiscrizione(nominativo,contaPersone);
                contaPersone--;
                cout<<"Partecipante disiscritto."<<endl<<endl;
                break;
            case 3:
                ordinamentoAlfa(contaPersone);
                cout<<endl<<contaPersone<<" partecipanti:"<<endl;
                for(short i=0;i<contaPersone;i++){
                    cout<<i+1<<": "<<persone[i].nominativo<<endl;
                }
                cout<<endl;
                break;
            case 4:
                cout<<endl;
                if(contaPersone <= 0){
                    cout<<"Inserire prima i partecipanti!!"<<endl<<endl;
                    break;
                }
                for(short i=0;i<contaPersone;i++){
                    min = rand()%2+1;
                    sec = rand()%60;
                    persone[i].tempo = min*60 + sec;
                }
                cout<<"Gara in corso..."<<endl;
                system("sleep 5");
                cout<<"Gara terminata! Controlla la classifica!"<<endl<<endl;
                //system("pause");
                break ;
            case 5:
                ordinamentoTempo(contaPersone);
                cout<<endl;
                if(contaPersone <= 0){
                    cout<<"Inserire prima i partecipanti!!"<<endl<<endl;
                    break;
                }
                cout<<"Classifica completa:"<<endl;
                for(short i=0;i<contaPersone;i++)
                    cout<<i+1<<char(41)<<" "<<persone[i].nominativo<<": "
                        <<persone[i].tempo/60<<"m"
                        <<persone[i].tempo%60<<"s"<<endl;
                cout<<endl;
                break ;
            case 6:
                return 0 ;
            default:
                cout<<endl<<"Inserisci amodo!"<<endl<<endl;
                continue;
        } // Fine switch
    } // Fine while
    return 0 ;
}
