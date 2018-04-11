//http://stackoverflow.com/questions/13494417/ftruncate-on-file-opened-with-fopen

#include <stdio.h>
#include <stdlib.h>

int main() {

  FILE *fp = fopen ("write.file", "r"); 
  char buf; 
  int count = 0;
  while ((buf = fgetc(fp)) != '\0') {
    if (buf == 'B') 
        count++;
  }
  printf ("Number of B's counted %d\n", count); 
  return 0;
}

