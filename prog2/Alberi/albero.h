struct nodo {
    tipoInf info;
    nodo* padre;
    nodo* figlio;
    nodo* fratm;
};

typedef nodo* albero;

nodo* newNode(tipoInf);
void insertChild(albero,albero);
void insertSibling(nodo*,albero);

tipoInf getInfo(albero);
nodo* getPadre(albero);
nodo* getFiglio(albero);
nodo* getFratm(albero);

void serializza(albero);
int altezza(albero);
bool path(nodo*,tipoInf);