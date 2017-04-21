#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct{
  float x;
  float y;
} coord;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "Numero de argumentos incorrecto, favor de ingresar los ";
    cout << "argumentos de la siguiente manera: \"<numero> <caracter>\"\n";
    return 0;
  }
  int n = atoi(argv[1]);
  char *c = argv[2];
  int largo = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      largo++;
    }
  }

  coord *coords = (coord *)malloc(sizeof(coord)*largo);

  int l = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << c;
      coords[l].x = i;
      coords[l].y = j;
      l++;
    }
    cout << "\n";
  }

  cout << "\n" << "Coordenadas elementos:\n";
  for (int i = 0; i < largo; i++) {
    cout << "(" << coords[i].x << ") (";
    cout << coords[i].y << ")\n";

  }
  return 0;
}
