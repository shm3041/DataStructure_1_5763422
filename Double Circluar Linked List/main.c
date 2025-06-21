// Double Circluar Linked List (preview , next)
#include <stdio.h>
#include <stdlib.h>

#include "Double Circular Linked List.h"

int main() {
	NodeType* mylist;
	mylist = createDClinkedList();

	/* insertFirstDClinkedList(mylist, 0); // 1�� ��ġ�� ����
	insertFirstDClinkedList(mylist, 1); // 1�� ��ġ�� ����
	insertFirstDClinkedList(mylist->rLink, 2); // 2�� ��ġ�� ����
	insertFirstDClinkedList(mylist->lLink, 3); // ������ ��ġ�� ����
	printDClinkedList(mylist);

	deleteDCLinkedList(mylist->rLink); // 1�� ��� ����
	deleteDCLinkedList(mylist->lLink); // ������ ��� ����
	deleteDCLinkedList(mylist->rLink->rLink); // 2�� ��� ����
	printDClinkedList(mylist); */

	insertLastDClinkedList(mylist, 1);
	insertLastDClinkedList(mylist, 2);
	insertLastDClinkedList(mylist, 3);
	insertLastDClinkedList(mylist, 4);
	insertLastDClinkedList(mylist, 5);
	printDClinkedList(mylist);

	deleteLastDClinkedList(mylist);
	deleteLastDClinkedList(mylist);
	printDClinkedList(mylist);

	insertNthDClinkedList(mylist, 1, 333);
	printDClinkedList(mylist);

	distroyDClinkedList(mylist);

	return 0;
}