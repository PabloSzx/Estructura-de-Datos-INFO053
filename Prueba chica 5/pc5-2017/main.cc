#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#define LIM 1000

using namespace std;

// global values
int a, b, n, m, p, seed;

#include "node.h"
#include "hash.h"

static const char alfabeto[] =
"abcdefghijklmnopqrstuvwxyz";

char genRandom() {
    return alfabeto[rand() % (sizeof(alfabeto) - 1)];
}

char *genPalabra() {

  char* ret = (char*)malloc(sizeof(char)*10);
  for (int i = 0; i < 10; i++) {
    ret[i] = genRandom();
  }

  return (ret);
}


int main(int argc, char **argv){
    if(argc != 3){
        fprintf(stderr, "ejecutar como ./prog m n\n");
        exit(EXIT_FAILURE);
    }
    // reiniciar el prng en estado asociado al '101;
    m = atoi(argv[1]);
    n = atoi(argv[2]);

    seed = time(NULL);

    srand(seed);

    // generar una funcion hash de forma aleatoria
    printf("generando una funcion hash para m=%i.....", m); fflush(stdout);
    gen_hashfunc(m, &a, &b, &p);
    printf("ok\n"); fflush(stdout);

    // allocando tabla hash
    printf("malloc ht..."); fflush(stdout);
    nodo **ht = (nodo**)malloc(sizeof(nodo*)*m);
    for(int i=0; i<m; ++i){
        ht[i] = NULL;
    }
    printf("ok\n"); fflush(stdout);

    // insertar N numeros aleatorios
    printf("insertando %i elementos...", n); fflush(stdout);
    for(int i=0; i<n; ++i){
      char *palabra = genPalabra();
        insert(ht, rand()%LIM , h2, palabra);
    }
    printf("ok\n"); fflush(stdout);

    printf("hash table:\n");
    print_ht(ht, m);
    return EXIT_SUCCESS;
}
