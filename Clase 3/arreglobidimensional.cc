#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <iostream>


int main(int argc, char const *argv[]) {

  // int a[24];  // a[i]
  // definir un arreglo con punteros
  int *a = (int *)malloc(sizeof(int)*24);
  // Matriz de doble puntero
  int **m = (int **)malloc(sizeof(int)*4);
  for (int i = 0; i < 4; i++) {
    m[i] = (int *)malloc(sizeof(int)*5);
  }

  // m[i][j]
  m[2][4] = 25;
  // a[2] = 25;

  std::cout << m[2][4];

  return EXIT_SUCCESS;
}
