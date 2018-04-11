#include <stdio.h>

int cmpfunc (const void * a, const void * b) {
   //printf ("%d %d \n", *(int*)a, *(int*)b); 
   return ( *(int*)a - *(int*)b );
}

/*
 * Usage: ./readwrite3 in.txt out.txt
 *
 */
int main(int argc, char** argv) {

   /* STEP 1 */ 
   //open the necessary file pointers
   //FILE* fileIn  = fopen(argv[1], "r");
   //FILE* fileOut = fopen(argv[2], "w"); 
   FILE* fileIn  = fopen("input.txt", "r");
   FILE* fileOut = fopen("output.txt", "w"); 
   
   /* STEP 2 */
   // read from 'fileIn' and write to 'fileOut'
   int x[100]; 
   int i = 0;
   while((fscanf(fileIn, "%d\n", &x[i])) != EOF) {
      //fprintf (fileOut, "%d %d\n", x[i], x[i]);
      i++;
   }

   qsort (x, i, sizeof(int), cmpfunc); 
   
   int j;
   for (j = 0; j < i; j++)
      fprintf(fileOut, "%d\n", x[j]); 
      
      
   /* STEP 3 */
   // clean up by closing all the file pointers
   fflush(fileOut);
   fclose(fileOut);
   fclose(fileIn);
   return 0;
}