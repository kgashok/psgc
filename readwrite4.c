#include <stdio.h>


struct student_info {
   char name[30]; 
   int marks;
} students[10];
typedef struct student_info Student; 

int cmpfunc (const void * a, const void * b) {
   Student *s1 = (Student *)a; 
   Student *s2 = (Student *)b; 

   //printf ("%d %d \n", s1->marks, s2->marks); 
   return s2->marks - s1->marks;
}


int main(int argc, char** argv) {

   /* STEP 1 */ 
   //open the necessary file pointers
   FILE* fileIn  = fopen(argv[1], "r");
   FILE* fileOut = fopen(argv[2], "w"); 
   
   /* STEP 2 */
   // read integers from 'fileIn'
   int count = 0;
   while((fscanf(fileIn, "%s %d\n", 
         students[count].name, &(students[count].marks) )) != EOF) {
      //fprintf (fileOut, "%d %d\n", x[i], x[i]);
      count++;
   }
   
   /* STEP 3 */
   // sort them into ascending order
   qsort (students, count, sizeof(struct student_info), cmpfunc); 

   /* STEP 4 */
   // write the sorted array into a new file
   int j;
   for (j = 0; j < count; j++)
      fprintf(fileOut, "%s\t%d\n", students[j].name, students[j].marks); 
      
      
   /* STEP 5 */
   // clean up by closing all the file pointers
   fflush(fileOut);
   fclose(fileOut);
   fclose(fileIn);
   return 0;
}