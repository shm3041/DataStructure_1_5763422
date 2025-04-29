//�ڵ� ������ 0429 ��Ʈ��
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

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

int printList(linkedList_h* L) {
	listNode* lptr = L->head;
	printf("Linked List: ");
	while (lptr->link != (listNode*)NULL) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d]", lptr->data);
	printf("\n");

	return 0; // 0: ����X  |  1: ����O
}