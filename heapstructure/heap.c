#include "heap.h"

Node* node_create(void* data, int order){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->order = order;

    return newNode;
}

Heap* heap_create(int heap_size, int (*order_function)(void* item), void (*del_function)(void* item)){
    Heap* newHeap = malloc(sizeof(Heap));
    newHeap->max_size = heap_size;
    newHeap->order_func = order_function;
    newHeap->del_func = del_function;
    newHeap->nextIndex = 0;

    Node** heapStorage = malloc(heap_size * sizeof(Node*));

    if(heapStorage == NULL){
        return NULL;
    }

    newHeap->heapStorage = heapStorage;
    return newHeap;
}

Heap* heap_build(void* array, int array_size, int heap_size, int (*order_function)(void* item), void (*del_function)(void* item)){

}

void heap_destroy(Heap* heap){
    for (int i = 0; i < heap->nextIndex; i++)
    {
       Node* currentNode = heap->heapStorage[i];
       heap->del_func(currentNode->data);
       free(currentNode);
    }
    free(heap->heapStorage);
    
}

void heap_add(Heap* self, void* item){
    if(!(self->nextIndex < self->max_size)){
        return;
    }

    int order = self->order_func(item);
    Node* newNode = node_create(item, order);

    heapify_down(self);
}

void* heap_remove(Heap* self){
    if(self->nextIndex == 0){
        return NULL;
    }

    
}