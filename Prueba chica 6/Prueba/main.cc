#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <omp.h>
#include <iostream>
#include <ctime>
#define RANGO 10000

using namespace std;


void quicksort(int *a, int l, int r, int p);
void insercion(int *a, int n);

int particion(int *a, int l, int r, int p);
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

int check_ordenado(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      return 0;
    }
  }

  return 1;
}

int* generar_arreglo(int tipo, int n) {
  srand(time(NULL));
  int *arreglo = (int*)malloc(sizeof(int)*n);
  if (tipo == 0) {
    for(int i = 0; i < n; ++i){
      arreglo[i] = rand()%RANGO;
    }
  } else {
    for (int i = n; i > 0; i--) {
      arreglo[n - i] = i;
    }
  }


  return arreglo;
}


int main(int argc, char **argv) {
  if(argc != 4){
    fprintf(stderr, "ejecutar como ./prog n c\n");
    exit(EXIT_FAILURE);
  }
  int n = atoi(argv[1]);
  int c = atoi(argv[2]);
  int p = atoi(argv[3]);
  int *a = (int*)malloc(sizeof(int)*n);
  int *b = (int*)malloc(sizeof(int)*n);

  clock_t start;
  clock_t end;


  start_time_count(&start);

  // generar arreglos (a y b deben ser iguales)
  a = generar_arreglo(c, n);
  b = a;
  // for(int i = 0; i < n; ++i){
  //   a[i] = rand()%RANGO;
  //   b[i] = a[i];
  // }

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

  quicksort(a, 0, n-1, p);
  end_time_count(&end);

  calculate_duration(&start, &end, 0);

  printf("ok\n"); fflush(stdout);
  cout << "checkeando si el usado con quicksort esta ordenado...";
  if (check_ordenado(a, n)) {
    cout << "ok, esta ordenado" << endl;
  } else {
    cout << "no está ordenado" << endl;
  }

  printf("insercion......."); fflush(stdout);
  start_time_count(&start);

  insercion(b, n);
  end_time_count(&end);

  calculate_duration(&start, &end, 2);

  printf("ok\n"); fflush(stdout);

  cout << "checkeando si el usado con insercion esta ordenado...";
  if (check_ordenado(a, n)) {
    cout << "ok, esta ordenado" << endl;
  } else {
    cout << "no está ordenado" << endl;
  }

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

void quicksort( int *a, int l, int r, int p){
  int j;
  if( l < r ){
    j = particion(a, l, r, p);
    quicksort(a, l, j-1, p);
    quicksort(a, j+1, r, p);
  }
}

int particion( int *a, int l, int r, int p) {
  srand(time(NULL));
  int pivot, i, j, t, pivot_index;

  if (p == 0) {
    pivot = a[l];
  } else {
    pivot_index = l + rand() % (r - l);
    // pivot_index = (rand()%(r - l));
    pivot = a[pivot_index];
    // if (pivot == l) {
    //   pivot+=1;
    // }
    //
    // if (pivot == r) {
    //   pivot-=1;
    // }
  }
  cout << "-----" << endl;
  cout << "l es " << l << endl;
  cout << "pivot es " << pivot << endl;
  cout << "r es " << r << endl;
  cout << "-----" << endl;
  i = l; j = r + 1;
  while(1){
    do ++i; while(a[i] <= pivot && i <= r);
    do --j; while(a[j] > pivot);
    if( i >= j ){
      break;
    }
    t = a[i]; a[i] = a[j]; a[j] = t;
  }
  t = a[pivot_index]; a[pivot_index] = a[j]; a[j] = t;
  return j;
}


// int particion( int *a, int l, int r, int p) {
//     int pivot, i, j, t, pivot_index;
//     pivot = a[l];
//
//       if (p == 0) {
//         pivot = a[l];
//       } else {
//         pivot_index = (rand()%(r - l));
//         pivot = l + pivot_index;
//         // if (pivot == l) {
//         //   pivot+=1;
//         // }
//         //
//         // if (pivot == r) {
//         //   pivot-=1;
//         // }
//       }
//
//     i = l; j = r+1;
//     while(1){
//         do ++i; while(a[i] <= pivot && i <= r);
//         do --j; while(a[j] > pivot);
//         if( i >= j ){
//             break;
//         }
//         t = a[i]; a[i] = a[j]; a[j] = t;
//     }
//     t = pivot; a[pivot_index] = a[j]; a[j] = t;
//     return j;
// }

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
