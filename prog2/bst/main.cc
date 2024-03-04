#include <iostream>
#include "tipo.h"
#include "bst.h"
using namespace std;

int main(){
    btree t = NULL;
	int risp;
	int k;
	int i;

	do{
		cout << "Inserisci valore di chiave (intero): " << endl;
		cin>>k;
		cout << "Inserisci valore informativo (intero): " << endl;
		cin>>i;
		bnode* b = newNode(k,i);
		cout<<"Nodo creato:"<<b<<getKey(b)<<getInf(b)<<endl;
		bstInsert(t,b);
		cout<<"Per terminare digitare 0 altrimenti altro valore: ";
		cin>>risp;
	}while(risp != 0);

	printBST(t);
}