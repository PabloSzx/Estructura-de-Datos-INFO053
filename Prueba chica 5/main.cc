#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#define LIM 1000

// global values
int a, b, n, m, p, seed;

#include "node.h"
#include "hash.h"

using namespace std;

static const char alphanum[] =
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom() {
    return alphanum[rand() % stringLength];
}

char* genPalabra() {
  char ret[10];
  for (size_t i = 0; i < 10; i++) {
    ret[i] = alphanum[rand() % stringLength];
  }

  return ret;
}

int main(int argc, char **argv){
    if(argc != 3){
        fprintf(stderr, "ejecutar como ./prog m n\n");
        exit(EXIT_FAILURE);
    }
    // reiniciar el prng en estado asociado al '101;
    m = atoi(argv[1]);
    n = atoi(argv[2]);


    // srand(time(0));
    // for(int z=0; z < 10; z++)
    // {
    //     cout << genRandom();
    //
    // }
    // return 0;

    // generar una funcion hash de forma aleatoria
    printf("generando una funcion hash para m=%i.....", m); fflush(stdout);
    gen_hashfunc(m, &a, &b, &p);
    printf("ok\n"); fflush(stdout);

    // allocando tabla hash
    seed = time(NULL);
    srand(seed);
    printf("malloc ht..."); fflush(stdout);
    nodo **ht = (nodo**)malloc(sizeof(nodo*)*m);
    for(int i=0; i<m; ++i){
        ht[i] = NULL;
    }
    printf("ok\n"); fflush(stdout);

    // insertar N numeros aleatorios
    printf("insertando %i elementos...", n); fflush(stdout);
    for(int i=0; i<n; ++i){
        // insert(ht, rand()%LIM , h2);

        insert(ht, genPalabra(), h3);

    }
    printf("ok\n"); fflush(stdout);

    // reiniciar el prng en estado asociado al '101;
    srand(seed);
    printf("lookup en %i elementos...", n); fflush(stdout);
    for(int i=0; i<n; ++i){
        exists(ht, rand()%LIM, h2);
    }
    printf("ok\n"); fflush(stdout);

    printf("hash table:\n");
    print_ht(ht, m);
    return EXIT_SUCCESS;
}
