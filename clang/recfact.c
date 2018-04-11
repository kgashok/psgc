#include <stdio.h>

int factorial(int n) {
  if (n == 0 || n == 1)  // TERMINAL CONDITION
    return 1;
  return n * factorial(n - 1);
}

int main(int argc, char** argv) {
  int number = atoi(argv[1]);
  int fval = factorial(number);
  printf("The factorial of %d is %d\n", number, fval);

  return 0;
}