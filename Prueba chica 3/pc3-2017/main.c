#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "nodo.h"

#define MAXDEPTH 200

int main(int argc, char **argv){
	if(argc != 2){
		fprintf(stderr, "ejecutar como ./prog n\n");
		exit(EXIT_FAILURE);
	}
	int padres[MAXDEPTH];
	int n = atoi(argv[1]);
	srand(time(NULL));
	nodo *r = NULL;
	for(int i=0; i<n; ++i){
		bst_insertar(&r, rand()%99);
	}
	// antes de balancear
	printf("**** ANTES ****\n");
	imprimir(r, 0, padres);
	printf("\naltura = %i\n", altura(r));
	printf("desbalanceado = %i\n", desbalanceado(r));
	printf("dpath = %i\n\n", dpath(r));

	printf("balanceando......."); fflush(stdout);
	balancear(&r);
	printf("ok\n\n"); fflush(stdout);


	printf("**** DESPUES ****\n");
	imprimir(r, 0, padres);
	printf("\naltura = %i\n", altura(r));
	printf("desbalanceado = %i\n", desbalanceado(r));
	printf("dpath = %i\n", dpath(r));
	return EXIT_SUCCESS;
}
