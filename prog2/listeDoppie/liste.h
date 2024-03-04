struct elem_t {
    tipoInf elemento;
    elem_t* next;
    elem_t* prev;
};

typedef elem_t* lista;

elem_t* nuovoElemento(tipoInf);
elem_t* search(lista,tipoInf);
lista inserisci(lista,elem_t*);
lista elimina(lista,elem_t*);

tipoInf head(lista);
elem_t* tail(lista);
elem_t* prev(lista);
