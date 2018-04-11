#include <stdio.h> 

struct employeeRec {
    char name[256]; 
    int age;
    int employeeID; 
    char phone[10]; 
    char address[256]; 
} employees[100]; 

typedef struct employeeRec Employee; 

int main () { 
    
    int i;
    for (i = 0; i < 100; i++) {
        scanf("%s %d %d %s %s ", employees[i].name, 
                                 &employees[i].age,
                                 &employees[i].employeeID, 
                                 employees[i].phone, 
                                 employees[i].address);
    }
    
    //searching based on employeeID
    int id;
    printf ("Enter employee ID"); 
    scanf ("%d", &id);
    
    for (i=0; i < 100; i++) {
        if (employees[i].employeeID == id) {
            printf ("%s %d %s", employees[i].name, 
                                   employees[i].age, 
                                   employees[i].phone);
        break;
    }
    
    // for oldest employees, do a bubble sort 
    // and then pick the top 10 of the array and 
    // print it 
    
    
    return 0;
    
}