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

  int limit = 10;
  int start = rand() % limit;
  arbol *arb = arbol_crear(start);

  int n;
  int largo = 10;

  for (int i = start; i < (largo + start); i++) {
    arbol_insertar(&arb, i);
  }

  imprimir_arbol_preorden(&arb);

  verticalOrder(arb->c);

  cout << "\nEl arbol tiene " << arb->largo << " nodos\n";

  return EXIT_SUCCESS;
}
