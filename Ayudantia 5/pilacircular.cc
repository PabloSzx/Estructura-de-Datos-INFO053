#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "pilacircular.h"

using namespace std;

int main(int argc, char const *argv[]) {
  lista *l = (lista *)malloc(sizeof(lista));
  l->inicio = NULL;
  l->largo = 0;

  char n[100];
  int e = 0;

  insertar(&l, 10, "pablo");
  insertar(&l, 20, "cristian");
  insertar(&l, 30, "vicente");
  insertar(&l, 12, "jorge");
  insertar(&l, 40, "sebastian");
  insertar(&l, 56, "tito");
  insertar(&l, 23, "matias");

  int seleccion = 0;
  int indice = 0;

  while (1) {
    cout << "\n";
    cout << "0: Ingresar un elemento \n";
    cout << "1: Eliminar un elemento \n";
    cout << "2: Imprimir lista \n";
    cout << "3: Salir \n";
    cout << "Seleccione que operacion deseas: \n";
    cin >> (seleccion);

    switch (seleccion) {
      case 0:
        cout << "Ingrese un nombres: ";
        cin >> n;
        cout << "Ingrese la edad: ";
        cin >> (e);
        insertar(&l, e, n);
        cout << "\nSe ha ingresado la lista \n";
        break;
      case 1:
        eliminar(&l);
        cout << "\nAca uds deben eliminars un elemento";
        break;
      case 2:
        imprimir(&l);
        break;
      case 3:
        exit(0);

    }
  }

  return 0;
}
