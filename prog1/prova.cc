#include <iostream>
using namespace std;

void Inizializza(int v[],int num){
    for(short i=0;i<26;i++){
        v[i] = 0;
    }
    num = 0;
}

void Inserisci(char p,int v[],int c,int num){
    if(num >= c)
        cout<<"Capienza massima raggiunta."<<endl;
    else{
        if(p < 'a' || p > 'z')
            cout<<"Elemento non valido."<<endl;
        v[p - 'a']++;
        num++;
    }
}

void Estrai(char p,int v[],int num){
    if(p < 'a' || p > 'z')
        cout<<"Elemento non valido."<<endl;
    num -= v[p - 'a'];
    v[p - 'a'] = 0;
}

int Modifica(int c,int newc){
    if(c > newc){
        cout<<"Capienza errata."<<endl;
        return -1;
    }
    else
    return newc;
}

void stampa(int v[]){
    cout<<"<";
    for(short i=0;i<26;i++){
        if(v[i] != 0)
            cout<<char('a'+i)<<":"<<v[i]<<", ";
    }
    cout<<">";
}

int main(){
    struct alfabeto{
        int vettore[26];
        int numElem = 0;
        int capienza;
    } contenitore;
    const char Menu[] = 
	    "\nComandi disponibili:\n"
	    "\ti - per inserire un elemento nel contenitore\n"
	    "\te - per estrarre elementi dal contenitore\n"
	    "\tc - per modificare la capienza del contenitore\n"
	    "\tf - per informazioni sul contenitore\n"
	    "\tt - per terminare\n" ;
	
	cout<< "Inizializzazione contenitore.\n" ;
	cout<< "Immetterne la capienza (e premere Invio): " ;
	cin>>contenitore.capienza;

	Inizializza(contenitore.vettore,contenitore.numElem);
	cout<<endl ;

	while(true) {
	    char comando,carattere;

	    stampa(contenitore.vettore);
	    cout<<Menu<<"\n\nImmettere comando e premere Invio: " ;
	    cin>>comando ; // 'consumiamo' il precedente newline
	    switch (comando) {
            case 'i':
                cout<<"Inserisci nome elemento " ;
                cin>>carattere ;
                Inserisci(carattere,contenitore.vettore,contenitore.capienza,contenitore.numElem);
                break;
            case 'e':
                cout<<"Inserisci nome elemento " ;
                cin>>carattere ;
                Estrai(carattere,contenitore.vettore,contenitore.numElem);
                break;
            case 'c':
                int nuovaCapienza;
                cout<<"Inserisci nuova capienza (e premi Invio): " ;
                cin>>nuovaCapienza;
                contenitore.capienza = Modifica(contenitore.capienza,nuovaCapienza);
                break;
            case 'f': 
                cout<<"Capienza: "<<contenitore.capienza<<"\tElementi: "
                    <<contenitore.numElem<<endl ;
            break;
            case 't': 
                return 0 ;
            default: 
                cout<< "Comando non valido\n" ;
            }
	    }
	return 0 ;
}