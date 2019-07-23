
#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef void* DATA;
typedef enum { False, True } BOOL;

typedef struct node {

	DATA key;
	struct node* nextNode;

}NODE;

typedef struct {
	
	NODE head;

}LinkedList;

BOOL L_init(LinkedList* pList);
NODE* L_insert(NODE* pNode, DATA Value);
BOOL L_delete(NODE* pNode);
NODE* L_find(NODE* pNode, DATA Value, int(*equal)(const void*, const void*));
BOOL L_free(LinkedList* pList);
int L_print(LinkedList* pList, void(*print)(const void*));


#endif
