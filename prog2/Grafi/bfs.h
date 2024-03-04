struct elemBFS{
    int elem;
    elemBFS* next;
};

typedef elemBFS* coda;

typedef struct{
    coda head;
    elemBFS* tail;
} listaBFS;

listaBFS newQueue();
static elemBFS* newElem(int);
listaBFS enqueue(listaBFS,int);
int dequeue(listaBFS&);
int first(listaBFS);
bool isEmpty(listaBFS);
