#include <stdio.h>
#include <stdlib.h>

// Existing Blocks of Code (aka Functions - the 5th construct)
int getNumber ();
void printNumber (int number);
int add (int a, int b);
int subtract (int a, int b);

int main () { 
    
    int dividend = getNumber();
    int divisor  = getNumber(); 
    
    int quotient = 0; 
    int remain   = dividend; 
    
    while (remain >= divisor )   {
        quotient = quotient + 1; 
        remain   = remain - divisor;
        printf ("quotient: %d ", quotient);
        printf ("remain: %d\n", remain);
    }
    printNumber (quotient);
    
    if (remain > 0) {
        printNumber (remain);
    }
    puts(""); 
    return 0;
}





















//------------------- DO NOT EDIT BELOW ------------
//
//
int add (int a, int b)
{
    return a + b;
}

int subtract (int a, int b)
{
    return a - b;
}


int getNumber() {
    int n;
    scanf ("%d", &n);
    return n;
}

void printNumber (int n)
{
    printf ("%d ", n);
    
}
