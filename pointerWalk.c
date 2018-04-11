#include "stdio.h"

int main(void) {
  int a[10], i;
  int *p = a;

  for (; p < a + 10; p++) {
    scanf("%d", p);
  }

  for (p--; p >= a; p--) {
    printf("%d ", *p);
  }

  return 0;
}