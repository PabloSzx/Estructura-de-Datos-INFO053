#ifndef arbol_H
#define arbol_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

using namespace std;

typedef struct arbol{
  nodo *c;
  int largo;
}arbol;

nodo* nodo_crear(int num){
  nodo *a = (nodo*)malloc(sizeof(nodo));
  a->num = num;
  a->right = NULL;
  a->left = NULL;
  return a;
}

void nodo_insertar(nodo* q, nodo* n) {
  if (n->num > (q->num)) {
    if (q->right != NULL) {
      nodo_insertar(q->right, n);
    } else {
      q->right = n;
    }
  } else if (n->num < (q->num)) {
    if (q->left != NULL) {
      nodo_insertar(q->left, n);
    } else {
      q->left = n;
    }
  }
}

arbol* arbol_crear(int n){
  arbol* q = (arbol*)malloc(sizeof(arbol));
  nodo* nd = nodo_crear(n);
  q->c = nd;
  q->largo = 0;
  return q;
}


void arbol_insertar(arbol** q, int num){
  nodo *n = nodo_crear(num);
  nodo *raiz = (*q)->c;

  nodo_insertar(raiz, n);

  (*q)->largo++;
}

nodo* buscar_nodo(arbol** q, int num) {
  pila *pil = pila_crear();

  //Algoritmo en preorden
  nodo *p = (*q)->c;
  insertar_pila(&pil, p);
  while (!pila_vacia(&pil)) {
    p = eliminar_pila(&pil);
    //Visitar(p) start
    if (p->num == num) {
      return p;
    }
    //Visitar(p) end
    if (p->right != NULL) {
      insertar_pila(&pil, p->right);
    }
    if (p->left != NULL) {
      insertar_pila(&pil, p->left);
    }
  }

  cout << "\nNodo no encontrado!!";
  return NULL;
}

void imprimir_arbol_preorden(arbol** q) {
  pila *pil = pila_crear();

  //Algoritmo en preorden
  nodo *p = (*q)->c;
  insertar_pila(&pil, p);
  while (!pila_vacia(&pil)) {
    p = eliminar_pila(&pil);
    //Visitar(p) start
    cout << "(" << p->num << ")";
    //Visitar(p) end
    if (p->right != NULL) {
      insertar_pila(&pil, p->right);
    }
    if (p->left != NULL) {
      insertar_pila(&pil, p->left);
    }

    if (!pila_vacia(&pil)) {
      cout << " - ";
    }
  }

  cout <<"\n";

}

#endif
