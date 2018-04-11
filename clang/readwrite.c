#include <stdio.h>

int main(int argc, char** argv) {
  FILE* filePtr = fopen(argv[1], "r+");
  char c;
  int i = 0, j = 0;
  int loc[100];  // to remember where tabs were found
  while ((c = fgetc(filePtr)) != EOF) {
    if (c == '\t') {
      printf("%d->tab ", i);  // to display tab was found
      loc[j++] = ftell(filePtr) - 1;
    } else
      printf("%d->%c ", i, c);  // to display other characters
    i++;
  }

  // print the offsets in the file where
  // tabs were located
  int k;
  for (k = 0; k < j; k++) printf("%d ", loc[k]);
  printf("\n");

  // replace all tabs with spaces
  for (k = 0; k < j; k++) {
    fseek(filePtr, loc[k], 0);
    fputc(' ', filePtr);
  }
  fflush(filePtr);
  fclose(filePtr);
  return 0;
}