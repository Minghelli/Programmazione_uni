#include <iostream>
#include <fstream>
using namespace std;

const char file[] = "prova.txt";

struct coda_t{
    char *utenti;
    unsigned int nUtenti = 0;
    unsigned int N = 0;
};

bool inizializza(coda_t &c,unsigned int n){
    if(n < 0)
        return false;
    if(n != c.N && c.N > 0){
        delete[] c.utenti;
        c.nUtenti = c.N = 0;
    }
    if(n > 0 && c.N == 0){
        c.utenti = new char[n];
        c.N = n;
    }
    return true;
}

bool accoda(coda_t &c,char cod){
    if(c.nUtenti == c.N)
        return false;
    c.utenti[c.nUtenti] = cod;
    c.nUtenti++;
    return true;
}

void stampaCoda(coda_t c){
    for(unsigned int i=0;i<c.nUtenti;i++)
        cout<<c.utenti[i]<<" ";
    cout<<endl<<endl;
}

bool salvaCoda(coda_t &c){
    ofstream outF(file);
    if(!outF)
        return false;

    outF<<c.nUtenti<<endl;
    outF<<c.N<<endl;
    for(unsigned int i=0;i<c.nUtenti;i++)
        outF<<c.utenti[i];
    return true;
}

bool caricaCoda(coda_t &c){
    unsigned int N,num;
    ifstream inF(file);
    if(!inF)
        return false;

    inF>>N;
    if(!inizializza(c,N))
        return false;
    inF>>num;
    char car;
    for(unsigned int i=0;i<num;i++){
        inF>>car;
        if(!accoda(c,car))
            return false;
    }
    return true;
}

char serviUtente(coda_t &c){
    char cod;
    cod = c.utenti[0];
    for(unsigned int i=0;i<c.nUtenti-1;i++)
        c.utenti[i] = c.utenti[i+1];
    c.nUtenti--;
    return cod;
}

bool anticipaServizio(coda_t &c,char cod){
    char scambio;
    bool ordine,fine=true;
    int cont = 0;
    for(unsigned int i=0;i<c.nUtenti;i++)
        if(c.utenti[i] == cod)
            cont++;
    do{
        ordine = true;
        for(unsigned int i=0;i<c.nUtenti-1;i++){
            for(short i=0;i<cont-1;i++){
                fine = false;
                if(c.utenti[i] == c.utenti[i+1])
                    fine = true;
            }

            if(fine)
                continue;

            if(c.utenti[i+1] == cod){
                scambio = c.utenti[i];
                c.utenti[i] = c.utenti[i+1];
                c.utenti[i+1] = scambio;
                ordine = false;
            }
        }
    }while(!ordine);
    
    if(cont == 0)
        return false;
    return true;
}

int main()
{
    coda_t coda;
	const char menu[] =
		"1. Reinizializza coda\n"
		"2. Accoda utente\n"
		"3. Stampa coda\n"
		"4. Salva coda\n"
		"5. Carica coda\n"
		"6. Servi prossimo utente\n"
		"7. Anticipa servizio\n"
		"8. Esci\n";

	while (true) {
		cout<<menu<<endl;
		int scelta;
        bool ins = false;
		cin>>scelta;

		cout<<endl ; // per il corretto funzionamento del tester

		switch (scelta) {
            case 1:
                unsigned int lunghezza;
                cout<<"Inserisci lunghezza massima coda: ";
                cin>>lunghezza;
                if(!inizializza(coda,lunghezza))
                    cout<<"Errore inizializzazione."<<endl<<endl;
                cout<<endl;
                break;
            case 2:
                char codice;
                cout<<"Inserisci codice utente MAIUSCOLO: ";
                do{
                    cin>>codice;
                    if(codice < 'A' || codice > 'Z')
                        cout<<"Reinserisci maiuscolo: ";
                    else
                        ins = true;
                }while(!ins);
                if(!accoda(coda,codice))
                    cout<<"Errore! massimo numero di utenti raggiunto."<<endl<<endl;
                break;
            case 3:
                if(coda.nUtenti == 0){
                    cout<<"Coda vuota."<<endl<<endl;
                    break;
                }
                stampaCoda(coda);
                break;
            case 4:
                if(!salvaCoda(coda))
                    cerr<<"Errore nel salvataggio! Ritentare."<<endl<<endl;
                break;
            case 5:
                if(!caricaCoda(coda))
                    cerr<<"Errore nel Caricamento! Ritentare."<<endl<<endl;
                break;
            case 6:
                cout<<"Utente "<<serviUtente(coda)<<" servito."<<endl<<endl;
                break;
            case 7:
                //char codice;
                ins = false;
                cout<<"Inserisci codice da anticipare: ";
                do{
                    cin>>codice;
                    if(codice < 'A' || codice > 'Z')
                        cout<<"Reinserisci maiuscolo: ";
                    else
                        ins = true;
                }while(!ins);
                if(!anticipaServizio(coda,codice))
                    cerr<<"Spiacente! il codice non risulta in coda."<<endl<<endl;
                else
                    cout<<"Servizio anticipato!"<<endl<<endl;
                break;
            case 8:
                delete[] coda.utenti;
                return 0;
            default:
                cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}