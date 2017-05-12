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
    cout << "\n2.- Eliminar un elemento.";
    cout << "\n3.- Altura del arbol.";
    cout << "\n4.- Factor de balanceo del arbol.";
    cout << "\n5.- Si el arbol es balanceado.";
    cout << "\n6.- Invertir el arbol en un nodo en especifico.";

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
      case 2:
        cout <<"\nIngrese el numero que desea eliminar en el arbol: ";
        cin >> n;
        arbol_eliminar(&arb, n);
        break;
      case 3:
        altura(&arb);
        break;
      case 4:
        cout << "El factor de balanceo del arbol es: " << bfactor(&arb);
        break;
      case 5:
        if (arbol_balanceado(&arb)) {
          cout << "\nEl arbol es balanceado\n";
        } else {
          cout << "\nEl arbol no es balanceado\n";
        }
        break;
      case 6:
        cout <<"\nIngrese el numero del nodo que va a hacer pivot: ";
        cin >> n;
        arbol_invertir(&arb, n);
        break;

      default:
        cout << "\nNo se identifico el comando a realizar!!";
    }
  }

  return EXIT_SUCCESS;
}
