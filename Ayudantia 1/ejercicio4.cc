#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);

  int divisores = 0;

  for (int i = 1; i <= n; i++) {
    if ((n % i) == 0) {
      divisores++;
    }
  }

  if (divisores == 2) {
    printf("%i es primo\n", n);
  } else {
    printf("%i no es primo\n", n);
  }

  return 0;
}
