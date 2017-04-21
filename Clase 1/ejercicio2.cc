#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  long suma;
  long promedio;
  for (int i = 1; i < argc; i++) {
    suma = suma + atoi(argv[i]);
  }
  promedio = (suma / (argc - 1));

  printf("Promedio es: %li\n", promedio);
  return 0;
}
