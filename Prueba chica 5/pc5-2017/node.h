#ifndef NODE_H
#define NODE_H

typedef struct nodo{
    int val;
    char* text;
    struct nodo* next;
} nodo;

nodo* crear_nodo(int x, char *text){
    //printf("x = %i asasa1\n", x); fflush(stdout);
    nodo *aux = (nodo*)malloc(sizeof(nodo));
    //printf("x = %i asasa2\n", x); fflush(stdout);
    // cout << "crear nodo" << endl;
    // cout << (text);
    aux->val = x;
    aux->text = text;
    // strcpy(aux->text, text);
    aux->next = NULL;
    return aux;
}

#endif
