#include <stdio.h>

void halfOf(int val) {
  if (val == 0) return;

  printf("%d ", val);
  return halfOf(val / 2);
}

int main() {
  int start = 21;

  halfOf(21);

  return 0;
}