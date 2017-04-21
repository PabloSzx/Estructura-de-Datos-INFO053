#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int mayor;
  for (int i = 1; i < argc; i++) {
    if (atoi(argv[i]) > mayor) {
      mayor = atoi(argv[i]);
    }
  }

  printf("El numero mayor es: %i\n", mayor);
  return 0;
}
