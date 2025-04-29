#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
	linkedList_h mylist;

	mylist.head = (listNode*)NULL;
	//ctrl + D
	insertFirstNode(&mylist, 10);
	insertFirstNode(&mylist, 20);
	insertFirstNode(&mylist, 30);
	insertFirstNode(&mylist, 40);
	insertFirstNode(&mylist, 50);

	printList(&mylist);

	return 0;
}