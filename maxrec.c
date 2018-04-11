#include <stdio.h>

int maxrec(int mval, int array[], int size) {
  if (size == 0)  // TERMINAL CONDITION
    return mval;

  if (mval < array[0]) mval = array[0];
  return maxrec(mval, &array[1], size - 1);
}

int main() {
  int s[] = {1, 2, 300, 4, 5, 64, 1020, 8};

  int max = maxrec(1, &s[1], 8);
  printf("The maximum is %d\n", max);

  return 0;
}