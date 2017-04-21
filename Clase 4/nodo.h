#ifndef NODO_H
#define NODO_H

using namespace std;

typedef struct nodo{
  int x;
  int y;
  nodo *nexo;
}nodo;

nodo* crear_nodo(int x, int y){
  nodo *n = (nodo*)malloc(sizeof(nodo));
  n->x = x;
  n->y = y;
  n->nexo = NULL;
  return n;
}

void agregar_nexo(nodo *n, nodo *elem) {
  n->nexo = elem;
}

void imprimir_lista(nodo* p) {
  nodo *aux = p;
  while(aux != NULL) {
    cout << "\nnodo " << aux->x << " " << aux->y;
    aux = aux->nexo;
  }
}

void agregar_nodo(nodo* p, int x, int y) {
  nodo *a = crear_nodo(x, y);
  nodo *aux = p;
  while(aux->nexo != NULL) {
    aux = aux->nexo;
  }
  aux->nexo = a;
}

// void agregar_elemento(nodo *lista, nodo *elem, int pos) {
//   int contador = 0;
//   bool rest = false;
//   nodo *p = *lista->nexo;
//   while ((p->nexo) !== NULL) {
//     contador++;
//     if (contador == pos) {
//       p->nexo = elem;
//       rest = true;
//     }
//
//     if !(rest) {
//       p = p->nexo;
//     }
//     // else {
//     //   // p =
//     //   p->nexo = p;
//     // }
//   }
//   while
// }

#endif
