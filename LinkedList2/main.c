#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main() {
	listNode* A = (listNode*)malloc(sizeof(listNode));
	A = NULL;

	A = InsertFirstNode(A, 1);
	A = InsertFirstNode(A, 2);
	A = InsertFirstNode(A, 3);
	A = InsertFirstNode(A, 4);

	printList(A);

	return 0;
}