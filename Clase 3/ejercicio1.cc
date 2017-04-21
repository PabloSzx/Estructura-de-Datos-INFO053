#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <iostream>
#include <math.h>
#define RANGO 1000


// 1) generar N puntos aleatorios (x, y):
  // a) encontrar el que tiene maximo (x, y)
  // b) encontrar el par de puntos mas cercanos
  // c) los puntos que conforman el perimetro de la nube de puntos

// estructura punto: p = (x, y)

typedef struct{
  float x;
  float y;
} punto;

float distancia(int x1, int y1, int x2, int y2) {
  return sqrt(pow((x2 - x1), 2)+pow((y2 - y1), 2));
}

int main(int argc, char const *argv[]) {
  int n = atoi(argv[1]);
  punto *array = (punto*)malloc(sizeof(punto)*n);

  srand((unsigned int) time (NULL));

  int limitante = 100;


  for (int i = 0; i < n; i++) {
    array[i].x = (rand() % limitante);
    array[i].y = (rand() % limitante);
  }

  for (int i = 0; i < n; i++) {
    std::cout << "\n";
    std::cout << i;
    std::cout << ": ";
    std::cout << "\nEl punto x es: ";
    std::cout << array[i].x;
    std::cout << " El punto y es: ";
    std::cout << array[i].y;

  }

  int xmayor = array[1].x;
  int ymayor = array[1].y;
  int indice = 1;
  for (int i = 1; i < n; i++) {
    if ((array[i].x > xmayor) & (array[i].y > ymayor)) {
      xmayor = array[i].x;
      ymayor = array[i].y;
      indice = i;
    }
  }

  std::cout << "\n\nEl punto mayor está en el indice: ";
  std::cout << indice;
  std::cout << "\nY el punto es: ";
  std::cout << xmayor;
  std::cout << ", ";
  std::cout << ymayor;

  float cercaniaMenor;
  int cercaniaIndice1 = 0;
  int cercaniaIndice2 = 1;
  int punto1x = array[1].x;
  int punto1y = array[1].y;
  int punto2x = array[2].x;
  int punto2y = array[2].y;

  cercaniaMenor = distancia(punto1x, punto1y, punto2x, punto2y);

  float cercaniaTemp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        punto1x = array[i].x;
        punto1y = array[i].y;
        punto2x = array[j].x;
        punto2y = array[j].y;
        cercaniaTemp = distancia(punto1x, punto1y, punto2x, punto2y);

        if (cercaniaTemp < cercaniaMenor) {
          cercaniaIndice1 = i;
          cercaniaIndice2 = j;
          cercaniaMenor = cercaniaTemp;
        }

      }
    }

  }

  std::cout << "\n\nEl par de puntos mas cercanos estan en los indices: ";
  std::cout << cercaniaIndice1;
  std::cout << ", ";
  std::cout << cercaniaIndice2;
  std::cout << "\nLa distancia es: ";
  std::cout << cercaniaMenor;
  std::cout << "\n Y los puntos son: ";
  std::cout << array[cercaniaIndice1].x;
  std::cout << ", ";
  std::cout << array[cercaniaIndice1].y;
  std::cout << " y ";
  std::cout << array[cercaniaIndice2].x;
  std::cout << ", ";
  std::cout << array[cercaniaIndice2].y;






  int *nube = (int*)malloc(sizeof(int)*n);

  std::cout << "\n";
  return 0;
}
