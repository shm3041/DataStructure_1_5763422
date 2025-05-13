#pragma once

typedef int elementType; //��忡 ������ ������ Ÿ�� (����)

typedef struct ListNode { //���Ḯ��Ʈ�� ��� Ÿ�� ����
	elementType data;
	struct ListNode* link; //������ | data, next
} listNode;

//����ü�� �̸��� �ʿ��� ���� ���� ������ �Ͱ� ���� ����ü �ȿ��� ����ü�� ������� ������.
typedef struct { //���Ḯ��Ʈ�� ���(���� �ڷ��� ��ġ)
	listNode* head;
	//tail ����: ����Ʈ�� ���� �������� ����Ŵ
	int follow;
} linkedList_h;

extern linkedList_h* createLinkedList(void); //�Ű������� void�� ���� ��� ������(���ͷ�)�� �����Ѵ�.
extern int destroyLinkedList(linkedList_h* L);
extern int printList(linkedList_h* L);
extern int insertFirstNode(linkedList_h* L, elementType item);
extern int insertMiddleNode(linkedList_h* L, listNode* pre, elementType item);
extern int insertLastNode(linkedList_h* L, elementType item);
extern void insertNthNode(linkedList_h* L, int loc, elementType item); //loc: location
extern void ordered_insertNode(linkedList_h* L, elementType item);
//deleteNode First, Middle, Last �����غ���
extern void deleteNode(linkedList_h* L, listNode* p);