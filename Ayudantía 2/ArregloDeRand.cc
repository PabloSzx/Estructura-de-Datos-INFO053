#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  int elementos;
  printf("Ingrese numero de elementos: ");
  scanf("%i", &elementos);

  //Reservamos memoria
  int *arreglo = (int *)malloc(sizeof(int)*elementos);
  //Srand inicia un generador de numeros pseudoaleatorios
  srand(time(NULL));

  for(int i=0;i<elementos;i++){
    arreglo[i]=rand()%100;
    printf("%i \n", arreglo[i]);
  }
  return EXIT_SUCCESS;
}
