
//Escriba un programa que reciba un entero "i" y "c, genere dos arreglos de tamaño "i" y calcule y[i] = c*x[i] + y[i]

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int i = atoi(argv[1]);
  int c = atoi(argv[2]);
  srand(time(NULL));


  int *x = (int *)malloc(sizeof(int)*i);
  //Srand inicia un generador de numeros pseudoaleatorios
  printf("Generando arreglo x\n");
  for(int j=0;j<i;j++){
    x[j]=rand()%10;
    printf("%i \n", x[j]);
  }


  int *y = (int *)malloc(sizeof(int)*i);
  //Srand inicia un generador de numeros pseudoaleatorios

  printf("Generando arreglo y\n");
  for(int j=0;j<i;j++){
    y[j]=rand()%10;
    printf("%i \n", y[j]);
  }

  // int *y = (int *)malloc(sizeof(int)*i);


  for (int j = 0; j < i; j++) {
    y[j] = (c * x[j]) + y[j];
  }

  printf("Arreglo y sumado con arreglo x\n");
  for (int j = 0; j < i; j++) {
    printf("%i\n", y[j]);
  }

  return 0;
}
