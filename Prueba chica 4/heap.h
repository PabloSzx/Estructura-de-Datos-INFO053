#ifndef HEAP_H
#define HEAP_H

#define MAX 1000

typedef struct heap{
  int data[MAX]; //arbol con espacio MAX
  int n; // numero de elementos
}heap;

void heap_heapify(heap *h, int i);

heap* heap_crear(){
  heap *h = (heap*)malloc(sizeof(heap));
  h->n = 0;
  h->data[0] = -INT_MAX; // dato auxiliar
  return h;
}

void heap_insertar(heap *h, int x){
  if(h->n >= MAX){
    return;
  }
  h->n++;
  h->data[h->n] = x;

  int pos = h->n;
  while(h->data[pos/2] > x) {
    h->data[pos] = h->data[pos/2];
    pos /= 2;
  }
  h->data[pos] = x;
}

void heap_imprimir(heap *h){
  printf("heap n=%i:\n", h->n);
  for(int i=1; i<=h->n; ++i){
    printf("%i\n", h->data[i]);
  }
}

int heap_menor(heap *h, int i){
  int m = i;
  if(2*i <= h->n && h->data[m] > h->data[2*i]){
    m = 2*i;
  }
  if(2*i+1 <= h->n && h->data[m] > h->data[2*i+1]){
    m = 2*i+1;
  }
  return m;
}


void heap_heapify(heap *h, int i){
  if(2*i >= h->n) {
    return;
  }
  int m = heap_menor(h, i); // buscar menor
  // si el menor es distinto al padre
  if(m != i){
    int aux = h->data[i];
    h->data[i] = h->data[m];
    h->data[m] = aux;
    heap_heapify(h, m);
  }
}

// eliminar el minimo
int heap_eliminar(heap *h){
  if(h->n == 0){
    return -1;
  }
  int r = h->data[1]; // a) sacamos (copiamos) la raiz para retornarla al final
  h->data[1] = h->data[h->n--];  // b) ubicamos el ultimo valor del arbol en la raiz y disminuimos n al final de la instruccion
  heap_heapify(h, 1); // proceso heapify
  return r;
}

void heap_build(heap *h, int *nums, int n){
  for(int i=0; i<n; ++i){
    h->data[i] = nums[i];
  }
  h->n = n;
  for(int i=n/2; i>0; --i){
    heap_heapify(h,i);
  }
}



#endif
