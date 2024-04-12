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
    
};
typedef struct Heap Heap;

Node* node_create(void* data, int order);
Heap* heap_create(int heap_size);
Heap* heap_create(void* array, int array_size, int heap_size);
void heap_add(Heap* self, void* data);
void* heap_remove(Heap* self);
void* heap_sort(Heap* self);

#endif
