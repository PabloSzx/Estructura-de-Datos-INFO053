#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arbol.h"
#include "pila.h"
#include <iostream>

using namespace std;

int main() {

  int start;
  cout << "\nIngrese un valor inicial para el arbol: ";
  cin >> start;
  arbol *arb = arbol_crear(start);

  while (true) {
    cout << "\nLista de comandos: ";
    cout << "\n0.- Ingresar un elemento.";
    cout << "\n1.- Imprimir el arbol en preorden.";

    int choice, n;
    cout << "\n\nIngrese un numero segun el comando que desea realizar: ";
    cin >> choice;
    cout << "\n";
    switch (choice) {
      case 0:
      cout <<"\nIngrese el numero que desea ingresar en el arbol: ";
      cin >> n;
      arbol_insertar(&arb, n);
      break;
      case 1:
      imprimir_arbol_preorden(&arb);
      cout << "\nEl arbol tiene " << arb->largo << " nodos\n";
      break;
      default:
      cout << "\nNo se identifico el comando a realizar!!";
    }
  }

  return EXIT_SUCCESS;
}
