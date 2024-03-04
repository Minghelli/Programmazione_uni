struct nodo {
    int inf;
    double weight;
    nodo* next;
};

typedef nodo* listaAd;

typedef struct{
    listaAd* nodes;
    int dim;
} graph;

graph newGraph(int);
void addArc(graph&,int,int,double);
void addEdge(graph&,int,int,double);

int getDim(graph);
listaAd getListaAd(graph,int);
int getNode(nodo*);
listaAd getNext(listaAd);

