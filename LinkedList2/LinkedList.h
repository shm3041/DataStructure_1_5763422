#pragma once

typedef int elementType;

typedef struct listNode {
	elementType data; //������ (elementType) NULL
	struct listNode* link; //��� NULL
} listNode;

extern listNode* InsertFirstNode(listNode* L, elementType item);
extern int printList(listNode* L);