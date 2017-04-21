#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, const char *argv[]) {

  for (int i = 1; i < (argc); i++) {
    printf("%s ", argv[argc - i]);
  }

  printf("\n");
  return 0;
}
