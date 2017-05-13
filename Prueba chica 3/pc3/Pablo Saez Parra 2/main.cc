#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;
#include <math.h>;
#include "nodo.h";
#include <iostream>;
#include <time.h>;

#define MAXDEPTH 100

using namespace std;
int main(int argc, char **argv){
	int padres[MAXDEPTH];
	nodo *r = NULL;
	srand(time(NULL));

	int n = 50;

	for(int i=0; i<n; ++i){
		bst_insertar(&r, rand()%999);
	}


	int contador = 0;

	cout << endl << endl;
	imprimir(r, 0, padres);
	printf("\naltura = %i\n", altura(r));
	printf("\nbfactor = %i\n", bfactor(r));
	if (arbol_desbalanceado(&r)) {
		cout << "El arbol esta desbalanceado" << endl;
	} else {
		cout << "El arbol esta balanceado" << endl;
	}

	cout << endl;
	cout << "PROCEDEMOS A BALANCEAR" << endl;

	while (arbol_desbalanceado(&r)) {
		balancear(&r);
		if (contador == 40) {
			cout << "Arbol no es totalmente balanceable" << endl;
			break;
		}
		contador++;
	}
	cout << endl << endl;
	imprimir(r, 0, padres);
	printf("\naltura = %i\n", altura(r));
	printf("\nbfactor = %i\n", bfactor(r));
	if (arbol_desbalanceado(&r)) {
		cout << "El arbol esta desbalanceado" << endl;
	} else {
		cout << "El arbol esta balanceado" << endl;
	}

	cout << endl;


	r = NULL;

	bst_insertar(&r, 5);
	bst_insertar(&r, 2);
	bst_insertar(&r, 8);
	bst_insertar(&r, 9);



	cout << endl << endl;
	imprimir(r, 0, padres);
	printf("\naltura = %i\n", altura(r));
	printf("\nbfactor = %i\n", bfactor(r));
	if (arbol_desbalanceado(&r)) {
		cout << "El arbol esta desbalanceado" << endl;
	} else {
		cout << "El arbol esta balanceado" << endl;
	}

	cout << "el dpath del arbol es " << dpath(r);





	cout << "\n\n\n";
	cout << "\n";
	return EXIT_SUCCESS;
}
