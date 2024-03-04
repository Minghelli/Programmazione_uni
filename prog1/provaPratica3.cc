#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef unsigned int u_int;
const int MAX = 15;
const char file[] = "prova.txt";

struct biglietto_t{
    char propietario[MAX+1];
    u_int numero;
};

struct lotteria_t{
    biglietto_t* biglietti;
    int nBiglietti = 0;
    int N = 0;
};

void allocaVettore(lotteria_t &l){
    int max;
    max = l.N * 2;
        
    biglietto_t* nuovo = new biglietto_t[max];

    for(int i=0;i<l.nBiglietti;i++)
        nuovo[i] = l.biglietti[i];
    
    if(l.N != 0)
        delete[] l.biglietti;
    l.biglietti = nuovo;
    l.N = max;
    delete[] nuovo;
}

bool vendiBiglietto(lotteria_t &l,char n[],u_int num){
    if(l.nBiglietti == l.N)
        allocaVettore(l);
    for(int i=0;i<l.nBiglietti;i++)
        if(l.biglietti[i].numero == num)
            return false;
    strcpy(l.biglietti[l.nBiglietti].propietario,n);
    l.biglietti[l.nBiglietti].numero = num;
    l.nBiglietti++;
    return true;
}

bool slavaBiglietti(lotteria_t &l){
    ofstream outF(file);
    if(!outF)
        return false;

    outF<<l.nBiglietti<<endl;
    outF<<l.N<<endl;
    for(int i=0;i<l.nBiglietti;i++)
        outF<<l.biglietti[i].propietario<<" "<<l.biglietti[i].numero<<endl;
    return true;
}

bool caricaLotteria(lotteria_t &l){
    int nuovoMax,nuovoNum;
    ifstream inF(file);
    if(!inF)
        return false;
    
    inF>>nuovoMax;
    
    if(l.N != 0)
        delete[] l.biglietti;
    
    if(nuovoMax > 0)
        l.biglietti = new biglietto_t[nuovoMax];
    l.N = nuovoMax;

    inF>>nuovoNum;
    l.nBiglietti = nuovoNum;

    for(int i=0;i<nuovoNum;i++){
        inF>>l.biglietti[i].propietario;
        inF>>l.biglietti[i].numero;
    }
    return true;
}

void stampa(lotteria_t l){
    for(int i=0;i<l.nBiglietti;i++)
        cout<<l.biglietti[i].propietario<<" "<<l.biglietti[i].numero<<endl;
    cout<<endl;
}

void estrai(lotteria_t l,int n){
    int vincitore;
    vincitore = rand()%n;
    cout<<"Vincitore:"<<endl;
    cout<<l.biglietti[vincitore].propietario<<" "<<l.biglietti[vincitore].numero<<endl<<endl;
}

void estraiN(lotteria_t l,int n){
    if(n >= l.nBiglietti)
        for(int i=0;i<l.nBiglietti;i++)
            estrai(l,l.nBiglietti);
    
    if(n < l.nBiglietti)
        for(int i=0;i<n;i++)
            estrai(l,n);
}

int main()
{
    srand(time(0));
    lotteria_t lotteria;
	const char menu[] =
		"1. Vendi biglietto\n"
		"2. Stampa biglietti venduti\n"
		"3. Salva biglietti venduti\n"
		"4. Carica biglietti venduti\n"
		"5. Stampa vincitore\n"
		"6. Stampa primi n vincitori\n"
		"7. Esci\n";

	while (true) {
		cout<<menu<<endl;
		int scelta;
		cin>>scelta;

		cout<<endl ; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1:
            char nome[MAX+1];
            u_int numero;
            cout<<endl<<"Inserisci nome: ";
            cin>>nome;
            cout<<"Numero: ";
            cin>>numero;
            if(!vendiBiglietto(lotteria,nome,numero))
                cout<<"Vendita fallita!"<<endl<<endl;
			break;
		case 2:
            stampa(lotteria);
			break;
		case 3:
            if(!slavaBiglietti(lotteria))
                cout<<"Salvataggio fallito!"<<endl<<endl;
            else
                cout<<"Salvataggio effettuato!"<<endl<<endl;
			break;
		case 4:
            if(!caricaLotteria(lotteria))
                cout<<"Caricamento fallito!"<<endl<<endl;
            else
                cout<<"Caricamento effettuato!"<<endl<<endl;
			break;
		case 5:
            if(lotteria.nBiglietti == 0){
                cout<<endl<<"NESSUNO 0"<<endl<<endl;
                break;
            }
            estrai(lotteria,lotteria.nBiglietti);
			break;
		case 6:
            int n;
            if(lotteria.nBiglietti == 0){
                cout<<endl<<"NESSUNO 0"<<endl<<endl;
                break;
            }
            cout<<"Quanri biglietti estrarre: ";
            cin>>n;
            estraiN(lotteria,n);
			break;
		case 7:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}
    return 1;
}