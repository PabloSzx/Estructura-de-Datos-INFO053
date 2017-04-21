#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  int diferencia = atoi(argv[1]);
  int raiz = 0;

  for (int i = 0; i <= (n / 2); i++) {
    if ((n - (i * i)) >= 0) {
      if ((n - (i * i)) < diferencia) {
        diferencia = (n - (i * i));
        raiz = i;
      }
    } else {
      if ((n + (i * i)) < diferencia) {
        diferencia = (n - (i * i));
        raiz = i;
      }
    }

  }

  printf("La raiz entera mas cercana es: %i\n", raiz);
  return 0;
}
