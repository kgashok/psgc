#include <stdio.h>

int naturalSum(int);
int main() {
  int n = 10;
  int sum = naturalSum(n);
  printf("sum of %d natural numbers is %d\n", n, sum);
  return 0;
}

int naturalSum(int n) {
  if (n == 1)  // TERMINAL CONDITION
    return 1;
  return n + naturalSum(n - 1);
}
