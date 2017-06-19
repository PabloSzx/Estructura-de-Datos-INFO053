#ifndef NODE_H
#define NODE_H

typedef struct nodo{
    char text[10];
    struct nodo* next;
} nodo;

nodo* crear_nodo(char* text){
    //printf("x = %i asasa1\n", x); fflush(stdout);
    nodo *aux = (nodo*)malloc(sizeof(nodo));
    //printf("x = %i asasa2\n", x); fflush(stdout);
    // aux->val = x;
    strcpy(aux->text, text);
    aux->next = NULL;
    return aux;
}

#endif
