#include <stdio.h>

int Fibonacci(int n) {
  if (n == 0)  // TERMINAL CONDITION_1
    return 0;
  else if (n == 1)  // TERMINAL CONDITION_2
    return 1;
  else
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

main() {
  int n, i = 0, c;
  scanf("%d", &n);
  printf("Fibonacci series\n");
  for (c = 1; c <= n; c++) {
    printf("%d ", Fibonacci(i));
    i++;
  }
  return 0;
}