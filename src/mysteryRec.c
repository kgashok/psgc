#include <stdio.h>

int main() {
  int x, num = 5;
  x = call(num);
  printf("%d\n", x);

  return 0;
}

int call(int num) {
  static int x = 1, y;
  if (num > 0) {
    x = x + num - 1;
    y = call(num - 1) + 2;
  }
  return x;
}
