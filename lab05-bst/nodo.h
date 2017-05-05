#ifndef NODO_H
#define NODO_H

int max(int a, int b){
    return a>b? a : b;
}

typedef struct nodo{
    int val;
    struct nodo *izq;
    struct nodo *der;
}nodo;




nodo* crear_nodo(int val){
    nodo *n = (nodo*)malloc(sizeof(nodo));
    n->val = val;
    n->izq = NULL;
    n->der = NULL;
    return n;
}

int eshoja(nodo *r){
    if(r->izq == NULL && r->der == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void imprimir(nodo *r, int depth, int *padres){
    if(r != NULL){
        printf("(%i)", r->val);
        char buf[512] = "  ";
        for(int i=0; i<depth; ++i){
            if(padres[i] == 1){
                strcat(buf, " \t");
            }
            else{
                strcat(buf, "|\t");
            }
        }
        if(eshoja(r)){
            return;
        }
        //printf("\n%s|----", buf);
        printf("--", buf);
        padres[depth] = 0;
        imprimir(r->izq, depth+1, padres);

        printf("\n%s|-----", buf);
        padres[depth] = 1;
        imprimir(r->der, depth+1, padres);
    }
}

// (1)
void bst_insertar(nodo **r, int val){
}

// (2)
nodo* bst_buscar(nodo **r, int val){
    return NULL;
}

// (3)
void bst_eliminar(nodo **r){

}

// (5)
int altura(nodo *r){
    return 0;
}

// (6)
int bfactor(nodo *r){
    return 1;
}

// (7)
int arbol_balanceado(nodo *r){
    return 1;
}

// (8)
int rot_der(nodo **r){
    return 1;
}

// (8)
int rot_izq(nodo **r){
    return 1;
}
#endif
