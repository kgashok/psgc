#include <stdio.h>

int power(int x, int y) {
  if (y == 0)  // TERMINAL CONDITION
    return 1;

  return x * power(x, y - 1);
}

int main() {
  int x = 5;
  int y = 3;
  int result = power(x, y);
  printf("%d to the power of %d is = %d\n", x, y, result);
  return 0;
}