#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  /* code */
  char buffer[128];

  while (scanf("%s", buffer)) {
  printf("\nla palabra es: %s\nel largo es: %lu\n", buffer, strlen(buffer));
  // printf("%lu\n", strlen(buffer));
  if (strcmp(buffer, "hola") == 1) {
    printf("%s es mayor a hola\n", buffer);
  } else if (strcmp(buffer, "hola") == 0) {
    printf("%s es igual a hola\n", buffer);
  } else {
    printf("%s es menor a hola\n", buffer);
  }

  printf("\n");
}

  return EXIT_SUCCESS;
}
