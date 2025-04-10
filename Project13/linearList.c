#include <stdio.h>
#include <stdlib.h>
#include "linearList.h"

//CRUD-PI�� �ǰ��Ͽ� �Լ� ����

listType* createList(int size) {
	//��������Ʈ ����
	listType* lptr = NULL;
	lptr = (listType*)malloc(sizeof(listType));

	lptr->array = (elementType*)malloc(sizeof(elementType) * size);
	lptr->size = size;
	lptr->move = 0;
	lptr->last = -1;

	return lptr;
}

elementType readItem(listType* list, int index) {
	if (index < 0 || list->last < index) {
		fprintf(stderr, "Index error %d in readItem\n", index);
		return NULL_ITEM;
	}
	return list->array[index];
}

int compare_item(elementType item1, elementType item2) {
	if (item1.row != item2.row) return item1.row - item2.row; //item1 > item2 = 0���� ū �� ��ȯ
	else return item1.col - item2.col; //row(��)�� ���ٸ� ���� ���Ͽ� �� ��ȯ
}

//OLL ADT
int ordered_insertItem(listType* list, elementType item) {
	int i;
	//item�� list->array[i]������ �۰ų� ���ٸ�
	for (i = 0; i <= list->last; i++) {
		if (compare_item(list->array[i], item) > 0) break;
	}
	//array[i]���� ~ last���������� ���� ��� �ڷ� �а�
	//array[i]������ ���� �����϶� (array ���� 1 ����)
	for (int j = list->last; j >= i; j--) {
		list->array[j + 1] = list->array[j];
		list->move++;
	}
	list->array[i] = item;
	list->last++;

	return 1;
}

elementType deleteItem(listType* list, int index) {
	elementType tmp = list->array[index];

	if (index < 0 || index > list->last) {
		fprintf(stderr, "Index error %d int deleteItem\n", index);
		return NULL_ITEM;
	}
	for (int i = index; i <= list->last; i++) {
		list->array[i] = list->array[i + 1];
		list->move++;
	}
	list->last--;
	return tmp;
}

void printList(listType* list) {
	printf("List: size = %d, last = %d\nItems: \n", list->size, list->last);
	for (int i = 0; i <= list->last; i++) {
		printf("   [%d] %d, %d, %d\n", i, list->array[i].row,
			list->array[i].col,
			list->array[i].value);
	}
	printf("\n");
}

void initList(listType* list) {
	list->last = -1;
	list->move = 0;
}