#include <iostream>
#include <stdlib.h>

using namespace std;

void quickSort(int *array, int low, int high);

int partition(int *array, int low, int high);

void quickSort(int *array, int low, int high) {
  if (low < high) {
    int pivot = partition(array, low, high);

    quickSort(array, low, pivot - 1); //antes del pivot
    quickSort(array, pivot + 1, high); //despues del pivot
  }
}

int partition(int *array, int low, int high) {
  int pivot = array[high]; //el pivot se elige como el ultimo elemento del arreglo

  int aux;
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (array[j] <= pivot) {
      i++;
      aux = array[i];
      array[i] = array[j];
      array[j] = aux;
    }
  }

  aux = array[i + 1];

  array[i + 1] = array[high];
  array[high] = aux;

  return (i + 1);
}

void imprimir(int *array, int n) {
  cout << "[";
  for (int i = 0; i < n; i++) {
    cout << array[i];
    if (i < n - 1) {
      cout << "-";
    }
  }
  cout << "]" << endl;
}


int main(int argc, char const *argv[]) {
  int n = 50000000;
  double t1;
  double t2;

  int seed = time(NULL);

  int *arreglo=(int*)malloc(sizeof(int)*n);
  srand(seed);

  for(int i = 0; i < n;i++){
    arreglo[i] = rand()%10000;
  }


  // imprimir(arreglo, n);

  cout << "Quick Sort" << endl;
  t1 = time(NULL);
  quickSort(arreglo, 0, n - 1);
  t2 = time(NULL);
  cout << "QuickSort se demoró: " << t2 - t1 << endl;

  // imprimir(arreglo, n);


  return 0;
}
