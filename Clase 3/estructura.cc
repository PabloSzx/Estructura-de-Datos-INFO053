#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define RANGO 1000


// estructura punto: p = (x, y)
typedef struct{
  float x;
  float y;
} punto;

int main(int argc, char const *argv[]) {
  punto p;
  p.x = 1.0f;
  p.y = 2.0f;
  printf("punto p = (%f, %f)\n", p.x, p.y);
  return 0;
}
