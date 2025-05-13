#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
	/*linkedList_h mylist;
	mylist.head = (listNode*)NULL;*/

	linkedList_h* mylist;
	mylist = createLinkedList();

	//ctrl + D
	//First
	insertFirstNode(mylist, 10);
	insertFirstNode(mylist, 20);
	insertFirstNode(mylist, 30);
	insertFirstNode(mylist, 40);
	insertFirstNode(mylist, 50);

	//Last
	insertLastNode(mylist, 60);
	insertLastNode(mylist, 70);
	insertLastNode(mylist, 80);

	//Middle
 	insertMiddleNode(mylist, mylist->head->link->link, 90);

	//Nth
	insertNthNode(mylist, 2, 20);

	printList(mylist);
	destroyLinkedList(mylist);

	printf("Destroy unorder linked list and New ordered linked list\n");
	mylist = createLinkedList();
	ordered_insertNode(mylist, 5);
	ordered_insertNode(mylist, 3);
	ordered_insertNode(mylist, 8);
	ordered_insertNode(mylist, 2);
	ordered_insertNode(mylist, 9);
	ordered_insertNode(mylist, 11);

	printList(mylist);

	deleteNode(mylist, mylist->head->link->link);
	printList(mylist);

	destroyLinkedList(mylist);
	return 0;
}