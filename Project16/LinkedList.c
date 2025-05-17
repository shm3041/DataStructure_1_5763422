#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "LinkedList.h"

linkedList_h* createCLinkedList(void) {
	linkedList_h* lptr;

	lptr = (linkedList_h*)malloc(sizeof(linkedList_h));
	lptr->head = (listNode*)NULL;
	lptr->tail = (listNode*)NULL;
	lptr->follow = 0;

	return lptr;
}

void destroyCLinkedList(linkedList_h* L) {
	if (L->head != NULL) {
		if (L->head->link == L->head) {
			free(L->head);
		}
		else {
			listNode* me = L->head->link;
			listNode* next;

			while (me != L->head) {
				next = me->link;
				free(me);
				me = next;
			}
			free(L->head);
		}
	}
	free(L);
}

void printMenu() {
	printf("=======  Linked_list Menu  =======\n");
	printf("1) insertFirst    (����Ʈ�� ���� �տ� ����)\n");
	printf("2) insertLast     (����Ʈ�� ���� �ڿ� ����)\n");
	printf("3) insertMiddle   (Ư�� �� �ڿ� ����)\n");
	printf("4) insertNthNode  (N��° ��ġ ����)\n");
	printf("6) deleteNode     (Ư�� �� ����)\n");
	printf("7) print Head/Tail\n");
	printf("0) Program Stop\n");
	printf("Select menu �� ");
}

void printCList(linkedList_h* L) {
	listNode* lptr = L->head;

	printf("Linked List(%d): ", L->follow);
	if (lptr == NULL) {
		printf("\n");
		return;
	}

	while (lptr != L->tail) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d]", lptr->data);
	printf("\n");
}

void printHeadTail(linkedList_h* L) {
	if (L->head == (listNode*)NULL)
		printf("Head/Tail �� ����Ʈ�� ��� �ֽ��ϴ�.\n");
	else
		printf("Head �� [%d]   Tail �� [%d]\n", L->head->data, L->tail->data);
}

void insertFirstCNode(linkedList_h* L) {
	listNode* newNode;
	elementType item;

	// �Է�
	printf("    ������ ��: ");
	scanf("%d", &item);

	// �� ����
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == (listNode*)NULL) {
		newNode->link = newNode;
		L->tail = newNode;
	}
	else {
		newNode->link = L->head;
		L->tail->link = newNode;
	}

	L->head = newNode;

	// ���
	system("cls");
	printf("    ������ ��: %d\n", item);
}

void insertMiddleCNode(linkedList_h* L) {
	listNode* Node, * newNode;
	elementType itemOld, itemNew;

	// �Է�
	printf("  (Key) � �� �ڿ�?: ");
	scanf("%d", &itemOld);
	printf("  ������ ��: ");
	scanf("%d", &itemNew);

	// itemOld���� �̵�
	Node = L->head;
	while (Node->data != itemOld) {
		Node = Node->link;
		L->follow++;
	}
	
	// �� ����
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = itemNew;
	newNode->link = Node->link;
	Node->link = newNode;

	// ���
	system("cls");
	printf("  ������ ��: %d\n", itemNew);
}

void insertNthCNode(linkedList_h* L) {
	listNode* Node, * newNode;
	int index;
	elementType item;

	// �Է�
	printCList(L);
	//printf("\033[A"); // \n �����
	printf("  ��ġ(index, 0����): ");
	scanf("%d", &index);
	printf("  ������ ��: ");
	scanf("%d", &item);

	// index - 1���� �̵�
	int count = 0;
	Node = L->head;
	while (count != index - 1) {
		Node = Node->link;
		count++;
		L->follow++;
	}

	// �� ����
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = Node->link;
	Node->link = newNode;

	// ���
	system("cls");
	printf("  ������ ��: %d\n", item);
}

void insertLastCNode(linkedList_h* L) {
	listNode* newNode;
	elementType item;

	printf("    ������ ��: ");
	scanf("%d", &item);

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == (listNode*)NULL) {
		newNode->link = newNode;
		L->head = newNode;
		L->tail = newNode;
	}
	else {
		L->tail->link = newNode;
		newNode->link = L->head;
		L->tail = newNode;
	}

	system("cls");
	printf("    ������ ��: %d\n", item);
}

void deleteCNode(linkedList_h* L) {

	listNode* Node, * delNode;
	elementType item;

	//�Է�
	printf("    ������ ��: ");
	scanf("%d", &item);

	//item - 1���� �̵�
	Node = L->head;
	while (Node->link->data != item) {
		Node = Node->link;
		L->follow++;
	}
	
	//�� ����
	delNode = Node->link;
	Node->link = Node->link->link;
	free(delNode);

	//���
	system("cls");
	printf("    ������ ��: %d\n", item);
}