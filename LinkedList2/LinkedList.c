#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

listNode* InsertFirstNode(listNode* L, elementType item) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = L;
	L = newNode;
	return L;
}

int printList(listNode* L) {
	while (L->link != NULL) {
		printf("[%d]", L->data);
		L = L->link;
	} printf("[%d]", L->data);
	printf("\n");
}