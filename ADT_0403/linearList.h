#pragma once
#define NULL_ITEM (elementType) - 1
//ADT ���� ����� �ۼ�


typedef int elementType; //int�ڷ����� ���� �ο�

/*
//���� ����� ������� ���� ��
typedef struct {
	char name[20];
	char telphone[3][3][3];
	char address[40];
	int age;
} elementType;
*/

typedef struct ListType {
	int last; //�迭�� ���� �������� ���� ���ٴ� ���� ǥ���ϱ� ���� ����
	int size; //�迭�� ũ�⸦ �Ҵ��ϱ� ���� ����
	int move; //�����͸� �� �� �������� �ϴ��� ����
	elementType* array; //malloc�� size��ŭ �޸� �Ҵ��� ��
}listType;

//include �� �� createList�� linearList.c��� .h�� �ƴ� �ٸ� ���� �ִٴ� ��.
extern listType* createList(int size);
extern elementType readItem(listType* list, int index);
extern int insertItem(listType* list, int index, elementType item);
extern elementType deleteItem(listType* list, int index);
extern int printList(listType* list);
extern int initList(listType* list);