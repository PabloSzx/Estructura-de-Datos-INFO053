#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
  char nombre[60];
  char carrera[60];
  int edad;
} Alumnos;

int main(int argc, char const *argv[]) {

  Alumnos alumno[100];
  char linea[256];
  FILE *archivo;
  int ndatos = 0;
  char *elemento;

  archivo = fopen("datos.csv", "r+");

  while (fgets(linea, 256, archivo)) {
    elemento = strtok(linea, ",");
    strcpy(alumno[ndatos].nombre, elemento);
    elemento = strtok(NULL, ",");
    strcpy(alumno[ndatos].carrera, elemento);
    elemento = strtok(NULL, "\n");
    alumno[ndatos].edad = atoi(elemento);

    ndatos++;
  }

  fclose(archivo);

  for (int k = 0; k < ndatos; k++) {
    printf("Mi nombre es %s! y estudio %s \n", alumno[k].nombre, alumno[k].carrera);
  }
  return 0;
}
