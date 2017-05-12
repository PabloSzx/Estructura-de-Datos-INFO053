#ifndef pila_H
#define pila_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

using namespace std;

typedef struct nodo{
   int      num;
   int      vertical;
   int      horizontal;
   struct   nodo *right;
   struct   nodo *left;
} nodo;

typedef struct nodopila {
  struct nodo *nodo;
  struct nodopila *siguiente;
}nodocola;


typedef struct pila {
  nodopila *inicio;
  int largo;
} pila;


pila* pila_crear(){
    pila* q = (pila*)malloc(sizeof(pila));
    q->inicio = NULL;
    q->largo = 0;
    return q;
}

void insertar_pila(pila **pila, nodo *nodo) {
  nodopila *n = (nodopila *)malloc(sizeof(nodopila));
  n->nodo = nodo;
  if ((*pila)->inicio == NULL) {
    n->siguiente = NULL;
    (*pila)->inicio = n;
    (*pila)->largo++;
  } else {
    n->siguiente = (*pila)->inicio;
    (*pila)->inicio = n;
    (*pila)->largo++;
  }
}

bool pila_vacia(pila **pila) {

  if ((*pila)->inicio == NULL) {
    return true;
  }
  return false;
}

nodo* eliminar_pila(pila **pila) {
  nodopila *ptr = (*pila)->inicio;
  nodopila *sig = ptr->siguiente;

  if (ptr->siguiente == NULL) {
    (*pila)->inicio = NULL;
  } else {
    (*pila)->inicio = (sig);
  }

  (*pila)->largo--;
  return ptr->nodo;

}

#endif
