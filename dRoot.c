#include "stdio.h"

int main(void) {
    
    int n;
    
    scanf ("%d", &n); 
    
    while (n > 9 ) { 
    	int sum = 0; 
    	while (n > 0) { 
    		int r = n%10; 
    		sum   = sum + r; 
    		n     = n/10;
    	}
    	n = sum; 
    	printf ("%d ", n);
    }
    
    printf ("The digital root is %d\n", n);
    
    return 0;
}