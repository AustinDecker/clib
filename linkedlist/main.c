#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct Book {
    char* title;
    double price;
} Book;

char* print_book(void* book){
    char * data = malloc(sizeof(char) * 50);
    snprintf(data, 50, "Title:\t%s\tPrice:\t%f", ((Book *)book)->title, ((Book*)book)->price);
    return data;
}

void main(){
    LinkedList* myBookList = ll_create();
    Book book1 = {"To Kill a Mocking Bird", 24.99};
    Book book2 = {"Harry Potter", 24.69};
    Book book3 = {"Overlord Vol1", 20.99};
    
    ll_add(myBookList, &book1);
    ll_add(myBookList, &book2);
    ll_add(myBookList, &book3);
    ll_print(myBookList, print_book);

    Book* removedItem = NULL;
    ll_del_h(myBookList, (void*)&removedItem);

    printf("%s\n", print_book(removedItem));

    ll_destroy(myBookList);
}