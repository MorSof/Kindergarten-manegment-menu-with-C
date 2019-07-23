#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

BOOL L_init(LinkedList* pList)
{
	if (pList == NULL)
		return False;
	pList->head.nextNode = NULL;//
	return True;
}

NODE* L_insert(NODE* pNode, DATA Value)
{
	NODE* tmp;

	if (!pNode) return NULL;

	tmp = (NODE*)malloc(sizeof(NODE));

	if (tmp != NULL) {
		tmp->key = Value;
		tmp->nextNode = pNode->nextNode;
		pNode->nextNode = tmp;
	}
	return tmp;
}

BOOL L_delete(NODE* pNode)
{
	NODE* tmp;

	if (!pNode || !(tmp = pNode->nextNode)) return False;

	pNode->nextNode = tmp->nextNode;
	free(tmp);
	return True;
}

//optional, was not use in this exrecise
NODE* L_find(NODE* pNode, DATA Value,
	int(*equal)(const void*, const void*))
{
	NODE* tmp;

	if (!pNode) return NULL;
	tmp = pNode;

	while ((tmp != NULL) && (equal(tmp->key, Value) != 1))
		tmp = tmp->nextNode;

	return tmp;
}

BOOL L_free(LinkedList* pList)
{
	NODE *tmp;

	if (!pList) return False;

	for (tmp = &(pList->head); L_delete(tmp); );
	return True;
}

int L_print(LinkedList* pList, void(*print)(const void*))
{
	NODE	*tmp;
	int		c = 0;

	if (!pList) 
		return 0;

	printf("\n");
	for (tmp = pList->head.nextNode; tmp; tmp = tmp->nextNode, c++)
	{
		print(tmp->key);
		printf("\n");
	}
	printf("\n");
	return c;
}
