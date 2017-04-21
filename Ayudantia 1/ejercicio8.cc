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

  int *x = (int *)malloc(sizeof(int)*atoi(argv[1]));

  printf("Generando arreglo x\n");
  for(int j=0;j<atoi(argv[1]);j++){
    x[j]=(rand()%99)+1;
    printf("%i \n", x[j]);
  }

  int lYes = 0;
  int lNo = 0;
  int nYes = 0;
  int nNo = 0;

  for (int i = 0; i < atoi(argv[1]); i++) {
    if (esPrimo(x[i])) {
      lYes++;
    } else {
      lNo++;
    }
  }

  int *arregloPrimos = (int *)malloc(sizeof(int)*lYes);
  int *arregloNoPrimos = (int *)malloc(sizeof(int)*lNo);

  for (int i = 0; i < atoi(argv[1]); i++) {
    if (esPrimo(x[i])) {
      arregloPrimos[nYes] = x[i];
      nYes++;
    } else {
      arregloNoPrimos[nNo] = x[i];
      nNo++;
    }
  }

  printf("\nArreglo de primos: \n");
  for (int i = 0; i < lYes; i++) {
    printf("%i\n", arregloPrimos[i]);
  }

  printf("\nArreglo de no primos: \n");
  for (int i = 0; i < lNo; i++) {
    printf("%i\n", arregloNoPrimos[i]);
  }

  return 0;
}
