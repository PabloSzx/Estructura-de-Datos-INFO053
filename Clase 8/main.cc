#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 1000

typedef struct heap{
  int data[MAX]; //arbol con espacio max
  int n;  //numero de elementos
}heap;

void heapify(heap *h, int i);
void heapifyInsert(heap *h, int i, int x);
int menor(heap *h, int i);
void init(heap *h);
void imprimir(heap *h);
int eliminar(heap *h);


using namespace std;

void init(heap *h){
  h->n = 0;
  h->data[0] = -INT_MAX; //dato auxiliar
}

void insertar(heap *h, int x) {
  h->n++;
  h->data[h->n] = x;

  heapifyInsert(h, h->n, x);
}

void heapifyInsert(heap *h, int i, int x) {
  if (h->data[i/2] > x) {
    h->data[i] = h->data[i/2];
    heapifyInsert(h, i/2, x);
  } else {
    h->data[i] = x;
  }
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
  // insertando valores arbitrarios
  insertar(&h, 9);
  insertar(&h, 8);
  insertar(&h, 6);
  insertar(&h, 7);
  insertar(&h, 6);
  insertar(&h, 1);
  insertar(&h, 5);

  imprimir(&h);
  cout << "eliminando " << eliminar(&h) << endl;
  imprimir(&h);
  cout << "eliminando " << eliminar(&h) << endl;
  imprimir(&h);
  cout << "eliminando " << eliminar(&h) << endl;
  imprimir(&h);
  cout << "eliminando " << eliminar(&h) << endl;
  imprimir(&h);
  cout << "eliminando " << eliminar(&h) << endl;
  imprimir(&h);
  cout << "eliminando " << eliminar(&h) << endl;
  imprimir(&h);
  return EXIT_SUCCESS;
}
