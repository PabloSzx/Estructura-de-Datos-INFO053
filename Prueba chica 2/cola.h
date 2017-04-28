#ifndef COLA_H
#define COLA_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>


// -----------------------------------
// definiciones de estructuras
// -----------------------------------
using namespace std;
// estructura de nodo
typedef struct nodo{
   int      num;
   char     text[100];
   struct   nodo *next;
} nodo;


// estructura de cola
typedef struct cola{
    nodo *c;
    nodo *f;
    int largo;
}cola;

// -----------------------------------
// declaraciones de funciones
// -----------------------------------

// funciones nodo
nodo*   nodo_crear(int num, const char *text);

// funciones cola
cola*   cola_crear();
void    cola_imprimir(cola *q);
void    cola_insertar(cola** q, int num, const char *text);
nodo*   cola_eliminar(cola **q);

// -----------------------------------
// definiciones de funciones
// -----------------------------------
nodo* nodo_crear(int num, const char *text){
    nodo *a = (nodo*)malloc(sizeof(nodo));
    a->num = num;
    strcpy(a->text, text);
    a->next = NULL;
    return a;
}

// crear cola, la retorna como puntero
cola* cola_crear(){
    cola* q = (cola*)malloc(sizeof(cola));
    q->c = NULL;
    q->f = NULL;
    q->largo = 0;
    return q;
}

// insertar elemento en la cola (FIFO)
void cola_insertar(cola** q, int num, const char *text){
    nodo *n = nodo_crear(num, text);
    if((*q)->c == NULL && (*q)->f == NULL){
        (*q)->c = (*q)->f = n;
        (*q)->largo++;
        return;
    }
    else{
        (*q)->f->next = n;
        (*q)->f = n;
        (*q)->largo++;
        return;
    }
}

// eliminar elemento de la cola (FIFO)
nodo* cola_eliminar(cola** q){
    if((*q)->c == NULL && (*q)->f == NULL){
        return NULL;
    }
    else if((*q)->c == (*q)->f){
        nodo *ret = (*q)->c;
        (*q)->c = NULL;
        (*q)->f = NULL;
        (*q)->largo--;
        return ret;
    }
    else{
        nodo *ret = (*q)->c;
        (*q)->c = (*q)->c->next;
        (*q)->largo--;
        return ret;
    }
}

// imprimir cola (FIFO)
void cola_imprimir(cola *q){
    nodo *aux = q->c;
    // cout << "\nLargo de la cola es: " << (*q)->largo;
    // printf("\nLargo de la cola es: %i \n", (º);
    while(aux != NULL){
        printf("(%i, %s) ", aux->num, aux->text);
        aux = aux->next;
    }
    printf("\n");
}
#endif
