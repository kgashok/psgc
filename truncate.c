// http://stackoverflow.com/questions/13494417/ftruncate-on-file-opened-with-fopen

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define string_len 1000

int main() {
  /*char *mega_string;
  int  file_descriptor;
  int  ret;
  char fn[]="write.file";
  struct stat st;

  if ((mega_string = (char*) malloc(string_len)) == NULL)
    perror("malloc() error");
  else if ((file_descriptor = creat(fn, S_IWUSR)) < 0)
    perror("creat() error");
  else {
    memset(mega_string, 'A', string_len);
    if ((ret = write(file_descriptor, mega_string, string_len)) == -1)
      perror("write() error");
    else {
      printf("write() wrote %d bytes\n", ret);
      fstat(file_descriptor, &st);
      printf("the file has %ld bytes\n", (long) st.st_size);
      if (ftruncate(file_descriptor, 1100) != 0)
        perror("ftruncate() error");
      else {
        fstat(file_descriptor, &st);
        printf("the file has %ld bytes\n", (long) st.st_size);
      }
    }
    close(file_descriptor);
    //unlink(fn);
  }
  free(mega_string);
  */

  FILE *fp = fopen("write.file", "r");
  char buf;
  int count = 0;
  while ((buf = fgetc(fp)) != '\0') {
    count++;
  }
  // printf ("%c %d\n", buf, count);
  printf("Number of bytes read %d\n", count);
  buf = fgetc(fp);
  printf("Next char %c -- expecting A\n", buf);
  buf = fgetc(fp);
  printf("Next char %c -- expecting EOF\n", buf);

  buf = fgetc(fp);
  printf("Next char %c -- expecting B\n", buf);

  /*if (fputc('B', fp) == '\0') printf ("ERROR writing \n");
  if (fputc('B', fp) == '\0') printf ("ERROR writing \n");
  if (fputc('B', fp) == '\0') printf ("ERROR writing \n");
  if (fputc('B', fp) == '\0') printf ("ERROR writing \n");
  if (fputc('B', fp) == '\0') printf ("ERROR writing \n");

  while ((buf = fgetc(fp)) != '\0') {
    count++;
    //printf ("%c %d\n", buf, count);
  }
  printf ("FP value %p\n", fp);
  printf ("Number of bytes read %d\n", count);
  fclose(fp);*/
  return 0;
}

/*#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main () {

    FILE *fp = fopen ("test.txt", "rw");
    printf ("File %p\n", fp);
    printf ("truncating...\n");
    fflush(fp);
    int val = ftruncate(fileno(fp), 30);
    fclose(fp);

    printf ("return val %d", val);




    return 0;
}
*/