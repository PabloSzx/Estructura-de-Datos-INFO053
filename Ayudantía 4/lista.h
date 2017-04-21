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

void eliminar(lista **lista, int indice) {

  int i = 0;
  nodo *ptr = (*lista)->inicio;

  while (ptr != NULL) {
    if (indice == 0) {
      nodo *sig = (nodo *)malloc(sizeof(nodo));
      // sig = ptr->siguiente;
      // cout << sig->nombre;
      (*lista)->inicio = ptr->siguiente;


      // sig = ((*lista)->inicio)->siguiente;
      // cout << sig->nombre;
      // (*lista)->inicio = sig;
      // (*lista)->largo--;
      // ptr = sig;
    } else if ((i + 1) == indice) {
      ptr->siguiente = (ptr->siguiente)->siguiente;
      (*lista)->largo--;
    } else {
      ptr = ptr->siguiente;
    }
    i++;
  }
}

#endif
