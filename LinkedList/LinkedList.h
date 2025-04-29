#pragma once

typedef int elementType; //��忡 ������ ������ Ÿ�� (����)

typedef struct listNode { //���Ḯ��Ʈ�� ��� Ÿ�� ����
	elementType data;
	elementType* link;
} listNode;

//����ü�� �̸��� �ʿ��� ���� ���� ������ �Ͱ� ���� ����ü �ȿ��� ����ü�� ������� ������.
typedef struct { //���Ḯ��Ʈ�� ���(���� �ڷ��� ��ġ)
	listNode* head;
} linkedList_h;

extern int insertFirstNode(linkedList_h* L, elementType item);
extern int printList(linkedList_h* L);