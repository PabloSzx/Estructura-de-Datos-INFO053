#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctime>


int main(int argc, char const *argv[]) {
  /* code */
  srand((unsigned int) time (NULL));
  long long n = atoi(argv[1]);
  long long limitante = 10;
  long long suma = 0;
  for (long long i = 0; i < n; i++) {
    suma = suma + (rand() % limitante) ;
    printf("%lli ", rand() % limitante);
    // printf("%i\n", (rand() % divisor));
  }

  printf("\nEl promedio es: %f\n", (float) suma / n);

  return EXIT_SUCCESS;
}
