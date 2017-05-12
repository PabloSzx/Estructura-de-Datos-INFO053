#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arbol.h"
#include "pila.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {

  srand((unsigned int) time (NULL));
  int limit = 20;
  int n;
  int largo = rand() % limit;

  arbol *arb = arbol_crear(rand() % limit);

  for (int i = 0; i < 8; i++) {
    n = (rand() % limit) * i;
    arbol_insertar(&arb, n);
  }

  imprimir_arbol_preorden(&arb);

  designarHorizontal(&arb);
  verticalOrder(arb->c);

  cout << "\nEl arbol tiene " << arb->largo << " nodos\n";

  return EXIT_SUCCESS;
}
