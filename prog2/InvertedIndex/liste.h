struct elem_t {
    tipoInf elemento;
    elem_t* next;
    elem_t* prev;
};

typedef elem_t* lista;

tipoInf head(lista);
lista nuovoElemento(tipoInf);
lista search(lista,tipoInf);

lista tail(lista);
lista prev(lista);
lista inserisci(lista,lista);
lista elimina(lista,lista);