#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

typedef struct Node{
    void* data;
    struct Node * next;
    struct Node * prev;
} Node;

typedef struct LinkedList{
    Node * head;
    Node * tail;
    int size;
} LinkedList;

LinkedList * ll_create(){
    LinkedList * newList = (LinkedList *)(malloc(sizeof(LinkedList)));

    if(newList != NULL){
        newList->head = NULL;
        newList->tail = NULL;
        newList->size = 0;
    }
    
    return newList;
}

int ll_destroy(LinkedList *self){
    Node * current = (self)->head;
    while (current != NULL){
        Node * next = current->next;
        free(current);
        current = next;
    }
    free(self);
    self = NULL;
    return 1;
}

Node * node_create(void* item){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

//adds item to back the list
int ll_add(LinkedList *self, void* item){
    Node * newNode = node_create(item);
    if(self->size == 0){
        self->head = newNode;
        self->tail = newNode;
    } else{
        self->tail->next = newNode;
        newNode->prev = self->tail;
        self->tail = self->tail->next;
    }
    self->size++;
    return 1;
}

//adds item to front of the list
int ll_add_h(LinkedList *self, void* item){
    Node * newNode = node_create(item);

    if(self->size == 0){
        self->head = newNode;
        self->tail = newNode;

    } else{
        self->head->prev = newNode;
        newNode->next = self->head;
        self->head = self->head->prev;
    }
    self->size++;
    return 1;
}

//removes item from tail
int ll_del(LinkedList *self, void** removedData){
    if(self->size == 0){
        return 0;
    }

    Node * newTail = self->tail->prev;
    *removedData = self->tail->data;

    free(self->tail);

    if(self->size > 1){
        newTail->next = NULL;
        self->tail = newTail;
    }
    else{
        self->head = NULL;
    }
    self->size--;
    return 1;
}

//removes item from head
int ll_del_h(LinkedList *self, void** removedData){
    if(self->size == 0){
        return 0;
    }
    
    Node * newHead = self->head->next;

    *removedData = self->head->data;
    
    free(self->head);

    if(newHead != NULL){
        newHead->prev = NULL;
    } else{
        self->tail = NULL;
    }
    self->head = newHead;
    self->size--;

    return 1;
}

void ll_print(LinkedList * self, char* (*f)(void*)){
    Node* current = self->head;

    while(current != NULL){
        char *text = f(current->data);
        printf("%s->", text);
        current = current->next;
        free(text);
    }
    printf("\n");
}

