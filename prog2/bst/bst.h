typedef int tipoKey;
struct bnode {
    tipoKey key;
    tipoInf inf;
    bnode* left;
    bnode* right;
    bnode* parent;
};

typedef bnode* btree;

int compareKey(tipoKey,tipoKey);
void copyKey(tipoKey&,tipoKey);
void printKey(bnode*);

bnode* newNode(tipoKey,tipoInf);
bnode* search(btree,tipoKey);
void bstInsert(btree&,bnode*);
void printBST(btree);

tipoInf getInf(bnode*);
tipoKey getKey(bnode*);
bnode* getLeft(bnode*);
bnode* getRight(bnode*);
bnode* getParet(bnode*);

