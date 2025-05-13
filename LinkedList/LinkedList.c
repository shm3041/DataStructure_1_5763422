//코드 구조는 0429 노트로
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

	return 0; // 0: 오류X  |  1: 오류O
}

//에러 여부를 리턴하기 위해 리터럴을 int로 지정
//헤더를 가져와서 Node를 만든 후 노드를 삽입함
int insertFirstNode(linkedList_h* L, elementType item) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = L->head; //(1)  |  lptr의 주소  |  lptr의 값은 data, link
	L->head = newNode; //(2)  |  [head->link = (data, link)] -> [head->link = (data, link)] -> ~~~~

	return 0; // 0: 오류X  |  1: 오류O
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
		//사진 찍어놓음 0508
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
	//만약 연결리스트에 값이 없다면 리턴
	if (temp == (listNode*)NULL) {
		L->head = newNode;
		return 0;
	}
	//만약 연결리스트에 값이 있다면 마지막 지점으로 설정
	while (temp->link != (listNode*)NULL) {
		temp = temp->link;
		L->follow++;
	}
	temp->link = newNode;


	return 0;
}