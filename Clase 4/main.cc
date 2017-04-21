//Listas enlazadas

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "nodo.h"

using namespace std;

int main(int argc, char const *argv[]) {
  nodo *p = crear_nodo(2, 3);
  // p->x = 2;
  // p->y = 3;
  cout << "nodo p " << p->x << " " << p->y;

  agregar_nodo(p, 5, 6);
  agregar_nodo(p, 7, 8);
  agregar_nodo(p, 9, 10);
  agregar_nodo(p, 11, 12);


  imprimir_lista(p);
  // cout << "\n";
  // nodo *p2 = crear_nodo(8, 9);
  // p->nexo = p2;
  // p2->x = 10;
  // p2->y = 20;
  //
  // cout << "nodo nexo de p " << (p->nexo)->x << " " << (p->nexo->y);
  //
  // p2->x = 109;
  //
  // cout << "\n";
  //
  // cout << "nodo nexo de p " << (p->nexo)->x << " " << (p->nexo->y);
  //
  //
  // nodo *p3 = crear_nodo(10999, 11);
  // agregar_nexo(p2, p3);
  //
  // cout << p2->nexo->x;
  cout << "\n";

  return 0;
}
