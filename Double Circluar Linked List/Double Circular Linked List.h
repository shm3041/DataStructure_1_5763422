#pragma once

typedef int elementType;

typedef struct Node {
	struct Node* lLink;
	elementType data;
	struct Node* rLink;
} NodeType;

extern NodeType* createDClinkedList();
extern void insertFirstDClinkedList(NodeType* Node, elementType item);
extern void insertLastDClinkedList(NodeType* Node, elementType item);
extern void insertNthDClinkedList(NodeType* Node, int index, elementType item);
extern void printDClinkedList(NodeType* H);