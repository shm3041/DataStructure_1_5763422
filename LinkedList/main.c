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

 	insertMiddleNode(mylist, mylist->head->link->link, 90);
	printList(mylist);
	destroyLinkedList(mylist);
	return 0;
}