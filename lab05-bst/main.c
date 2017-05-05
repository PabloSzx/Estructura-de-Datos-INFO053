#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "nodo.h"

#define MAXDEPTH 100

int main(int argc, char **argv){
    int padres[MAXDEPTH];
    nodo *r = NULL;
    for(int i=0; i<20; ++i){
        bst_insertar(&r, rand()%99);
    }
    imprimir(r, 0, padres);
    printf("\naltura = %i\n", altura(r));
    imprimir(r, 0, padres);
    printf("\naltura = %i\n", altura(r));
    return EXIT_SUCCESS;
}
