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

void insertNthNode(linkedList_h* L, int loc, elementType item) {
	//����Ʈ�� ��尡 ���ٸ�
	if (L->head == (listNode*)NULL) {
		//�����Ϸ��� ����� ��ġ�� 0�̶��
		if (loc == 0) insertFirstNode(L, item);
		else fprintf(stderr, "[insertNthNode]: list empty and loc not 0\n");
		return;
	}
	else {
		if (loc == 0)
			insertFirstNode(L, item);
		else {
			/*for (int i = loc, listNode* pre = L->head;
				i--, pre = pre->link;
				i > 1 && pre->link != (listNode*)NULL) {
				if (i == 1) insertMiddleNode(L, pre, item);
				else fprintf(stderr, "[insertNthNode]: locationerror");
			}*/
			int i = loc;
			listNode* pre = L->head;
			while (i > 1 && pre->link != (listNode*)NULL) {
				i--, pre = pre->link;
				L->follow++;
			}
			if (i == 1) insertMiddleNode(L, pre, item);
			else fprintf(stderr, "[insertNthNode]: location error");
		}
		return;
	}
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

int compare_item(elementType first, elementType second) {
	return (first - second);
	//return (second - first);
}

void ordered_insertNode(linkedList_h* L, elementType item) {
	listNode* pre;

	//����Ʈ�� ����ִٸ� 0�� ��ġ�� ��� ����
	if (L->head == (listNode*)NULL)
		insertFirstNode(L, item);
	else {
		//0�� ����� �� > item , 0�� ��ġ�� ��� ����
		if (compare_item(L->head->data, item) > 0)
			insertFirstNode(L, item);
		//�ƴ϶�� ���� ���� ��
		else {
			pre = L->head;
			while (pre->link != (listNode*)NULL) {
				if (compare_item(pre->data, item) < 0 &&
					compare_item(pre->link->data, item) > 0) break;
				//if (compare_item(pre->data, item) == 0) break;
				pre = pre->link;
				L->follow++;
			}
			insertMiddleNode(L, pre, item);
		}
	}
}

void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;

	//����Ʈ�� ����ִٸ� return
	if (L->head == (listNode*)NULL) return; 
	/* å �ڵ� �̻��ؼ� �ּ�ó��(������ ����)
	if (L->head->link == (listNode*)NULL) {
		free(L->head);
		L->head = (listNode*)NULL;
		return;
	}*/
	//2�� ��ġ�� ��尡 ���ٸ� return  (p : 2����ġ�� ����Ŵ)
	else if (p == (listNode*)NULL) return;
	else {
		pre = L->head;
		//pre�� link ���� p�� �ƴ϶��, ���� ��带 ����Ŵ
		//���� p->link != (listNode*)NULL ������ �ʿ��Ѱ� =>
		//p�� ����� ���� ��ġ�� ���� ���� ��忡 ��������� �ؼ� �ʿ���.
		//������ �ش� ������ �ݺ����� �� �ʿ�� ����.
		while (pre->link != p /*&& p->link != (listNode*)NULL*/) { 
			pre = pre->link;
			L->follow++;
		}
		//1, 3�� ��带 ����, 2�� ��ġ�� �ִ� ��带 ����
		if (pre->link == p && p->link != (listNode*)NULL) {
			pre->link = p->link;
			free(p);
		}
		else 
			fprintf(stderr, "[deleteNode]: not in the list\n");
	}
}