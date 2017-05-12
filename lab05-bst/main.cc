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
    // for(int i=0; i<20; ++i){
    //     bst_insertar(&r, rand()%99);
    // }
    // nodo* der = crear_nodo(5);
    // nodo* izq = crear_nodo(4);

    // r = crear_nodo(5);
    // r->izq = crear_nodo(4);
    // r->der = crear_nodo(7);
    //
    //
    // (r)->izq->izq = crear_nodo(3);
    // (r)->izq->der = crear_nodo(9);
    //
    // (r)->der->izq = crear_nodo(8);
    // (r)->der->der = crear_nodo(6);

    // bst_insertar(&r, 5);
    // bst_insertar(&r, 4);
    // bst_insertar(&r, 7);
    //
    // bst_insertar(&r, 3);
    // // bst_insertar(&r, 9);
    // // bst_insertar(&r, 8);
    // bst_insertar(&r, 6);
    // bst_insertar(&r, 8);
    // bst_insertar(&r, 9);
    // bst_insertar(&r, 10);
    // bst_insertar(&r, 12);
    // bst_insertar(&r, 13);

    bst_insertar(&r, 5);
    bst_insertar(&r, 2);
    bst_insertar(&r, 8);
    // bst_insertar(&r, 9);
    // bst_insertar(&r, 4);


    // cout << "\n caca";
    if (arbol_balanceado(&r)) {
      cout << "\nEl arbol es balanceado";
    } else {
      cout << "\nEl arbol no es balanceado";
    }
    // cout << "\n caca";
    fflush(stdout);



    // bst_insertar(&r, 5);
    // bst_insertar(&r, 2);
    // bst_insertar(&r, 4);
    // bst_insertar(&r, 3);
    // bst_insertar(&r, 1);
    // bst_insertar(&r, 0);
    // bst_insertar(&r, 7);
    // bst_insertar(&r, 6);
    // bst_insertar(&r, -1);
    // bst_insertar(&r, -2);
    // bst_insertar(&r, -3);
    // bst_insertar(&r, 9);
    // bst_insertar(&r, 8);
    // bst_insertar(&r, 10);
    // bst_insertar(&r, 11);
    // bst_insertar(&r, 15);
    // bst_insertar(&r, 20);
    // bst_insertar(&r, 220);
    //
    //
    //
    //
    // imprimir(r, 0, padres);
    // printf("\naltura = %i\n", altura(r));
    // printf("\nbfactor = %i\n", bfactor(r));
    // if (arbol_balanceado(r)) {
    //   cout << "\nEl arbol es balanceado";
    // } else {
    //   cout << "\nEl arbol no es balanceado";
    // }
    //
    // bst_eliminar(bst_buscar_puntero(&r, 2));
    // cout << "\n\n";
    // imprimir(r, 0, padres);
    // printf("\naltura = %i\n", altura(r));
    // printf("\nbfactor = %i\n", bfactor(r));
    // if (arbol_balanceado(r)) {
    //   cout << "\nEl arbol es balanceado";
    // } else {
    //   cout << "\nEl arbol no es balanceado";
    // }



    cout << "\n\n\n";
    // preorden(r, 9999);


    // cout << "\n" << arbol_balanceado(r) ? "El arbol es balanceado" : "El arbol no es balanceado\n";
    // bst_eliminar((bst_buscar_puntero(&r, 9)));
    // bst_buscar_puntero(&r, 7);

    // imprimir(r, 0, padres);
    // printf("\naltura = %i\n", altura(r));


    // nodo* p = bst_buscar(&r, 7);
    // cout << "\n" << (bst_buscar(&r, 7))->val;
    // imprimir(r, 0, padres);
    // printf("\naltura = %i\n", altura(r));
    cout << "\n";
    return EXIT_SUCCESS;
}
