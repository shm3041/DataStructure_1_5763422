#include <stdio.h>
#include <stdlib.h>
#include "linearList.h" //�����ڰ� ���� ��������� include�� ���� ""��
//�Լ��� CREATE - PI�� ���� ����

//listType�̶�� ����ü �������� createList �Լ� ����
listType* createList(int size) {
	listType* lptr;
	//����Ʈ ����
	lptr = (listType*)malloc(sizeof(listType));
	//List�� size��ŭ ������ �Ҵ��� �� �ְ� array��������� ũ�� elementType(int) * size��ŭ �Ҵ��Ѵ�.
	lptr->array = (elementType*)malloc(sizeof(elementType) * size);

	lptr->size = size;
	lptr->last = -1; //list�� �ʱ� �����Ͱ� ������ �⺻��: -1
	lptr->move = 0;

	return lptr;
}

elementType readItem(listType* list, int index) {
	//���� index�� element�� ������ �ʰ��Ͽ��ٸ� error�޼����� ����Ѵ�.
	if (index < 0 || index > list->last) {
		fprintf(stderr, "Index error %d in readItem\n", index);
		return NULL_ITEM;
	}

	return list->array[index];
	//return *(list->array + index); //���� ��İ� �����ϴ�.
}

int compare_item(elementType item1, elementType item2) {
	if (item1.row != item2.row) return (item1.row - item2.row);
	else return (item1.col - item2.col); //pos�� �� ���� ���� �����ϴٸ� ���� ���Ͽ� � ���� �� ������ üũ
}

int ordered_insertItem(listType* list, elementType item) {
	int i, j;
	for (i = 0; i <= list->last; i++) {
		if (compare_item(list->array[i], item) > 0) break;
	}

	for (int j = list->last + 1; j > i; j--) {
		list->array[j] = list->array[j - 1];
		list->move++;
	}
	list->array[i] = item;
	list->last++;

	return 1;
}

int insertItem(listType* list, int index, elementType item) {
	//index�� ������ ������ �ʰ��Ͽ����� üũ / �迭 �ȿ� ���Ұ� ���� �� �ִ��� üũ
	if (index < 0 || index > list->last + 1) {
		fprintf(stderr, "Index error %d in insertItem\n", index);
		return -1;
	}
	if (index > list->size) {
		fprintf(stderr, "list is full (%d) in insertItem\n", index);
		return -1;
	}

	for (int i = list->last + 1; i > index; i--) {
		list->array[i] = list->array[i - 1];
		list->move++;
	}
	list->array[index] = item;
	list->last++;

	return 1;
}

elementType deleteItem(listType* list, int index) {
	elementType r = list->array[index];

	if (index < 0 || index > list->last) {
		fprintf(stderr, "Index error %d in deleteItem\n", index);
		return NULL_ITEM;
	}

	for (int i = index; i < list->last; i++) {
		list->array[i] = list->array[i + 1];
		list->move++;
	}

	list->last--;
	return r;
}

int printList(listType* list) {
	printf("List: size = %d, last = %d, move = %d\n\t Items: ", list->size, list->last, list->move);
	for (int i = 0; i <= list->last; i++) {
		printf(" [%d]{%d,%d,%d} ", i, list->array[i].row, list->array[i].col, list->array[i].value);
	}
	printf("\n");
}

int initList(listType* list) {
	list->last = -1;
	list->move = 0;
}