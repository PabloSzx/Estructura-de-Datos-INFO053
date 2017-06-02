#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "heap.h"
#include "maxheap.h"
#define TOPE 200;

void imprime_array(int *nums, int n, const char *msg);


// ejercicio (1) ordenar
void ordenar1(int *nums, int n){
  heap *h = heap_crear();
  for (int i = 0; i < n; i++) {
    heap_insertar(h, nums[i]);
  }

  for (int i = 0; i < n; i++) {
    nums[i] = heap_eliminar(h);
  }
}

// ejercicio (2) ordenar
void ordenar2(int *nums, int n){
  maxheap *h = maxheap_crear();
  for (int i = 0; i < n; i++) {
    maxheap_insertar(h, nums[i]);
  }

  for (int i = 0; i < n; i++) {
    nums[i] = maxheap_eliminar(h);
  }
}

int main(int argc, char **argv){
  if(argc!=2){
    fprintf(stderr, "ejecutar como ./prog n\n");
    exit(EXIT_SUCCESS);
  }
  // crear un arreglo de n numeros aleatorios
  int n = atoi(argv[1]);
  int *nums = (int*)malloc(sizeof(int)*n);

  srand(time(NULL));
  for(int i=0; i<n; ++i){
    nums[i] = rand() % TOPE;
  }


  // imprime numeros desordenados
  if(n<30){
    imprime_array(nums, n, "desordenado:");
  }




  printf("< ordenando1......."); fflush(stdout);
  // ordenar numeros
  // ....
  ordenar1(nums,n);
  // ....
  printf("ok >\n\n"); fflush(stdout);

  // imprime numeros ordenados
  if(n<30){
    imprime_array(nums, n, "ordenado1:");
  }



  printf("< ordenando2......."); fflush(stdout);
  // ordenar numeros
  // ....
  ordenar2(nums,n);
  // ....
  printf("ok >\n\n"); fflush(stdout);

  // imprime numeros ordenados
  if(n<30){
    imprime_array(nums, n, "ordenado2:");
  }

  return EXIT_SUCCESS;
}

void imprime_array(int *nums, int n, const char *msg){
  printf("%s\n", msg);
  for(int i=0; i<n; ++i){
    printf("%i ", nums[i]);
  }
  printf("\n\n");
}
