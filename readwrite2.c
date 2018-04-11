#include <stdio.h>

int main(int argc, char** argv) {

   /* STEP 1 */ 
   //open the necessary file pointers
   FILE* fileIn  = fopen(argv[1], "r");
   FILE* fileOut = fopen(argv[2], "w"); 
   
   /* STEP 2 */
   // read from 'fileIn' and write to 'fileOut'
   char c;
   while((c = fgetc(fileIn)) != EOF) {
      fputc (c, fileOut); 
   }
   
   /* STEP 3 */
   // clean up by closing all the file pointers
   fflush(fileOut);
   fclose(fileOut);
   fclose(fileIn);
   return 0;
}