#include <stdio.h>

int main() {
  int a = 568, b = 22, c = 994;

  int biggest = a > b ? (a > c ? a : c) : (b > c ? b : c);

  printf("biggest %d\n", biggest);

  return 0;
}
