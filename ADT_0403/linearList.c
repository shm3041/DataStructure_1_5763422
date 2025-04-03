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

int insertItem(listType* list, int index, elementType item) {
	//index�� ������ ������ �ʰ��Ͽ����� üũ / �迭 �ȿ� ���Ұ� ���� �� �ִ��� üũ
	if (index < 0 || index > list->last + 1) {
		fprintf(stderr, "Index error %d in insertItem\n", index);
		return NULL_ITEM;
	}
	if (index > list->size) {
		fprintf(stderr, "list is full (%d) in insertItem\n", index);
		return NULL_ITEM;
	}
	
	for (int i = list->last + 1; i > index; i--) {
		list->array[i] = list->array[i - 1];
		list->move++;
	}
	list->array[index] = item;
	list->last++;
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
		printf(" [%d][%d] ", i, list->array[i]);
	}
	printf("\n");
}

int initList(listType* list) {
	list->last = -1;
	list->move = 0;
}