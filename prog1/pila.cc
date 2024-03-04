#include <iostream>
#include <fstream>
using namespace std;

const int DIM = 20;
struct pila_t{
    int pila[DIM];
    int nElementi = 0;
};

bool push(pila_t &p,int num){
    if(p.nElementi == 0){
        p.pila[0] = num;
        p.nElementi++;
        return true;
    }
    else{
        for(short i=p.nElementi;i>0;i--){
            if(i > DIM)
                return false;
            p.pila[i] = p.pila[i-1];
        }
        p.pila[0] = num;
        p.nElementi++;
        return true;
    }
    return false;
}

int pop(pila_t &p){
    int num;
    if(p.nElementi == 0)
        return -1;
    if(p.nElementi == 1){
        num = p.pila[0];
        p.nElementi--;
        return num;
    }
    else{
        num = p.pila[0];
        for(short i=0;i<p.nElementi-1;i++)
            p.pila[i] = p.pila[i+1];
        p.nElementi--;    
        return num;
    }
    return -1;
}

int main(){
    int estrai;
    pila_t pilaGenerale;
    char nomeFile[100];
    
    while(true){
        int scelta;
        cout<<"\tPila:"<<endl
            <<"1. Push da stdin."<<endl
            <<"2. Pop su stdout."<<endl
            <<"3. Push da file."<<endl
            <<"4. Pop su file."<<endl
            <<"5. Stampa pila."<<endl
            <<"6. Termina."<<endl;
        cin>>scelta;
        switch(scelta){
            case 1:
                int numero;
                cout<<endl<<"Inserisci i numeri (scrivere una lettera per terminare):"<<endl;
                while(cin>>numero)
                    if(!push(pilaGenerale,numero)){
                        cout<<"Pila piena o errore nel push!"<<endl;
                        break;
                    }
                cin.clear();
                cin.ignore();
                break;
            case 2:
                if(pilaGenerale.nElementi == 0){
                    cout<<endl<<"Pila vuota."<<endl<<endl;
                    break;
                }
                cout<<endl<<"Quanti elementi estraggo e stampo? ";
                cin>>estrai;
                cout<<"Numeri estratti:"<<endl;
                for(short i=0;i<estrai;i++){
                    cout<<pop(pilaGenerale)<<" ";
                }
                cout<<endl<<endl;
                break;
            case 3:
                cout<<endl<<"Inserire nome del file con estensione: ";
                cin>>nomeFile;
                {
                    ifstream inFile(nomeFile);
                    if(!inFile){
                        cout<<"Errore nella lettura del file."<<endl;
                        break;
                    }
                    int n;
                    cout<<"Valori trovati:"<<endl;
                    while(inFile>>n){
                        cout<<n<<" ";
                        push(pilaGenerale,n);
                    }
                    inFile.close();
                    cout<<endl<<endl;
                }
                break;
            case 4:
                if(pilaGenerale.nElementi == 0){
                    cout<<endl<<"Pila vuota."<<endl<<endl;
                    break;
                }
                cout<<endl<<"Inserire nome del file con estensione: ";
                cin>>nomeFile;
                cout<<"Quanti elementi estraggo? ";
                cin>>estrai;
                {
                    ofstream outFile(nomeFile);
                    if(!outFile){
                        cout<<"Errore nella lettura del file."<<endl;
                        break;
                    }
                    for(short i=0;i<estrai;i++)
                        outFile<<pop(pilaGenerale)<<" ";
                    outFile.close();
                    cout<<"Fatto."<<endl<<endl;
                }
                break;
            case 5:
                if(pilaGenerale.nElementi == 0){
                    cout<<endl<<"Pila vuota."<<endl<<endl;
                    break;
                }
                cout<<endl<<"Pila attuale:"<<endl;
                for(short i=0;i<pilaGenerale.nElementi;i++)
                    cout<<pilaGenerale.pila[i]<<" ";
                cout<<endl<<endl;
                break;
            case 6:
                return 0;
            default:
                cout<<"Inserisci Amodo."<<endl<<endl;
        }//switch
    }
}