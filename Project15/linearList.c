#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linearList.h"

listType* createList(int size) {
	listType* lptr;
	lptr = (listType*)malloc(sizeof(listType));
	lptr->array = (elementType*)malloc(sizeof(elementType) * size);
	lptr->size = size;
	lptr->last = -1;
	lptr->move = 0;

	return lptr;
}

void destroyList(listType* list) {
	free(list->array);
	free(list);
}

elementType readItem(listType* list, int index) {
	if (index < 0 || index > list->last) {
		fprintf(stderr, "Index error %d in readItem\n", index);
		return NULL_ITEM;
	}
	return list->array[index];
}

int compare_item(elementType item1, elementType item2) {
	return strcmp(item1.name, item2.name); 
}
int ordered_insertItem(listType* list, elementType item) {
	int i, j;

	for (i = 0; i <= list->last; i++) {
		if (compare_item(list->array[i], item) > 0) break;
	}

	for (j = list->last + 1; j > i; j--) {
		list->array[j] = list->array[j - 1];
		list->move++;
	}
	list->array[i] = item;
	list->last++;

	return 1;
}

/* int insertItem(listType* list, int index, elementType item) {
	if (index < 0 || index >(list->last + 1)) {
		fprintf(stderr, "Index error %d in readItem\n", index);
		return -1;
	}
	if (index > list->size) {
		fprintf(stderr, "list is full(%d) in readItem\n", index);
		return -1;
	}

	for (int i = list->last + 1; i > index; i--) {
		list->array[i] = list->array[i - 1];
		list->move++;
	}
	list->array[index] = item;
	list->last++;

	return 1;
} */

void deleteItem(listType* list, elementType index) {
	int i, found = 0;
	
	for (i = 0; i <= list->last; i++) {
		if (!strcmp(list->array[i].name, index.name)) {
			found = 1;
			for (int j = i; j <= list->last; j++) {
				list->array[j] = list->array[j + 1];
				list->move++;
			}
			printf("�����Ǿ����ϴ�.\n\n\n");
			list->last--;
		}
	}
	if (!found)
		printf("�ش� ����ó�� �������� �ʽ��ϴ�. \n\n\n");
}

int printList(listType* book) {
	printf("\n----- ��ü ����ó -----\n");
	for (int i = 0; i <= book->last; i++) {
		printf("[%d] �̸�: %s, ��ȭ��ȣ: %s\n", i + 1, book->array[i].name, book->array[i].phone);
	}
	printf("----------------------\n");

	if (book->last == -1) {
		printf("\n\n");
		return -1;
	}
	return 0;
}

//��ȭ��ȣ�� ���� �Լ�
void AddPhone(listType* book) {
	elementType tmp;
	printf("�̸��� �Է��ϼ���: ");
	scanf(" %[^\n]s", tmp.name);

	printf("��ȭ��ȣ�� �Է��ϼ���: ");
	scanf(" %s", tmp.phone);

	ordered_insertItem(book, tmp);
	printf("����ó�� �߰��Ǿ����ϴ�.\n\n\n");
}

void deletePhone(listType* book) {
	elementType tmp;
	printf("������ �̸��� �Է��ϼ���: ");
	scanf(" %[^\n]s ", tmp.name);
	deleteItem(book, tmp);
}

void searchPhone(listType* book) {
	elementType tmp;
	int found = 0;
	printf("�˻��� �̸�: ");
	scanf(" %[^\n]s ", tmp.name);
	for (int i = 0; i <= book->last; i++) {
		if (!strcmp(book->array[i].name, tmp.name)) {
			printf("[%d] �̸�: %s, ��ȭ��ȣ: %s\n", i + 1, book->array[i].name, book->array[i].phone);
			found = 1;
			break;
		}
	}
	if (!found)
		printf("�ش� ����ó�� �������� �ʽ��ϴ�.\n\n\n");
}

int initList(listType* list) {
	list->last = -1;
	list->move = 0;
	return 0;
}