#ifndef PCOLAS_H
#define PCOLAS_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

using namespace std;

typedef struct nodocola {
  struct cola *cola;
  struct nodocola *siguiente;
  struct nodocola *anterior;
}nodocola;

typedef struct pila {
  nodocola *inicio;
  int largo;
} pila;

pila* pcolas_crear(){
    pila* q = (pila*)malloc(sizeof(pila));
    q->inicio = NULL;
    q->largo = 0;
    return q;
}


void pcolas_insertar(pila **pila, cola* cola) {
  nodocola* nc = (nodocola*)malloc(sizeof(nodocola));
  nc->cola = cola;
  if ((*pila)->inicio == NULL) {
    nc->siguiente = NULL;
    nc->anterior = NULL;
    (*pila)->inicio = nc;
  } else {
    nc->siguiente = (*pila)->inicio;
    (*pila)->inicio = nc;
  }
  (*pila)->largo++;

}

void pcolas_imprimir(pila **pila) {
  cout << "\n El largo de la pila es: " << (*pila)->largo;

  nodocola *pi = (*pila)->inicio;
  cout << "\n [\n";

  //Recorremos la pila "pi"
  while (pi != NULL) {
    cout << "\n-------------------------------------------\n";

    nodo *co = (pi)->cola->c;
    //Recorremos la cola "co"
    while (co != NULL) {
      cout << "\n" << "Text: " << co->text << " || Num: " << co->num;
      co = co->next;
    }
    pi = pi->siguiente;
  }

  cout << "\n] \n";
}

void pcolas_eliminar(pila **pila) {

  nodocola* pi = (*pila)->inicio;
  nodocola* pisiguiente = (nodocola*)malloc(sizeof(nodocola));
  if (pi->siguiente == NULL) {
    (*pila)->inicio = NULL;
  } else {
    pisiguiente = ((*pila)->inicio)->siguiente;
    free(pi);
    (*pila)->inicio = pisiguiente;
  }

  (*pila)->largo--;


}

pila* pcolas_invertir(pila **pil) {

  pila *p = pcolas_crear();

  nodocola *pi = (*pil)->inicio;

  while (pi != NULL) {
    pcolas_insertar(&p, pi->cola);
    pi = pi->siguiente;
  }

  return(p);
}


#endif
