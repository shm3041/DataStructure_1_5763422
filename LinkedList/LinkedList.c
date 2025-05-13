//�ڵ� ������ 0429 ��Ʈ��
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

linkedList_h* createLinkedList(void) {
	linkedList_h* lptr;

	lptr = (linkedList_h*)malloc(sizeof(linkedList_h));
	lptr->head = (listNode*)NULL;
	lptr->follow = 0;
	return lptr;
}

int destroyLinkedList(linkedList_h* L) {
	listNode* p;

	while (L->head != (listNode*)NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
	}
	free(L);
}

int printList(linkedList_h* L) {
	listNode* lptr = L->head;
	printf("Linked List(%d): ", L->follow);
	while (lptr->link != (listNode*)NULL) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d]", lptr->data);
	printf("\n");

	return 0; // 0: ����X  |  1: ����O
}

//���� ���θ� �����ϱ� ���� ���ͷ��� int�� ����
//����� �����ͼ� Node�� ���� �� ��带 ������
int insertFirstNode(linkedList_h* L, elementType item) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = L->head; //(1)  |  lptr�� �ּ�  |  lptr�� ���� data, link
	L->head = newNode; //(2)  |  [head->link = (data, link)] -> [head->link = (data, link)] -> ~~~~

	return 0; // 0: ����X  |  1: ����O
}

int insertMiddleNode(linkedList_h* L, listNode* pre, elementType item) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == (listNode*)NULL) {
		newNode->link = (listNode*)NULL;
		L->head = newNode;
	}
	else if (pre == (listNode*)NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		//���� ������ 0508
		newNode->link = pre->link; //(1)
		pre->link = newNode; //(2)
	}

	return 0;
}


int insertLastNode(linkedList_h* L, elementType item) {
	listNode *temp, *newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = (listNode*)NULL;

	temp = L->head;
	//���� ���Ḯ��Ʈ�� ���� ���ٸ� ����
	if (temp == (listNode*)NULL) {
		L->head = newNode;
		return 0;
	}
	//���� ���Ḯ��Ʈ�� ���� �ִٸ� ������ �������� ����
	while (temp->link != (listNode*)NULL) {
		temp = temp->link;
		L->follow++;
	}
	temp->link = newNode;


	return 0;
}