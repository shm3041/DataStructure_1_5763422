//코드 구조는 0429 노트로
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

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

int printList(linkedList_h* L) {
	listNode* lptr = L->head;
	printf("Linked List: ");
	while (lptr->link != (listNode*)NULL) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d]", lptr->data);
	printf("\n");

	return 0; // 0: 오류X  |  1: 오류O
}