#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cola.h"
#include <iostream>

using namespace std;

int main() {

  arbol *arb = arbol_crear(5);

  arbol_insertar(&arb, 4);
  arbol_insertar(&arb, 6);
  arbol_insertar(&arb, 8);
  arbol_insertar(&arb, 9);
  arbol_insertar(&arb, 2);

  arbol_imprimir(arb);


  return EXIT_SUCCESS;
}
