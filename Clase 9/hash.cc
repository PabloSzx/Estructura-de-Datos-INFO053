#include "stdio.h"
#include "stdlib.h"
#include <iostream>

//implementar hashing h(x) = x % 20
// rango 0.. 19
// h[0], h[1], ..., h[19]

int h(int num, int U) {
  return num % U;
}
using namespace std;
//elemento del hash
typedef struct nodo {
  int num;
  nodo* nexo;
} nodo;

nodo* nodo_crear(int num) {
  nodo *a = (nodo*)malloc(sizeof(nodo));
  a->num = num;
  a->nexo = NULL;
  return a;
}

//hash insertar
void hash_insertar(nodo **tabla, int num, int U) {
  // 1) buscar donde insertar, con, int pos = h(x)
  int pos = h(num, U);
  // 2) RECORRER LA LISTA ENLAZADA e insertar al final
  nodo *aux = tabla[pos];
  nodo *q = nodo_crear(num);

  if (aux == NULL) {
    tabla[pos] = q;
    return;
  }

  // si no, ubicarlo adelante
  q->nexo = aux;
  tabla[pos] = q;
  // while (aux != NULL) {
  //   aux = aux->nexo;
  // }

  aux = nodo_crear(num);

}

void hash_imprimir(nodo** tabla, int largo) {
  // recorremos cada lista
  for (size_t i = 0; i < largo; i++) {
    nodo *aux = tabla[i];
    cout << "tabla[" << i << "]: ";

    while (aux != NULL) {
      cout << "(" << aux->num << ") ";
      aux = aux->nexo;
    }

    cout << endl;
  }
}

nodo* hash_buscar(nodo *tabla, int num) {

return NULL;
}


int main(int argc, char const *argv[]) {
  if (argc != 3) {
    cout << "./prog n U";
    exit(EXIT_FAILURE);
  }

  int n = atoi(argv[1]);
  int U = atoi(argv[2]);
  //crear una tabla
  nodo **tabla = (nodo**)malloc(sizeof(nodo*)*U);
  for (size_t i = 0; i < U; i++) {
    tabla[i] = NULL;
  }

  // insertar n elementos valores aleatorios
  for (size_t i = 0; i < n; i++) {
    hash_insertar(tabla, rand()%1000, U);
  }

  hash_imprimir(tabla, n);


  return 0;
}
