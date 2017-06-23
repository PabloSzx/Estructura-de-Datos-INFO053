#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <omp.h>
#include <iostream>
#include <ctime>
#define RANGO 10000

using namespace std;


void quicksort(int *a, int l, int r);
void insercion(int *a, int n);

int particion(int *a, int l, int r);
void imprimir(int *a, int n);


void start_time_count(clock_t* start) {
  (*start) = clock();
}

void end_time_count(clock_t* end) {
  (*end) = clock();
}

void calculate_duration(clock_t* start, clock_t* end, int tipo) {
  // cout << CLOCKS_PER_SEC << endl;
  double duration = ((*end) - (*start)) / (double) CLOCKS_PER_SEC;

  if (tipo == 0) {
    cout << "QuickSort se demoró " << duration << endl;
  } else if (tipo == 1){
    cout << "Insercion se demoró " << duration << endl;
  } else if (tipo == 2) {
    cout << "Ordenamiento por insercion se demoró " << duration << " segundos" << endl;
  }
}


int main(int argc, char **argv) {
  if(argc != 2){
    fprintf(stderr, "ejecutar como ./prog n\n");
    exit(EXIT_FAILURE);
  }
  srand(time(NULL));
  int n = atoi(argv[1]);
  int *a = (int*)malloc(sizeof(int)*n);
  int *b = (int*)malloc(sizeof(int)*n);

  clock_t start;
  clock_t end;


  start_time_count(&start);

  // generar arreglos (a y b deben ser iguales)
  for(int i = 0; i < n; ++i){
    a[i] = rand()%RANGO;
    b[i] = a[i];
  }

  end_time_count(&end);
  calculate_duration(&start, &end, 1);
  if(n < 50){
    printf("\na[] desordenado:\n");
    imprimir(a, n);
    printf("\nb[] desordenado:\n");
    imprimir(b, n);
    printf("\n\n");
  }
  printf("quicksort......."); fflush(stdout);
  start_time_count(&start);

  quicksort(a, 0, n-1);
  end_time_count(&end);

  calculate_duration(&start, &end, 0);

  printf("ok\n"); fflush(stdout);
  printf("insercion......."); fflush(stdout);
  start_time_count(&start);

  insercion(b, n);
  end_time_count(&end);

  calculate_duration(&start, &end, 2);

  printf("ok\n"); fflush(stdout);
  if(n < 50){
    printf("\na[] ordenado:\n");
    imprimir(a, n);
    printf("\nb[] ordenado:\n");
    imprimir(b, n);
    printf("\n\n");
  }
  // printf("tiempos:\nquicksort %f s\ninsercion %f s\n");


  // duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

  // cout <<"se demoro: "<< duration <<'\n';
}

void quicksort( int *a, int l, int r){
  int j;
  if( l < r ){
    j = particion( a, l, r);
    quicksort(a, l, j-1);
    quicksort(a, j+1, r);
  }
}

int particion( int *a, int l, int r) {
  int pivot, i, j, t;
  pivot = a[l];
  i = l; j = r+1;
  while(1){
    do ++i; while(a[i] <= pivot && i <= r);
    do --j; while(a[j] > pivot);
    if( i >= j ){
      break;
    }
    t = a[i]; a[i] = a[j]; a[j] = t;
  }
  t = a[l]; a[l] = a[j]; a[j] = t;
  return j;
}

void imprimir(int *a, int n){
  for(int i = 0; i < n; ++i){
    printf("%d ", a[i]);
  }
}


void insercion(int *a, int n){
  int t;
  for (int c = 1 ; c <= n - 1; c++) {
    int d = c;
    while ( d > 0 && a[d] < a[d-1]) {
      t = a[d];
      a[d]   = a[d-1];
      a[d-1] = t;
      d--;
    }
  }
}
