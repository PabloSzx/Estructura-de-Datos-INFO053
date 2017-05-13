#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "nodo.h"
#include <iostream>

#define MAXDEPTH 100

using namespace std;
int main(int argc, char **argv){
    int padres[MAXDEPTH];
    nodo *r = NULL;




    bst_insertar(&r, 5);
    bst_insertar(&r, 2);
    bst_insertar(&r, 8);
    bst_insertar(&r, 9);
    bst_insertar(&r, 4);
    bst_insertar(&r, 10);
    bst_insertar(&r, 11);
    bst_insertar(&r, 3);
    bst_insertar(&r, 1);

    bst_insertar(&r, 15);
    bst_insertar(&r, 17);
    bst_insertar(&r, 19);

    bst_insertar(&r, 20);
    bst_insertar(&r, 22);
    bst_insertar(&r, 24);
    bst_insertar(&r, 30);
    bst_insertar(&r, 35);

    bst_insertar(&r, 40);

    bst_insertar(&r, 42);

    bst_insertar(&r, 48);


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

    balancear(&r);
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
    // bst_insertar(&r, 4);
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
