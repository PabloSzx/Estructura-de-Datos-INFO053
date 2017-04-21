#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int n1 = atoi(argv[1]);
  int n2 = atoi(argv[2]);
  int multiplicacion = 0;

  for (int i = 0; i < n2; i++) {
    multiplicacion = multiplicacion + n1;
  }

  printf("La multiplicacion es: %i\n", multiplicacion);
  return 0;
}
