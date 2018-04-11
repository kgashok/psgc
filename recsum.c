#include <stdio.h> 

int rec_sum (int* s, int size) { 
    if (size == 0) 
        return 0; 

    int sumval = *s; // get element
    return sumval + rec_sum(++s, --size); 

}

int main () {

    int s[7] = {1, 2, 3, 4, 5, 6, 7};
    int sum  = rec_sum (s, 7); 
    
    printf ("The sum is %d\n", sum); 
    
}