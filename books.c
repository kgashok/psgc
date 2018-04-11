#include <stdio.h> 

struct book_info {
    char book_title[100]; 
    char book_author[100];
    char book_publisher[100];
    float cost; 
    int accession_number;
} books[100]; 

typedef struct book_info Book;

void display_author_books(char*), 
    display_publisher_books(char*), 
    display_books();


int main () { 

    int anumber = 1000; 
    int i = 0;
    char response;
    while(1) {
        printf ("Add book details? "); 
        scanf ("%[yn]", &response);
        if (response == 'n')
            break;
            
        // get book details
        books[i].accession_number = anumber;
        scanf ("%s %s %s %f", books[i].book_title,
                            books[i].book_author,
                            books[i].book_publisher, 
                            &books[i].cost);
        i++, anumber++;
    }
    
    int option; 
    char buf[100];
    printf ("Display options - 1, 2 or 3? ");
    scanf ("%d", &option); 
    switch (option) {
        case 1: 
            printf ("Enter author name\n");
            scanf ("%s", buf);
            display_author_books(buf);
            break;
        case 2: 
            printf ("Enter author name\n");
            scanf ("%s", buf);
            display_publisher_books(buf);
            break;
        case 3: 
            puts ("Displaying all books");
            display_books();
    }
    
    
    return 0;
}

void display_author_books ( char* name) { 
    int i; 
    for (i = 0; i < 100; i++) {
        if (books[i].accession_number >= 1000) {
            if (strcmp(books[i].book_author, name) == 0) 
                printf ("%s %s %s %f\n", books[i].book_title, 
                                    books[i].book_author,
                                    books[i].book_publisher, 
                                    books[i].cost);
        }
        else // no more books with valid accession number
            break;
    }
    return;
}

void display_publisher_books ( char* name) { 
    // string compare with books[i].book_publisher
    return;
}

void display_books () { 
    // sort based on the accesssion number
    // and then print
    int i, j; 
    for (i = 0; i < 100; i++) {
        for (j = 0; j < (100-1)-i; j++ ) {
            if (books[j].accession_number > books[j+1].accession_number) {
                Book temp = books[j+1]; 
                books[j+1] = books[j];
                books[j] = temp;
            }
        }
    }
    for (i = 0; i < 100; i++) {
        if (books[i].accession_number >= 1000)
            printf ("%s %s %s %f\n", books[i].book_title,
                                    books[i].book_author, 
                                    books[i].book_publisher, 
                                    books[i].cost);
    }
    return;
}