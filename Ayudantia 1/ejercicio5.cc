#include <stdlib.h>
#include <stdio.h>

void binary(int number) {
 int remainder;

 if(number <= 1) {
  printf("%i", number);
  return;
 }

 remainder = number%2;
 binary(number >> 1);
 printf("%i", remainder);
}

int main(int argc, char *argv[]) {

  int number = atoi(argv[1]);

  if (number < 0){
   return 0;
  }

  else {
   printf("Binario: ");
   binary(number);
  }
  printf("\n");
  return 0;
}
