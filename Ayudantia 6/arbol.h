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

int altura(nodo* ab) {
    if (ab == NULL)
        return -1;
    else
        return (1 + max(altura(ab->left), altura(ab->right)));

}
int alturaArbol(arbol** q) {
    return altura((*q)->c);
}

int getAltura(nodo* q) {
  return altura(q);
}

int alturaSubarbolIzquierdo(nodo* q) {
  return altura(q->left);
}

int alturaSubarbolDerecho(nodo* q) {
  return altura(q->right);
}

// int alturaIzquierda(arbol** q) {
//
//   //Algoritmo en preorden
//   try {
//     if ((*q)->c == NULL) {
//       return 0;
//     } else {
//       int mayor = 0, contador = 0;
//       pila *pil = pila_crear();
//
//       nodo *p = (*q)->c->left;
//       insertar_pila(&pil, p);
//       while (!pila_vacia(&pil)) {
//         p = eliminar_pila(&pil);
//         //Visitar(p) start
//         if (p != (*q)->c->left) {
//           contador++;
//         }
//         if (p->right == NULL && p->left == NULL) {
//           if ((contador) > mayor) {
//             mayor = contador;
//           }
//           contador = 0;
//         }
//         //Visitar(p) end
//         if (p->right != NULL) {
//           insertar_pila(&pil, p->right);
//         }
//         if (p->left != NULL) {
//           insertar_pila(&pil, p->left);
//         }
//       }
//
//
//       return mayor;
//     }
//   } catch (int e) {
//     return 0;
//   }
//
//
// }
//
// int alturaDerecha(arbol** q) {
//
//
//   try {
//     //Algoritmo en preorden
//     if ((*q)->c == NULL) {
//       return 0;
//     } else {
//       int mayor = 0, contador = 0;
//       pila *pil = pila_crear();
//
//       nodo *p = (*q)->c->right;
//       insertar_pila(&pil, p);
//       while (!pila_vacia(&pil)) {
//         p = eliminar_pila(&pil);
//         //Visitar(p) start
//         if (p != (*q)->c->right) {
//           contador++;
//         }
//         if (p->right == NULL && p->left == NULL) {
//           if ((contador) > mayor) {
//             mayor = contador;
//           }
//           contador = 0;
//         }
//         //Visitar(p) end
//         if (p->right != NULL) {
//           insertar_pila(&pil, p->right);
//         }
//         if (p->left != NULL) {
//           insertar_pila(&pil, p->left);
//         }
//       }
//
//     return mayor;
//     }
//   } catch (int e) {
//     return 0;
//   }
//
// }

// void designarHorizontal(arbol** q) {
//
//   //Algoritmo en preorden
//   if ((*q)->c == NULL) {
//     cout << "\nArbol Vacío, no tiene altura";
//   } else {
//     int mayor = 0, contador = 0;
//     pila *pil = pila_crear();
//
//     nodo *p = (*q)->c;
//     insertar_pila(&pil, p);
//     while (!pila_vacia(&pil)) {
//       p = eliminar_pila(&pil);
//       //Visitar(p) start
//       if (p != (*q)->c) {
//         contador++;
//       }
//       p->horizontal = contador;
//       if (p->right == NULL && p->left == NULL) {
//         if ((contador) > mayor) {
//           mayor = contador;
//         }
//         contador = 0;
//       }
//       //Visitar(p) end
//       if (p->right != NULL) {
//         insertar_pila(&pil, p->right);
//       }
//       if (p->left != NULL) {
//         insertar_pila(&pil, p->left);
//       }
//
//     }
//
//
//   cout << "\nLa altura del arbol es: " << mayor <<"\n";
//   }
//
// }

int bfactor(arbol** q) {
  int izq = alturaSubarbolIzquierdo((*q)->c);
  int der = alturaSubarbolDerecho((*q)->c);

  return (max(izq, der)-min(izq, der));
}

bool arbol_balanceado(arbol** q) {
  return (bfactor(q) <= 1 ) ? true : false;
}

// void arbol_invertir(arbol** q, int num) {
//   // p = nodo_crear(num);
//   nodo* p = buscar_nodo(q, num);
//   nodo* left = p->left; //si no tiene nada, es null
//   nodo* right = p->right; //si no tiene nada es null
//   // if (left != NULL && right != NULL) {
//   p->left = right;
//   p->right = left;
//   // }
//   cout << "\nArbol invertido en el nodo " << num << "\n";
//   // if (p->left != NULL) {
//   //
//   // }
//   // p = buscar_nodo(q, num);
// }


void findMinMax(nodo *nodo, int *min, int *max, int hd) {
    // Base case
    if (nodo == NULL) return;

    // Update min and max
    if (hd < *min)  *min = hd;
    else if (hd > *max) *max = hd;

    // Recur for left and right subtrees
    findMinMax(nodo->left, min, max, hd-1);
    findMinMax(nodo->right, min, max, hd+1);
}

void printVerticalLine(nodo *nodo, int line_no, int hd) {
    // Base case
    if (nodo == NULL) return;

    // If this nodo is on the given line number
    if (hd == line_no) {
      nodo->vertical = line_no;
      cout << nodo->num << "(" << nodo->horizontal << ")" << "(" << nodo->vertical << ")" <<  "" <<" ";
    }
        // cout << "line_no es" << line_no;
        // nodo->vertial

    // Recur for left and right subtrees
    printVerticalLine(nodo->left, line_no, hd-1);
    printVerticalLine(nodo->right, line_no, hd+1);
}

void verticalOrder(nodo *root) {
    // Find min and max distances with resepect to root
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    // Iterate through all possible vertical lines starting
    // from the leftmost line and print nodos line by line
    for (int line_no = min; line_no <= max; line_no++)
    {
        printVerticalLine(root, line_no, 0);
        cout << endl;
    }
}

#endif
