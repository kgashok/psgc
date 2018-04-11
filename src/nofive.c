#include <stdio.h>
#include <string.h>

int main() {
  char buf[30] = "230943";
  char buf1[30] = "3233445";

  if (strchr(buf, '5') == NULL) printf("no five in buf\n");

  if (strchr(buf1, '5') != NULL) printf("five present in buf1\n");

  return 0;
}