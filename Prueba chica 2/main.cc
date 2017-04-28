#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cola.h"
#include "pcolas.h"
#include <iostream>

using namespace std;

int main() {
  pila *p = pcolas_crear();

  cola *c1 = cola_crear();
  cola *c2 = cola_crear();
  cola *c3 = cola_crear();

  cola_insertar(&c1, 10, "perro");
  cola_insertar(&c1, 20, "gato");
  cola_insertar(&c1, 30, "pato");

  cola_insertar(&c2, 1, "valdivia");
  cola_insertar(&c2, 2, "temuco");
  cola_insertar(&c2, 3, "chiloe");

  cola_insertar(&c3, 7, "jugo");
  cola_insertar(&c3, 12, "galleta");
  cola_insertar(&c3, 22, "cafe");

  pcolas_insertar(&p, c1);
  pcolas_insertar(&p, c2);
  pcolas_insertar(&p, c3);
  pcolas_insertar(&p, c1);
  pcolas_insertar(&p, c2);
  pcolas_insertar(&p, c3);
  pcolas_insertar(&p, c1);
  pcolas_insertar(&p, c2);
  pcolas_insertar(&p, c3);
  pcolas_insertar(&p, c1);
  pcolas_insertar(&p, c2);
  pcolas_insertar(&p, c3);

  pcolas_imprimir(&p);

  cout << "\n\n";

  pcolas_eliminar(&p);

  p = pcolas_invertir(&p);

  pcolas_imprimir(&p);


  return EXIT_SUCCESS;
}
