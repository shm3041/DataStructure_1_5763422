#include <stdio.h>
#include <stdlib.h>

#include "Double Circular Linked List.h"

int main() {
	NodeType* mylist;
	mylist = createDClinkedList();

	/*insertFirstDClinkedList(mylist, 1);
	insertFirstDClinkedList(mylist, 2);
	insertFirstDClinkedList(mylist, 3);
	insertFirstDClinkedList(mylist, 4);
	insertFirstDClinkedList(mylist, 5);
	printDClinkedList(mylist);*/

	insertLastDClinkedList(mylist, 1);
	insertLastDClinkedList(mylist, 2);
	insertLastDClinkedList(mylist, 3);
	insertLastDClinkedList(mylist, 4);
	insertLastDClinkedList(mylist, 5);
	printDClinkedList(mylist);

	insertNthDClinkedList(mylist, 2, 333);
	printDClinkedList(mylist);

	return 0;
}