#include <iostream>
#include <fstream>
using namespace std;

typedef unsigned int u_int;

const char file[] = "dati.txt";

struct memoria_t{
    char *memoria;
    u_int dimensione = 0;
};

bool inizializza(memoria_t &m,u_int dim){
    if(m.dimensione != 0 && dim > 0){
        delete[] m.memoria;
        m.dimensione = 0;
    }

    m.memoria = new char[dim];
    m.dimensione = dim;
	for(u_int i=0;i<m.dimensione;i++)
		m.memoria[i] = '-';
    return true;
}

bool allocaOggetto(memoria_t &m,u_int pos,u_int dim){
	bool controllo = true;
	if(pos + dim > m.dimensione || pos > m.dimensione)
		return false;
	for(u_int i=pos;i<pos+dim;i++)
		if(m.memoria[i] == '*')
			controllo = false;
	
	if(controllo){
		for(u_int i=pos;i<pos+dim;i++)
			m.memoria[i] = '*';
		return true;
	}
	else
		return false;
}

void stampaMemoria(memoria_t m){
	u_int cont = 0;
	cout<<endl;
	for(u_int i=0;i<m.dimensione;i++){
		cout<<cont;
		cont++;
		if(cont == 10)
			cont = 0;
	}
	cout<<endl;
	for(u_int i=0;i<m.dimensione;i++)
		cout<<m.memoria[i];
	cout<<endl<<endl;
}

bool salva(memoria_t &m){
	ofstream out(file);
	if(!out)
		return false;

	out<<m.dimensione<<endl;
	for(u_int i=0;i<m.dimensione;i++)
		out<<m.memoria[i];
	
	out.close();

	return static_cast<bool>(out);
}

bool carica(memoria_t &m){
	ifstream in(file);
	if(!in)
		return false;

	u_int nuovaDim;
	in>>nuovaDim;

	if(inizializza(m,nuovaDim))
		for(u_int i=0;i<nuovaDim;i++)
			in>>m.memoria[i];

	return static_cast<bool>(in);
}

bool allocaOggetto2(memoria_t &m,u_int pos,u_int dim){
	u_int cont = 0,cont2 = 0;
	if(pos + dim > m.dimensione || pos > m.dimensione)
		return false;
		
	for(u_int i=0;i<pos;i++)
		if(m.memoria[i] == '*')
			cont2++;

	if(cont2 > 0)
		for(u_int i=0;i<pos;i++)
			m.memoria[i] = '-';

	for(u_int i=pos;i<m.dimensione;i++){
		if(m.memoria[i] == '*'){
			for(u_int j=i;j<m.dimensione;j++)
				if(m.memoria[j] == '-'){
					m.memoria[j] = '*';
					cont++;
					break;
				}
			if(cont == dim+cont2)
				break;
		}
		else{
			m.memoria[i] = '*';
			cont++;
		}
	}
			
	return true;
}

int main()
{
    memoria_t allocatore;
	const char menu[] =
		"1. Reinizializza memoria\n"
		"2. Stampa memoria\n"
		"3. Alloca oggetto\n"
		"4. Salva memoria\n"
		"5. Carica memoria\n"
		"6. Alloca oggetto 2\n"
		"7. Esci\n";

	while (true) {
		cout<<menu<<endl;
		int scelta;
		cin>>scelta;

		cout<<endl ; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1:
            u_int dimensione;
            cout<<"Inserisci dimensione: ";
            cin>>dimensione;
			if(!inizializza(allocatore,dimensione))
				cerr<<"Errore."<<endl<<endl;
			else
				cout<<"Inizializzato ben."<<endl<<endl;
			break;
		case 2:
			if(allocatore.dimensione == 0){
				cerr<<"Allocatore vuoto."<<endl<<endl;
				break;
			}
			stampaMemoria(allocatore);
			break;
		case 3:
			u_int posizione;
			cout<<"Posizione da occupare: ";
			cin>>posizione;
			cout<<"Dimensione dell'oggetto: ";
			cin>>dimensione;
			if(!allocaOggetto(allocatore,posizione,dimensione))
				cerr<<"Errore."<<endl<<endl;
			else
				cout<<"Allocato ben."<<endl<<endl;
			break;
		case 4:
			if(allocatore.dimensione == 0){
				cerr<<"Allocatore vuoto."<<endl<<endl;
				break;
			}
			if(!salva(allocatore))
				cerr<<"Errore."<<endl<<endl;
			else
				cout<<"Salvato ben."<<endl<<endl;
			break;
		case 5:
			if(!carica(allocatore))
				cerr<<"Errore."<<endl<<endl;
			else
				cout<<"Caricato ben."<<endl<<endl;
			break;
		case 6:
			cout<<"Inserisci posizione: ";
			cin>>posizione;
			cout<<"Dimensione dell'oggetto: ";
			cin>>dimensione;
			if(!allocaOggetto2(allocatore,posizione,dimensione))
				cerr<<"Errore."<<endl<<endl;
			else
				cout<<"Allocato ben."<<endl<<endl;
			break;
		case 7:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}