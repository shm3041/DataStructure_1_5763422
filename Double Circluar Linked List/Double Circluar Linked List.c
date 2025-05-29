#include <stdio.h>
#include <stdlib.h>
#include "Double Circular Linked List.h"

// Create Head (Data X)
NodeType* createDClinkedList() {
	NodeType* H;

	H = (NodeType*)malloc(sizeof(NodeType));
	H->lLink = H;
	H->rLink = H;
	return H;
}

// insert First Node
void insertFirstDClinkedList(NodeType* Node, elementType item) {
	NodeType* newNode;

	newNode = (NodeType*)malloc(sizeof(NodeType));
	newNode->data = item;

	newNode->lLink = Node;
	newNode->rLink = Node->rLink;
	Node->rLink->lLink = newNode;
	Node->rLink = newNode;
}

void insertLastDClinkedList(NodeType* Node, elementType item) {
	NodeType* newNode;

	newNode = (NodeType*)malloc(sizeof(NodeType));
	newNode->data = item;

	newNode->lLink = Node->lLink;
	newNode->rLink = Node;
	Node->lLink->rLink = newNode;
	Node->lLink = newNode;
}

void insertNthDClinkedList(NodeType* Node, int index, elementType item) {
	NodeType* newNode;
	NodeType* temp = Node;

	newNode = (NodeType*)malloc(sizeof(NodeType));
	newNode->data = item;

	for (int i = 0; i <= index; i++) {
		temp = temp->rLink;
	}

	newNode->lLink = temp;
	newNode->rLink = temp->rLink;
	temp->rLink->lLink = newNode;
	temp->rLink = newNode;

}

void printDClinkedList(NodeType* H) {
	NodeType* nptr = H->rLink;

	printf("이중연결리스트 출력: ");

	while (nptr != H) {
		printf("[%d]", nptr->data);
		nptr = nptr->rLink;
	}
	printf("\n");

	/*if (nptr->rLink == H) return;
	nptr = nptr->rLink;

	do {
		printf("[%d]", nptr->data);
		nptr->rLink;
	} while (nptr != H);
	printf("\n");*/
}