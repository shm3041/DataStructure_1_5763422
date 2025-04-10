#pragma once
//���� �޼���
#define NULL_ITEM (elementType) {-1, -1, -1}
//��������Ʈ�� �����ϱ� ���� �ʿ��� �ڷ����� ����.

//����Ʈ ������ �ڷ���
typedef struct ElementType {
	int row; //��
	int col; //��
	int value; //��
} elementType;

//����Ʈ ���� ����
typedef struct ListType {
	int size; //ũ��
	int move; //�̵� (Ư�� ��ġ�� ���Ҹ� �����ϱ� ����)
	int last; //������ ����
	elementType* array; //malloc, ����Ʈ
}listType;

//include �� �� createList�� linearList.c��� .h�� �ƴ� �ٸ� ���� �ִٴ� ��.
extern listType* createList(int size);
extern elementType readItem(listType* list, int index);
extern int insertItem(listType* list, int index, elementType item);
extern elementType deleteItem(listType* list, int index);
extern void printList(listType* list);
extern void initList(listType* list);
extern int ordered_insertItem(listType* list, elementType item);
extern int compare_item(elementType item1, elementType item2);