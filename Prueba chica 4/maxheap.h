#ifndef MAXHEAP_H
#define MAXHEAP_H

#define MAX 1000

typedef struct maxheap{
  int data[MAX]; //arbol con espacio MAX
  int n; // numero de elementos
}maxheap;

void maxheap_heapify(maxheap *h, int i);

maxheap* maxheap_crear(){
  maxheap *h = (maxheap*)malloc(sizeof(maxheap));
  h->n = 0;
  h->data[0] = INT_MAX; // dato auxiliar
  return h;
}

void maxheap_insertar(maxheap *h, int x){
  if(h->n >= MAX){
    return;
  }
  h->n++;
  h->data[h->n] = x;

  int pos = h->n;
  while(h->data[pos/2] < x) {
    h->data[pos] = h->data[pos/2];
    pos /= 2;
  }
  h->data[pos] = x;
}

void maxheap_imprimir(maxheap *h){
  printf("maxheap n=%i:\n", h->n);
  for(int i=1; i<=h->n; ++i){
    printf("%i\n", h->data[i]);
  }
}

int maxheap_menor(maxheap *h, int i){
  int m = i;
  if(2*i <= h->n && h->data[m] < h->data[2*i]){
    m = 2*i;
  }
  if(2*i+1 <= h->n && h->data[m] < h->data[2*i+1]){
    m = 2*i+1;
  }
  return m;
}


void maxheap_heapify(maxheap *h, int i){
  if(2*i >= h->n) {
    return;
  }
  int m = maxheap_menor(h, i); // buscar menor
  // si el menor es distinto al padre
  if(m != i){
    int aux = h->data[i];
    h->data[i] = h->data[m];
    h->data[m] = aux;
    maxheap_heapify(h, m);
  }
}

// eliminar el minimo
int maxheap_eliminar(maxheap *h){
  if(h->n == 0){
    return -1;
  }
  int r = h->data[1]; // a) sacamos (copiamos) la raiz para retornarla al final
  h->data[1] = h->data[h->n--];  // b) ubicamos el ultimo valor del arbol en la raiz y disminuimos n al final de la instruccion
  maxheap_heapify(h, 1); // proceso heapify
  return r;
}

void maxheap_build(maxheap *h, int *nums, int n){
  for(int i=0; i<n; ++i){
    h->data[i] = nums[i];
  }
  h->n = n;
  for(int i=n/2; i>0; --i){
    maxheap_heapify(h,i);
  }
}
#endif
