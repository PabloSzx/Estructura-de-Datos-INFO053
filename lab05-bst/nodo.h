#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <limits>

int maximo(int a, int b){
    return a > b ? a : b;
}

int minimo(int a, int b){
    return a < b? a : b;
}

int absoluto(int a) {
  return a < 0 ? -a : a;
}

typedef struct nodo{
    int val;
    struct nodo *izq;
    struct nodo *der;
}nodo;

int bfactor(nodo*  a);
// int preorden(nodo *a, int factorAnterior);

using namespace std;

nodo* crear_nodo(int val){
    nodo *n = (nodo*)malloc(sizeof(nodo));
    n->val = val;
    n->izq = NULL;
    n->der = NULL;
    return n;
}

int eshoja(nodo *r){
    if(r->izq == NULL && r->der == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void imprimir(nodo *r, int depth, int *padres){
    if(r != NULL){
        printf("(%i)", r->val);
        char buf[512] = "  ";
        for(int i=0; i<depth; ++i){
            if(padres[i] == 1){
                strcat(buf, " \t");
            }
            else{
                strcat(buf, "|\t");
            }
        }
        if(eshoja(r)){
            return;
        }
        //printf("\n%s|----", buf);
        printf("--", buf);
        padres[depth] = 0;
        imprimir(r->izq, depth+1, padres);

        printf("\n%s|-----", buf);
        padres[depth] = 1;
        imprimir(r->der, depth+1, padres);
    }
}

// (1)
void bst_insertar(nodo **r, int val){

  if ((*r) == NULL) {
    nodo* n = crear_nodo(val);
    (*r) = n;
  } else if (val > (*r)->val) {
      bst_insertar(&(*r)->der, val);
  } else if (val < (*r)->val) {
      bst_insertar(&(*r)->izq, val);
    }

}

// (2)
nodo* bst_buscar(nodo **r, int val){
  if ((*r) == NULL) {
    cout << "\nNodo no encontrado";
    return NULL;
  } else if ((*r)->val < val) {
    return bst_buscar(&(*r)->der, val);
  } else if ((*r)->val > val) {
    return bst_buscar(&(*r)->izq, val);
  } else {
    return (*r);
  }
}

// (2) adaptado para retornar el puntero exacto del nodo, no un nodo temporal con el valor
nodo** bst_buscar_puntero(nodo **r, int val){
  if ((*r) == NULL) {
    return r;
  } else if ((*r)->val < val) {
    nodo** p = bst_buscar_puntero(&(*r)->der, val);
    return p;
  } else if ((*r)->val > val) {
    nodo** p = bst_buscar_puntero(&(*r)->izq, val);
    return p;
  }
  else {
    return (r);
  }
}

// (3)  elimina el puntero r donde esté el arbol, puede ser la raiz del arbol o un resultado de bst_buscar_puntero a partir del arbol
void bst_eliminar(nodo **r){
  if (eshoja(*r)) {
    (*r) = NULL;
  } else {
    if ((*r)->der != NULL) {
      nodo **menor = &(*r)->der->izq;
      while ((*menor) != NULL) {
        menor = &(*menor)->izq;
      }
      (*menor) = (*r)->izq;
      (*r) = (*r)->der;
    } else {
      (*r) = (*r)->izq;
    }
  }
}

// (4) recorrido en preorden para verificar balanceo

void balanceo(nodo **p, bool *siga) {

  if (*siga) {
    int factor = bfactor(*p);
    if (absoluto(factor) <= 1) {
      if ((*p)->izq != NULL) {
        balanceo(&(*p)->izq, siga);
      }
      if ((*p)->der != NULL) {
        balanceo(&(*p)->der, siga);
      }
    } else {
      *siga = false;
    }
  }

}

// (5)
int altura(nodo *r){
  if (r == NULL) {
    return 0;
  } else {
    return (1 + max(altura(r->izq), altura(r->der)));
  }
}

// (6)
int bfactor(nodo *r){
  int izq = altura(r->izq);
  int der = altura(r->der);
  return (der - izq);
}

// (7)

bool arbol_balanceado(nodo **p) {
  bool siga = true;

  balanceo(p, &siga);

  return siga;
}

// (8)
int rot_der(nodo **r){
  return 1;
}

// (8)
int rot_izq(nodo **r){
    return 1;
}
#endif
