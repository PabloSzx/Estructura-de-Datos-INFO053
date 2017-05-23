#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 1000

typedef struct heap{
  int data[MAX]; //arbol con espacio max
  int n;  //numero de elementos
}heap;

using namespace std;

void init(heap *h){
  h->n = 0;
  h->data[0] = -INT_MAX; //dato auxiliar
}

void insertar(heap *h, int x) {
  // ejercicio 1
  h->n++;
  h->data[h->n] = x;

  int pos = h->n;

  while (h->data[pos/2] > x) {
    h->data[pos] = h->data[pos/2];
    pos /= 2;
  }
  h->data[pos] = x;
}

void imprimir(heap *h) {
  cout << "heap n=" << h->n << endl;
  for (int i = 1; i <= h->n; i++) {
    cout << h->data[i] << endl;
  }

  cout << endl;

}

int menor(heap *h, int i) {
  int m = i;

  if ((2 * i <= h->n) && (h->data[m] > h->data[2*i])) {
    m = 2 * i;
  }

  if ((((2 * i) + 1) <= h->data[m]) && (h->data[m] > h->data[(2 * i) + 1])) {
    m = (2 * i) + 1;
  }

  return m;
  // return (h->data[i * 2] < h->data[(i * 2) + 1]) ? (i * 2) : ((i * 2) + 1);
}

void heapify(heap *h, int i) {
  int posMenor = menor(h, i);
  if ((h->data[posMenor]) < h->data[i]) {
    int valActual = h->data[i],
    valMenor = h->data[posMenor];
    h->data[i] = valMenor;
    h->data[posMenor] = valActual;
    heapify(h, posMenor);
  }
}

//eliminar el minimo
int eliminar(heap *h) {
  int padre = h->data[1];

  h->data[1] = h->data[h->n];
  h->n--;


  heapify(h, 1);
  return padre;
}

int main(int argc, char const *argv[]) {
  heap h;
  init(&h);

  //insertando valores arbitrarios
  insertar(&h, 9);
  insertar(&h, 8);
  insertar(&h, 6);
  insertar(&h, 7);
  insertar(&h, 6);
  insertar(&h, 1);
  insertar(&h, 5);


  imprimir(&h);

  eliminar(&h);
  cout << "eliminamos" << endl;

  imprimir(&h);
  eliminar(&h);
  cout << "eliminamos" << endl;

  imprimir(&h);
  eliminar(&h);
  cout << "eliminamos" << endl;

  imprimir(&h);
  eliminar(&h);
  cout << "eliminamos" << endl;

  imprimir(&h);
  eliminar(&h);
  cout << "eliminamos" << endl;

  imprimir(&h);
  eliminar(&h);
  cout << "eliminamos" << endl;

  imprimir(&h);
  eliminar(&h);
  cout << "eliminamos" << endl;

  imprimir(&h);

  return 0;
}
