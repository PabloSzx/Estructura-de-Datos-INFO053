#ifndef NODE_H
#define NODE_H

typedef struct nodo{
  int val;
  // char text[128];
  struct nodo* next;
} nodo;

nodo* crear_nodo(int x){
  printf("x = %i asasa1\n", x); fflush(stdout);
  nodo *aux = (nodo*)malloc(sizeof(nodo));
  printf("x = %i asasa2\n", x); fflush(stdout);
  aux->val = x;
  aux->next = NULL;
  return aux;
}

#endif
