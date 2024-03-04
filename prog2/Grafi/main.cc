#include <iostream>
#include <fstream>
#include "grafo.h"
#include "bfs.h"
using namespace std;

graph gBuild(ifstream &f,bool o,bool w){
    graph g;
    int n = 0;
    int d,s;
    double we;
    f>>n;
    g = newGraph(n);
    if(o)
        if(w)
            while(f>>s>>d>>we)
                addArc(g,s,d,we);
        else
            while(f>>s>>d)
                addArc(g,s,d,1.0);
    else
        if(w)
            while(f>>s>>d>>we)
                addEdge(g,s,d,we);
        else
            while(f>>s>>d)
                addEdge(g,s,d,1.0);
    return g;
}

bool* connected(graph g,int v){
    bool* raggiunto = new bool[getDim(g)];
    for(int i=0;i<getDim(g);i++)
        raggiunto[i] = false;
    
    listaBFS coda = newQueue();
    raggiunto[v-1] = true;
    coda = enqueue(coda,v);
    while(!isEmpty(coda)){
        int u = dequeue(coda);
        for(listaAd n = getListaAd(g,u);n != NULL;n = getNext(n)){
            int i = getNode(n);
            if(!raggiunto[i-1]){
                raggiunto[i-1] = true;
                coda = enqueue(coda,v);
            }
        }
    }
    
    /*for(int i=0;i<getDim(g);i++)
        if(!raggiunto[i])
            return false;
    return true;*/
    return raggiunto;
}

int main(int argc,char* argv[]){
    if(argc != 4){
        cout<<"Inserisci numero di argomenti corretto."<<endl;
        return 0;
    }

    ifstream file(argv[1]);

    int oriented = atoi(argv[2]);
    int weighted = atoi(argv[3]);

    graph mainGraph = gBuild(file,oriented,weighted);

    listaAd liste = NULL;
    cout<<"Id      Ad List"<<endl<<endl;
    for(int i=0;i<getDim(mainGraph);i++){
        liste = getListaAd(mainGraph,i);
        cout<<i+1<<"\t";
        while(liste != NULL){
            cout<<getNode(liste)<<" ";
            liste = getNext(liste);
        }
        cout<<endl;
    }
    cout<<endl;

    /*if(connected(mainGraph,1))
        cout<<"Grafo connesso."<<endl;
    else
        cout<<"Grafo non connesso."<<endl;*/
    int n;
    cout<<"Nodo dal quale partire: ";
    cin>>n;

    bool* raggiungibili = connected(mainGraph,n);
    
    cout<<"Nodi raggiungibili a partire dal nodo 1:"<<endl;
    for(int i=1;i<=getDim(mainGraph);i++){
        //if(raggiungibili[i])
            cout<<raggiungibili[i]<<" ";
    }
    cout<<endl;
    
}