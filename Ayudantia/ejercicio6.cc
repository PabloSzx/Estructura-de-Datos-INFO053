#include <stdlib.h>
#include <stdio.h>

bool esPrimo(int n) {

  int divisores = 0;

  for (int i = 1; i <= n; i++) {
    if ((n % i) == 0) {
      divisores++;
    }
  }

  if (divisores == 2) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char *argv[]) {
  int i = 0;

  int n = 0;

  while (i <= atoi(argv[1])) {
    if (esPrimo(n)) {
      printf("%i\n", n);
      i++;
    }
    n++;
  }

  return 0;
}
