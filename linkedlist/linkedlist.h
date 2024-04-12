#ifndef linkedlist
#define linkedlist

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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

LinkedList * ll_create();
Node * node_create(void* data);
int ll_destroy(LinkedList* self);
int ll_add(LinkedList* self, void* item);
int ll_add_h(LinkedList* self, void* item);
int ll_del(LinkedList* self, void** delItem);
int ll_del_h(LinkedList* self, void** delItem);
void ll_print(LinkedList* self, char* f(void*));

#endif

