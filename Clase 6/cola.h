#ifndef arbol_H
#define arbol_H

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
   struct   nodo *right;
   struct   nodo *left;
} nodo;


// estructura de arbol
typedef struct arbol{
    nodo *c;
    int largo;
}arbol;

// -----------------------------------
// declaraciones de funciones
// -----------------------------------

// funciones nodo
nodo*   nodo_crear(int num);

// funciones arbol
arbol*   arbol_crear();
void    arbol_imprimir(arbol *q);
void    arbol_insertar(arbol** q, int num);
void    nodo_insertar(nodo* q, nodo* n);
nodo*   arbol_eliminar(arbol **q);

// -----------------------------------
// definiciones de funciones
// -----------------------------------
nodo* nodo_crear(int num){
    nodo *a = (nodo*)malloc(sizeof(nodo));
    a->num = num;
    a->right = NULL;
    a->left = NULL;
    return a;
}

// crear arbol, la retorna como puntero
arbol* arbol_crear(int n){
    arbol* q = (arbol*)malloc(sizeof(arbol));
    nodo* nd = nodo_crear(n);
    q->c = nd;
    q->largo = 0;
    return q;
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

// insertar elemento en la arbol (FIFO)
void arbol_insertar(arbol** q, int num){
    nodo *n = nodo_crear(num);

    nodo *raiz = (*q)->c;

    cout << raiz->num;
    nodo_insertar(raiz, n);


}

nodo* buscar_nodo(arbol** q, int num) {

}

// eliminar elemento de la arbol (FIFO)
// nodo* arbol_eliminar(arbol** q){
//     if((*q)->c == NULL && (*q)->f == NULL){
//         return NULL;
//     }
//     else if((*q)->c == (*q)->f){
//         nodo *ret = (*q)->c;
//         (*q)->c = NULL;
//         (*q)->f = NULL;
//         (*q)->largo--;
//         return ret;
//     }
//     else{
//         nodo *ret = (*q)->c;
//         (*q)->c = (*q)->c->next;
//         (*q)->largo--;
//         return ret;
//     }
// }

// imprimir arbol (FIFO)
void arbol_imprimir(arbol *q){
    nodo *aux = q->c;
    while(aux != NULL){
        printf("(%i) ", aux->num);
        aux = aux->right;
    }

    aux = q->c;
    printf("\n\nCambio de lado\n\n");
    while(aux != NULL){
        printf("(%i) ", aux->num);
        aux = aux->left;
    }
    printf("\n");
}
#endif
