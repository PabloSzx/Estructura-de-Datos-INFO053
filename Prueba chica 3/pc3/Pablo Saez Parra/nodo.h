#ifndef NODO_H
#define NODO_H

#include <iostream>


typedef struct nodo{
    int val;
    struct nodo *izq;
    struct nodo *der;
}nodo;

 //PABLO SAEZ PARRA
 //19.233.043-2

nodo* crear_nodo(int val);
int eshoja(nodo *r);
void imprimir(nodo *r, int depth, int *padres);
void bst_insertar(nodo **r, int val);
nodo* bst_buscar(nodo **r, int val);
nodo** bst_buscar_puntero(nodo **r, int val);
void bst_eliminar(nodo **r);
int altura(nodo *r);
int bfactor(nodo *r);
void balanceo(nodo **p, bool *siga) ;
bool arbol_balanceado(nodo **p) ;
void rot_der(nodo **p);
void rot_izq(nodo **p);


using namespace std;

int absoluto(int a) {
  return a < 0 ? -a : a;
}


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

  if ((*r) == NULL) {
    nodo* n = crear_nodo(val);
    (*r) = n;
  } else if (val > (*r)->val) {
      bst_insertar(&(*r)->der, val);
  } else if (val < (*r)->val) {
      bst_insertar(&(*r)->izq, val);
    }

}

// (2)
nodo* bst_buscar(nodo **r, int val){
  if ((*r) == NULL) {
    cout << "\nNodo no encontrado";
    return NULL;
  } else if ((*r)->val < val) {
    return bst_buscar(&(*r)->der, val);
  } else if ((*r)->val > val) {
    return bst_buscar(&(*r)->izq, val);
  } else {
    return (*r);
  }
}

// (2) adaptado para retornar el puntero exacto del nodo, no un nodo temporal con el valor
nodo** bst_buscar_puntero(nodo **r, int val){
  if ((*r) == NULL) {
    return r;
  } else if ((*r)->val < val) {
    nodo** p = bst_buscar_puntero(&(*r)->der, val);
    return p;
  } else if ((*r)->val > val) {
    nodo** p = bst_buscar_puntero(&(*r)->izq, val);
    return p;
  }
  else {
    return (r);
  }
}

// (3)  elimina el puntero r donde esté el arbol, puede ser la raiz del arbol o un resultado de bst_buscar_puntero a partir del arbol
void bst_eliminar(nodo **r){
  if (eshoja(*r)) {
    (*r) = NULL;
  } else {
    if ((*r)->der != NULL) {
      nodo **menor = &(*r)->der->izq;
      while ((*menor) != NULL) {
        menor = &(*menor)->izq;
      }
      (*menor) = (*r)->izq;
      (*r) = (*r)->der;
    } else {
      (*r) = (*r)->izq;
    }
  }
}


// (5)
int altura(nodo *r){
  if (r == NULL) {
    return -1;
  } else {
    return (1 + max(altura(r->izq), altura(r->der)));
  }
}

// (6)
int bfactor(nodo *r){
  if (r->izq != NULL && r->der != NULL) {
    int izq = altura(r->izq);
    int der = altura(r->der);
    return (der - izq);
  }
  return NULL;
}

// (7)

void esDesbalancedo(nodo **p, bool *siga) {

  if (!(*siga)) {
    int factor = bfactor(*p);
    if (absoluto(factor) <= 1) {
      if ((*p)->izq != NULL) {
        esDesbalancedo(&(*p)->izq, siga);
      }
      if ((*p)->der != NULL) {
        esDesbalancedo(&(*p)->der, siga);
      }
    } else {
      *siga = true;
    }
  }

}

bool arbol_desbalanceado(nodo **p) {
  bool siga = false;

  esDesbalancedo(p, &siga);

  return siga;
}

void balance(nodo **p) {
  // cout << "entro al balance" << endl;
  if ((*p) != NULL) {
  int factor = bfactor(*p);
  // cout << "pase el factor" << endl;
  int derFactor = 0;
  int izqFactor = 0;

  if ((*p)->der != NULL) {
    // cout << "p->der es distinto de null" << endl;
    derFactor = bfactor((*p)->der);
  } else {
    derFactor = NULL;
    // cout << "entro al else de p->der" << endl;
  }
  if ((*p)->izq != NULL) {
    // cout << "p->izq es distinto de null" << endl;
    izqFactor = bfactor((*p)->izq);
  } else {
    // cout << "entro al else de p->izq" << endl;
    izqFactor = NULL;
  }
  if (factor > 1 && derFactor >= 0) {
    // cout << "factor es 2 y derfactor >= 0" << endl;
    rot_izq(p);
    balance(p);
  }
  else if (factor < -1 && izqFactor <= 0) {
    // cout << "factor es -2 y izqfactor >= 0" << endl;
    rot_der(p);
    balance(p);
  } else {
    // cout << "else de todos" << endl;

    if ((*p) != NULL) {
      // cout << "p es distinto de null" << endl;
      if ((*p)->izq != NULL) {
        // cout << "p->izq es distinto de null" << endl;
        balance(&(*p)->izq);
      }
      if ((*p)->der != NULL) {
        // cout << "p->der es distinto de null" << endl;
        balance(&(*p)->der);
      }
    }

  }
  // cout << "salio del balance" << endl;
  }
}

void balancear(nodo **r) {
  // cout << "entró al balancear" << endl;
  nodo **p = r;
  balance(&(*p)->der);
  balance(&(*p)->izq);
  if (arbol_desbalanceado(r)) {
    // balancear(&(*r)->der);
    // balancear(&(*r)->izq);
    balancear(r);
  }
}
// (8)
void rot_der(nodo **p){
  nodo *q = (*p)->izq;
  nodo *b = q->der;

  if (q != NULL) {
    (*p)->izq =b;
    q->der = (*p);
    (*p) = q;
  } else {
    cout << "No se puede hacer la rotacion" << endl;
  }
}

// (8)
void rot_izq(nodo **p){
  nodo *q = (*p)->der;
  nodo *b = q->izq;

  if (q != NULL) {
    (*p)->der = b;
    q->izq = (*p);
    (*p) = q;
  } else {
    cout << "No se puede hacer la rotacion" << endl;
  }
}


int alturaMinima(nodo *r){
  if (r == NULL) {
    return 1;
  } else {
    return (1 + min(altura(r->izq), altura(r->der)));
  }
}

int dpath(nodo *r) {
  return altura(r) - alturaMinima(r);
}

#endif
