#pragma once

typedef int elementType;

typedef struct listNode {
	elementType data; //데이터 (elementType) NULL
	struct listNode* link; //노드 NULL
} listNode;

extern listNode* InsertFirstNode(listNode* L, elementType item);
extern int printList(listNode* L);