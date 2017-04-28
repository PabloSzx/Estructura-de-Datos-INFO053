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
  struct nodo *anterior;
}nodo;

typedef struct lista {
  nodo *inicio;
  int largo;
} lista;

void insertar(lista **lista, int edad, char *nombre) {
  nodo *n = (nodo *)malloc(sizeof(nodo));
  nodo *pre = (nodo *)malloc(sizeof(nodo));
  nodo *previous = (nodo *)malloc(sizeof(nodo));

  n->edad = edad;
  strcpy(n->nombre, nombre);
  int cont = 0;

  nodo *ptr = (*lista)->inicio;

  if ((*lista)->inicio == NULL) {
    n->siguiente = n;
    n->anterior = n;
    (*lista)->inicio = n;
    (*lista)->largo++;
  } else {
    while (cont < ((*lista)->largo)) {
      pre = ptr;
      previous = ptr->anterior;
      ptr = ptr->siguiente;
      cont++;
    }
    (*lista)->inicio->anterior = n;
    n->anterior = pre;
    n->siguiente = (*lista)->inicio;
    pre->siguiente = n;
    (*lista)->largo++;
  }
}

void imprimir(lista **lista) {
  system("clear");

  cout << "\n El largo de la lista es: " << (*lista)->largo;

  nodo *ptr = (*lista)->inicio;
  cout << "\n [\n";

  int cont = 0;


  while (cont < ((*lista)->largo)) {
    cout << "\n" << ptr->edad << " " << ptr->nombre;

    cout << "\n\nel anterior a " << ptr->nombre << " es " << ptr->anterior->nombre;
    cout << "\ny el siguiente a " << ptr->nombre << " es " << ptr->siguiente->nombre << "\n";

    ptr = ptr->siguiente;


    cont++;
  }

  cout << "\n] \n";

}

// void eliminar(lista **lista) {
//   nodo *ptr = (*lista)->inicio;
//   nodo *sig = ptr->siguiente;
//
//   if (ptr->siguiente == ptr) {
//     free(ptr);
//     (*lista)->inicio = NULL;
//   } else {
//     free(ptr);
//     (((*lista)->inicio)->anterior)->siguiente = (sig);
//     (*lista)->inicio = (sig);
//   }
//   (*lista)->largo--;
//
// }

void eliminar(lista **lista, char *nom){

  nodo *j=(*lista)->inicio;
  if(strcmp(j->nombre,nom)==0){
    (*lista)->inicio=j->siguiente;
    (*lista)->inicio->anterior=NULL;
    free(j);
  }
  else{
    while (strcmp(j->nombre,nom)!=0){
        printf("%i\n",strcmp(j->nombre,nom) );
        j=j->siguiente;

      }
      nodo *r=j->siguiente;
      nodo *a=j->anterior;
      free(j);
      a->siguiente=r;
      r->anterior=a;


    }
  }

#endif
