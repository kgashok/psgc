#include <stdio.h> 

int gcd (int, int); 

int main () {

    int x = 366; 
    int y = 60;
    
    int result = gcd (x, y); 
    printf ("GCD of %d and %d is %d\n", x, y, result); 
    return 0;
}

int gcd (int a, int b) { 
    if (b==0)     // TERMINAL CONDITION
        return a; 
        
    return gcd(b, a%b); 
}
