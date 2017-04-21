#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct nodo {
  int edad;
  char nombre[100];
  struct nodo *siguiente;
}nodo;

typedef struct lista {
  nodo *inicio;
  int largo;
} lista;

void insertar(lista **lista, int edad, char *nombre) {
  nodo *n = (nodo *)malloc(sizeof(nodo));
  n->edad = edad;
  strcpy(n->nombre, nombre);
  if ((*lista)->inicio == NULL) {
    n->siguiente = NULL;
    (*lista)->inicio = n;
    (*lista)->largo++;
  } else {
    n->siguiente = (*lista)->inicio;
    (*lista)->inicio = n;
    (*lista)->largo++;

  }
}

void imprimir(lista **lista) {
  system("clear");

  cout << "\n El largo de la lista es: " << (*lista)->largo;

  nodo *ptr = (*lista)->inicio;
  cout << "\n [\n";

  while (ptr != NULL) {
    cout << "\n" << ptr->edad << " " << ptr->nombre;
    ptr = ptr->siguiente;
  }

  cout << "\n] \n";
}

void eliminar(lista **lista) {
  nodo *ptr = (*lista)->inicio;
  nodo *sig = ptr->siguiente;

  if (ptr->siguiente == NULL) {
    (*lista)->inicio = NULL;
  } else {
    (*lista)->inicio = (sig);
  }
  (*lista)->largo--;

}

#endif
