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

int max(int a, int b) {
  return a>b ? a : b;
}

int min(int a, int b) {
  return a<b ? a : b;
}


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
    q->largo = 1;
    return q;
}


void arbol_insertar(arbol** q, int num){
    nodo *n = nodo_crear(num);
    if ((*q)->c == NULL) {
      (*q)->c = n;
    } else {
      nodo *raiz = (*q)->c;
      nodo_insertar(raiz, n);
    }
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

void arbol_eliminar(arbol** q, int num) {

  if ((*q)->c != NULL) {
    //Algoritmo en preorden
    if ((*q)->c->num == num) {
      (*q)->c = NULL;
      (*q)->largo--;
    } else {
      pila *pil = pila_crear();
      // if ((*q)->c != NULL) {
        nodo *p = (*q)->c;

        insertar_pila(&pil, p);
        while (!pila_vacia(&pil)) {
          p = eliminar_pila(&pil);


          if (p->right != NULL) {
            if (p->right->num == num) {
              free(p->right);
              (*q)->largo--;
              p->right = NULL;
            } else {
              insertar_pila(&pil, p->right);
            }
          }
          if (p->left != NULL) {
            if (p->left->num == num) {
              free(p->left);
              (*q)->largo--;
              p->left = NULL;
            } else {
              insertar_pila(&pil, p->left);
            }
          }
        }
      // }

    }
  }

}


void imprimir_arbol_preorden(arbol** q) {

  //Algoritmo en preorden
  if ((*q)->c == NULL) {
    cout << "\nArbol Vacío";
  } else {
    pila *pil = pila_crear();

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
  }

  cout <<"\n";

}


void altura(arbol** q) {

  //Algoritmo en preorden
  if ((*q)->c == NULL) {
    cout << "\nArbol Vacío, no tiene altura";
  } else {
    int mayor = 0, contador = 0;
    pila *pil = pila_crear();

    nodo *p = (*q)->c;
    insertar_pila(&pil, p);
    while (!pila_vacia(&pil)) {
      p = eliminar_pila(&pil);
      //Visitar(p) start
      if (p != (*q)->c) {
        contador++;
      }
      if (p->right == NULL && p->left == NULL) {
        if ((contador) > mayor) {
          mayor = contador;
        }
        contador = 0;
      }
      //Visitar(p) end
      if (p->right != NULL) {
        insertar_pila(&pil, p->right);
      }
      if (p->left != NULL) {
        insertar_pila(&pil, p->left);
      }
    }


  cout << "\nLa altura del arbol es: " << mayor <<"\n";
  }

}

int alturaIzquierda(arbol** q) {

  //Algoritmo en preorden
  try {
    if ((*q)->c == NULL) {
      return 0;
    } else {
      int mayor = 0, contador = 0;
      pila *pil = pila_crear();

      nodo *p = (*q)->c->left;
      insertar_pila(&pil, p);
      while (!pila_vacia(&pil)) {
        p = eliminar_pila(&pil);
        //Visitar(p) start
        if (p != (*q)->c->left) {
          contador++;
        }
        if (p->right == NULL && p->left == NULL) {
          if ((contador) > mayor) {
            mayor = contador;
          }
          contador = 0;
        }
        //Visitar(p) end
        if (p->right != NULL) {
          insertar_pila(&pil, p->right);
        }
        if (p->left != NULL) {
          insertar_pila(&pil, p->left);
        }
      }


      return mayor;
    }
  } catch (int e) {
    return 0;
  }


}

int alturaDerecha(arbol** q) {


  try {
    //Algoritmo en preorden
    if ((*q)->c == NULL) {
      return 0;
    } else {
      int mayor = 0, contador = 0;
      pila *pil = pila_crear();

      nodo *p = (*q)->c->right;
      insertar_pila(&pil, p);
      while (!pila_vacia(&pil)) {
        p = eliminar_pila(&pil);
        //Visitar(p) start
        if (p != (*q)->c->right) {
          contador++;
        }
        if (p->right == NULL && p->left == NULL) {
          if ((contador) > mayor) {
            mayor = contador;
          }
          contador = 0;
        }
        //Visitar(p) end
        if (p->right != NULL) {
          insertar_pila(&pil, p->right);
        }
        if (p->left != NULL) {
          insertar_pila(&pil, p->left);
        }
      }

    return mayor;
    }
  } catch (int e) {
    return 0;
  }

}

int bfactor(arbol** q) {
  int izq = alturaIzquierda(q), der = alturaDerecha(q);

  return (max(izq, der)-min(izq, der));
}

bool arbol_balanceado(arbol** q) {
  return (bfactor(q) <= 1 ) ? true : false;
}

// int altura(nodo *r){
//     return 0;
//
// }

#endif
