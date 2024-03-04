#include <iostream>
#include <fstream>
using namespace std;

const char file[] = "pratica.bin";

struct codice_t{
    char *code;
    int nCaratteri = 0;
    int nRighe = 0;
};

bool inizializzaCodice(codice_t &c,int righe,int caratteri,istream &in){
	bool ins = false;
	if(righe < 0 || caratteri < 0)
		return false;
	if(righe != c.nRighe || caratteri != c.nCaratteri && righe > 0 || caratteri > 0){
		delete[] c.code;
		c.nCaratteri = c.nRighe = 0;
	}
	c.nCaratteri = caratteri;
	c.nRighe = righe;
    c.code = new char[c.nCaratteri * c.nRighe];
    for(int i=0;i<c.nRighe*c.nCaratteri;i++){
		in>>c.code[i];
		do{
			ins = false;
			if(c.code[i] < 'A' || c.code[i] > 'Z'){
				cout<<"Ho detto MAIUSCOLI, rimettilo: ";
				i--;
			}
			else
				ins = true;
		}while(!ins);
    }
    return true;
}

void stampaCodice(codice_t c){
	for(int i=0;i<c.nRighe*c.nCaratteri;i++){
		if(i%c.nCaratteri == 0 && i != 0)
			cout<<"|";
		cout<<" "<<c.code[i]<<" ";	
    }
}

bool salvaCodice(codice_t c){
	ofstream outFile(file);
	if(!outFile)
		return false;

	outFile.write(reinterpret_cast<char*>(&c.nRighe),sizeof(c.nRighe));
	outFile.write(reinterpret_cast<char*>(&c.nCaratteri),sizeof(c.nCaratteri));

	outFile.write(c.code,c.nRighe*c.nCaratteri);
	return true;
}

bool caricaCodice(codice_t &c){
	int r,car;
	ifstream inFile(file);
	if(!inFile)
		return false;

	inFile.read(reinterpret_cast<char*>(&r),sizeof(r));
	inFile.read(reinterpret_cast<char*>(&car),sizeof(car));

	return inizializzaCodice(c,r,car,inFile);
}

char ritornaCarattere(codice_t c,int pos,int riga){
	short i = riga*c.nCaratteri;
	int cont = 0;
	for(;i<c.nCaratteri*c.nRighe;i++){
		if(cont == pos)
			return c.code[i];
		cont++;
	}
	return 'x';
}


int main()
{
    codice_t codici;
	const char menu[] =
		"1. Inizializza codice\n"
		"2. Stampa codice\n"
		"3. Salva codice\n"
		"4. Carica codice\n"
		"5. Stampa carattere\n"
		"6. Ruota codice\n"
		"7. Esci\n";

	while (true) {
		cout<<menu<<endl;
		int scelta,righe,caratteri;
		cin>>scelta;

		cout<<endl; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1:
			cout<<"Inserisci numero di caratteri: ";
			cin>>caratteri;
			cout<<"Inserisci numero di righe consecutive: ";
			cin>>righe;
			cout<<"Inserisci i caratteri MAIUSCOLI: ";
			inizializzaCodice(codici,righe,caratteri,cin);
			break;
		case 2:
			stampaCodice(codici);
			cout<<endl;
			break;
		case 3:
			salvaCodice(codici);
			break;
		case 4:
			caricaCodice(codici);
			break;
		case 5:
			{
				bool ins = false;
				int i,j;
				cout<<"Inserisci riga: ";
				do{
					cin>>j;
					if(j >= codici.nRighe)
						cout<<"Reinserisci bene: ";
					else
						ins = true;
				}while(!ins);
				ins = false;
				cout<<"Inserisci colonna: ";
				do{
					cin>>i;
					if(i >= codici.nCaratteri)
						cout<<"Reinserisci bene: ";
					else
						ins = true;
				}while(!ins);
				cout<<"Ecco il carattere: "<<ritornaCarattere(codici,i,j)<<endl<<endl;
				break;
			}
		case 6:
			break;
		case 7:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}