#ifndef linkedlist
#define linkedlist


typedef struct LinkedList LinkedList;
typedef struct Node Node;

LinkedList * ll_create();
Node * node_create(void* data);
int ll_destroy(LinkedList* self);
int ll_add(LinkedList* self, void* item);
int ll_add_h(LinkedList* self, void* item);
int ll_del(LinkedList* self, void** delItem);
int ll_del_h(LinkedList* self, void** delItem);
void ll_print(LinkedList* self, char* f(void*));

#endif

