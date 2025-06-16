#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

int main() {
	NodeType* mylist;
	mylist = createDClinkedList();

	

	distroyDClinkedList(mylist);

	return 0;
}