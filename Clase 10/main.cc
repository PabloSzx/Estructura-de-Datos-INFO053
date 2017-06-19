#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>

// global values
int a, b, n, m, p, seed;

#include "node.h"
#include "hash.h"

using namespace std;
// using namespacestd::ostringstream oss;
int main(int argc, char **argv){
  if(argc != 3){
    fprintf(stderr, "ejecutar como ./prog m n\n");
    exit(EXIT_FAILURE);
  }
  // reiniciar el prng en estado asociado al '101;
  m = atoi(argv[1]);
  n = atoi(argv[2]);

  // std::ostringstream oss;
  char txt[16];
  int myNum = 2000;
  cout << sprintf(txt, "%d", myNum);
  cout << "---------";
  // cout << itoa(6, 33, );


  // generar una funcion hash de forma aleatoria
  printf("generando una funcion hash para m=%i.....", m); fflush(stdout);
  gen_hashfunc(m, &a, &b, &p);
  printf("ok\n"); fflush(stdout);

  // allocando tabla hash
  seed = time(NULL);
  srand(seed);
  printf("malloc ht..."); fflush(stdout);
  nodo **ht = (nodo**)malloc(sizeof(nodo*)*m);
  for(int i=0; i<n; ++i){
    ht[i] = NULL;
  }
  printf("ok\n"); fflush(stdout);

  // insertar N numeros aleatorios
  printf("insertando %i elementos...", n); fflush(stdout);
  for(int i=0; i<n; ++i){
    inserta(ht, rand());
  }
  printf("ok\n"); fflush(stdout);

  // reiniciar el prng en estado asociado al '101;
  srand(seed);
  printf("lookup en %i elementos...", n); fflush(stdout);
  for(int i=0; i<n; ++i){
    int el = rand();
    if(existe(ht, el)){
      printf("valor %i existe en ht\n", el);
    }
  }
  printf("ok\n"); fflush(stdout);

  printf("hash table:\n");

  cout << endl << endl << endl ;

  cout << mprimo(22) << endl;
  print_ht(ht, m);
  return EXIT_SUCCESS;
}
