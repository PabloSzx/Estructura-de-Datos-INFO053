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

int altura(nodo *r){
    if(r == NULL){
        return -1;
    }
    return max(altura(r->izq), altura(r->der)) + 1;
}

void imprimir(nodo *r, int depth, int *padres){
    if(r != NULL){
        printf("(%i)", r->val);
        char buf[1024] = "  ";
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
        printf("---", buf);
        padres[depth] = 0;
        imprimir(r->izq, depth+1, padres);

        printf("\n%s|-----", buf);
        padres[depth] = 1;
        imprimir(r->der, depth+1, padres);
    }
}

void bst_insertar(nodo **r, int val){
    if((*r) == NULL){
        (*r) = crear_nodo(val);
        return;
    }
    if(val > (*r)->val){
        if((*r)->der == NULL){
            (*r)->der = crear_nodo(val);
        }
        else{
            bst_insertar(&((*r)->der), val);
        }
    }
    else{
        if((*r)->izq == NULL){
            (*r)->izq = crear_nodo(val);
        }
        else{
            bst_insertar(&((*r)->izq), val);
        }
    }
}

int factor_balance(nodo *r){
    if(r == NULL){
        return 0;
    }
    else{
        return altura(r->der) - altura(r->izq);
    }
}

int rot_der(nodo **r){
    printf("rot_der...");
    nodo *pivot = (*r)->izq;
    if(pivot == NULL){
        fprintf(stderr, "cannot rotate, pivot NULL\n");
        return 0;
    }
    (*r)->izq = pivot->der;
    pivot->der = (*r);
    (*r) = pivot;
    printf("ok\n");
    return 1;
}

int rot_izq(nodo **r){
    nodo *pivot = (*r)->der;
    if(pivot == NULL){
        fprintf(stderr, "cannot rotate, pivot NULL\n");
        return 0;
    }
    (*r)->der = pivot->izq;
    pivot->izq = (*r);
    (*r) = pivot;
    return 1;
}


// ejercicio 1
int desbalanceado(nodo *r){
    return 0;
}

// ejercicio 2
void balancear(nodo **r){

}

// ejercicio 3
int dpath(nodo *r){
    return 0;
}


#endif
