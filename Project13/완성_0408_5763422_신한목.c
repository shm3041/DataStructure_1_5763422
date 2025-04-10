#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linearList.h"

int main() {
	listType* myList1, * myList2, * myList3;
	elementType iMatrix;
	myList1 = createList(10);
	myList2 = createList(10);
	myList3 = createList(20);

	int i = 0;
	//ù ��° ��� �Է¹ޱ�
	printf("����� �Է��Ͻÿ�? (-1�Է� �� ����� �Է��� �����)\n");
	while (1) {
		scanf("%d", &iMatrix.row);
		if (iMatrix.row == -1) break;
		scanf("%d %d", &iMatrix.col, &iMatrix.value);

		//ordered_insertItem(myList1, iMatrix); //�Լ� ��� �� �ڵ����� ���� ���ĵǾ� ���Ե�.
		myList1->array[i] = iMatrix;
		myList1->last++;
		i++;
	}
	//�� ��° ��� �Է¹ޱ�
	i = 0;
	printf("����� �Է��Ͻÿ�? (-1�Է� �� ����� �Է��� �����)\n");
	while (1) {
		scanf("%d", &iMatrix.row);
		if (iMatrix.row == -1) break;
		scanf("%d %d", &iMatrix.col, &iMatrix.value);

		//ordered_insertItem(myList2, iMatrix);
		myList2->array[i] = iMatrix;
		myList2->last++;
		i++;
	}

	i = 0;
	int j = 0;
	while (i <= myList1->last && j <= myList2->last) {
		elementType item1 = readItem(myList1, i);
		elementType item2 = readItem(myList2, j);

		int cmp = compare_item(item1, item2);
		if (cmp == 0) {
			// ���� ��ġ�� ���Ҵ� ���� ����
			ordered_insertItem(myList3, (elementType) { item1.row, item1.col, item1.value + item2.value });
			i++;
			j++;
		}
		else if (cmp < 0) {
			// item1�� item2���� �տ� ��ġ
			ordered_insertItem(myList3, item1);
			i++;
		}
		else {
			// item2�� item1���� �տ� ��ġ
			ordered_insertItem(myList3, item2);
			j++;
		}
	}

	// ���� ����� ���� ���� ���
	while (i <= myList1->last) {
		ordered_insertItem(myList3, readItem(myList1, i++));
	}
	while (j <= myList2->last) {
		ordered_insertItem(myList3, readItem(myList2, j++));
	}

	//printList(myList1);
	//printList(myList2);
	printf("�� ����� ��\n");
	printList(myList3);

	return 0;
}