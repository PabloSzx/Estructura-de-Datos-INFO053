#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "nodo.h"
#include <iostream>

#define MAXDEPTH 100

using namespace std;
int main(int argc, char **argv){
  int padres[MAXDEPTH];
  nodo *r = NULL;

  bst_insertar(&r, 10);
  bst_insertar(&r, 20);
  bst_insertar(&r, 30);
  bst_insertar(&r, 40);
  bst_insertar(&r, 50);
  // bst_insertar(&r, 5);
  // bst_insertar(&r, 2);
  // bst_insertar(&r, 8);
  // bst_insertar(&r, 9);
  // bst_insertar(&r, 4);



  cout << endl << endl;
  imprimir(r, 0, padres);
  printf("\naltura = %i\n", altura(r));
  printf("\nbfactor = %i\n", bfactor(r));
  if (arbol_balanceado(&r)) {
    cout << "\nEl arbol es balanceado";
  } else {
    cout << "\nEl arbol no es balanceado";
  }


  rot_izq(&r);

  cout << endl << endl;
  imprimir(r, 0, padres);
  printf("\naltura = %i\n", altura(r));
  printf("\nbfactor = %i\n", bfactor(r));
  if (arbol_balanceado(&r)) {
    cout << "\nEl arbol es balanceado";
  } else {
    cout << "\nEl arbol no es balanceado";
  }



  cout << endl << endl;

  bst_eliminar(&r);
  imprimir(r, 0, padres);
  printf("\naltura = %i\n", altura(r));
  printf("\nbfactor = %i\n", bfactor(r));
  if (arbol_balanceado(&r)) {
    cout << "\nEl arbol es balanceado";
  } else {
    cout << "\nEl arbol no es balanceado";
  }


  cout << endl << endl;

  bst_eliminar(bst_buscar_puntero(&r, 5));
  imprimir(r, 0, padres);
  printf("\naltura = %i\n", altura(r));
  printf("\nbfactor = %i\n", bfactor(r));
  if (arbol_balanceado(&r)) {
    cout << "\nEl arbol es balanceado";
  } else {
    cout << "\nEl arbol no es balanceado";
  }



  cout << "\n\n\n";
  cout << "\n";
  return EXIT_SUCCESS;
}
