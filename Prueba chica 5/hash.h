#ifndef HASH_H
#define HASH_H

int h1(int x){
    return x % m;
}

// universal hashing
int h2(int x){
    return ((a*x + b) % p) % m;
}

int h3(char* x){
    return ((a*atoi(x) + b) % p) % m;
}


int esprimo(int n){
    int i,root;
    if (n%2 == 0 || n%3 == 0)
        return 0;

    root = (int)sqrt(n);
    for (i=5; i<=root; i+=6){
        if (n%i == 0)
           return 0;
    }
    for (i=7; i<=root; i+=6){
        if (n%i == 0)
           return 0;
    }
    return 1;
}

int mprimo(int m){
    int i = m;
    while( !esprimo(i) ){
        ++i;
    }
    return i;
}

void gen_hashfunc(int m, int *a, int *b, int *p){
    // get prime greater than M
    *p = mprimo(m);
    *a = (rand() % *p) + 1;
    *b = rand() % *p;
}

int insert(nodo **ht, char* x, int (*h)(int)){
    int pos = (*h)(atoi(x));
    //printf("i = %i asasa1\n", pos); fflush(stdout);
    nodo *aux = crear_nodo(x);
    //printf("i = %i asasa2\n", pos); fflush(stdout);
    aux->next = ht[pos];
    ht[pos] = aux;
}

// int exists(nodo **ht, char* x, int (*h)(int)){
//     int i = (*h)(atoi(x));
//     nodo *aux = ht[i];
//     while(aux != NULL){
//         if(aux->text == x){
//             return 1;
//         }
//         aux = aux->next;
//     }
//     return 0;
// }

void print_ht(nodo **ht, int m){
   for(int i=0; i<m; ++i){
        nodo *aux = ht[i];
        printf("ht[%i] = ", i);
        while(aux != NULL){
            printf("(%s) --> ", aux->text);
            aux = aux->next;
        }
        printf("NULL\n");
    }
}
#endif
