#include <iostream>
#include <math.h>
#include <time.h>
// #include <omp.h>

using namespace std;

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

void selectionSort(int *array, int n) {
  int menor;
  int k;
  for (size_t i = 0; i < n - 1; i++) {
    menor = array[i];
    k = i;
    for (size_t j = i + 1; j < n; j++) {
      if (array[j] < menor) {
        menor = array[j];
        k = j;
      }
    }
    array[k] = array[i];
    array[i] = menor;
  }
}

int main(int argc, char const *argv[]) {

  double t1;
  double t2;

  if(argc != 2){
    cout << "ejecutar como ./prog n" << endl;
    exit(EXIT_FAILURE);
  }
  int n = atoi(argv[1]);

  int seed = time(NULL);

  int *arreglo=(int*)malloc(sizeof(int)*n);
  srand(seed);

  for(int i=0;i<n;i++){
    arreglo[i] = rand()%10000;
  }
  t1 = time(NULL);
  selectionSort(arreglo, n);
  t2 = time(NULL);

  cout << "La seleccion se demoró: " << t2 - t1 << endl;
  // imprimir(arreglo, n);





  return 0;
}
