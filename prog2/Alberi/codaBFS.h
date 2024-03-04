struct elemBFS{
    nodo* elem;
    elemBFS* next;
};

typedef elemBFS* coda;

typedef struct{
    coda head;
    elemBFS* tail;
} listaBFS;

listaBFS newQueue();
static elemBFS* newElem(nodo*);
listaBFS enqueue(listaBFS,nodo*);
nodo* dequeue(listaBFS&);
nodo* first(listaBFS);
bool isEmpty(listaBFS);
