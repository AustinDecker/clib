#ifndef HEAP_H 
#define HEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node {
    void* data;
    int order;   
};
typedef struct Node Node; 

struct Heap {
    Node** heapStorage;
    int max_size;
    int nextIndex;
    int (*order_func)(void* item);
    void (*del_func)(void* item);

    
};
typedef struct Heap Heap;

/*
creates a locally used node object that wraps the void pointer data. Also contains an integer value representing the order of the node.
*/
Node* node_create(void* data, int order);
/*
initializes an empty heap array representation with functions to manipulate the internal array.
must include custom del and order functions in order to properly handle whatever data the heap will hold.
*/
Heap* heap_create(int heap_size, int (*order_function)(void* item), void (*del_function)(void* item));
/*
destroys the heap and frees any allocated memory
*/
void heap_destroy(Heap* self);
/*
initializes a heap given an array of items. Items are heapified.
*/
Heap* heap_build(void* array, int array_size, int heap_size, int (*order_function)(void* item), void (*del_function)(void* item));
/*
add an item to the heap if space is available.
*/
void heap_add(Heap* self, void* data);
/*
remove the root item from the heap if there is an item to remove.
*/
void* heap_remove(Heap* self);
/*
returns an array of void pointers in ascending order based on the order.
*/
void* heap_sort(Heap* self);
/*
returns the maximum size of the heap.
*/
int heap_size(Heap* self);
#endif
