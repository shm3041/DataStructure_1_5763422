#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "LinkedList.h"

void logicMenu();

int main() {
	linkedList_h* mylist;
	mylist = createCLinkedList();

	logicMenu(mylist);

	//destroyCLinkedList(mylist);
	return 0;
}

void logicMenu(linkedList_h* list) {
	int choice;

	while (1) {
		printMenu();
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			insertFirstCNode(list);
			printCList(list);
			break;
		case 2:
			insertLastCNode(list);
			printCList(list);
			break;
		case 3:
			insertMiddleCNode(list);
			printCList(list);
			break;
		case 4:
			insertNthCNode(list);
			printCList(list);
			break;
		case 6:
			deleteCNode(list);
			printCList(list);
			break;
		case 7:
			system("cls");
			printf("Select menu �� %d\n", choice);
			printHeadTail(list);
			break;
		case 0:
			return;
		default:
			system("cls");
			printf("�߸��� ���� �Է��ϼ̽��ϴ�.\n");
			break;
		}
		printf("\n");
	}
}