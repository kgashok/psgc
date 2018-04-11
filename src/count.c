#include <stdio.h>
#include<stdlib.h>

void main(int argc, char** argv) {
  FILE* fp;
  char ch;
  int character = 0, space = 0, tab = 0, line = 0;
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("File Not Found\n");
    exit(1);
  } else {
    while (1) {
      ch = fgetc(fp);
      if (ch == EOF) break;
      character++;
      if (ch == ' ')
        space++;
      else if (ch == '\t')
        tab++;
      else if (ch == '\n')
        line++;
    }
  }
  printf("\nNumber of Characters = %d\n", character);
  printf("\nNumber of Tabs       = %d\n", tab);
  printf("\nNumber of New Lines  = %d\n", line);
  printf("\nNumber of Spaces     = %d\n", space);

  // Using fseek and ftell to find size of file
  fseek(fp, 0, SEEK_END);
  int len = ftell(fp);
  fclose(fp);
  printf("\nSize of file         = %d\n", len);
}
