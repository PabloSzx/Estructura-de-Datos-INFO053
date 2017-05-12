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
  // int start = rand() % limit;
  arbol *arb = arbol_crear(5);

  int n;
  int largo = 10;

  // for (int i = start; i < (largo + start); i++) {
  //   arbol_insertar(&arb, i);
  // }
  arbol_insertar(&arb, 4);
  arbol_insertar(&arb, 3);
  arbol_insertar(&arb, 7);
  arbol_insertar(&arb, 6);
  arbol_insertar(&arb, 9);
  arbol_insertar(&arb, 10);
  arbol_insertar(&arb, 11);


  imprimir_arbol_preorden(&arb);

  // altura(&arb);
  cout << "La altura es: " << alturaArbol(&arb);

  // designarHorizontal(&arb);
  // verticalOrder(arb->c);

  cout << "\nEl arbol tiene " << arb->largo << " nodos\n";

  return EXIT_SUCCESS;
}
