#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Array Stack�� ������ ������ ���� ����� �� �ִ�.
// Linked List Stack�� ������ �ϳ��ۿ� ������ ���Ѵ�.
// �� ������ �ذ��ϱ� ���ؼ� ��� �ؾ��ϳ�? (���������� ���, linkedList���� head ������ �� ó�� ���)

int main() {
	stackType* mystack;
	elementType item;
	mystack = ACreateStack();

	// Array Stack
	printf("Array Stack\n");
	APush(mystack, 1);
	APush(mystack, 2);
	APush(mystack, 3);
	APush(mystack, 4);
	APrintStack(mystack);

	item = APop(mystack);
	printf("Poped item = %d\n", item);
	APrintStack(mystack);

	item = APop(mystack);
	printf("Poped item = %d\n", item);
	APrintStack(mystack);

	item = APop(mystack);
	printf("Poped item = %d\n", item);
	APrintStack(mystack);

	item = APop(mystack);
	printf("Poped item = %d\n", item);
	APrintStack(mystack);
	
	ADestroyStack(mystack);

	// Linked List Stack
	printf("\nLinked List Stack\n");
	LCreateStack();
	LPush(1);
	LPush(2);
	LPush(3);
	LPush(4);
	LPrintStack();

	item = LPop();
	printf("Poped item = %d\n", item);
	LPrintStack();

	item = LPop();
	printf("Poped item = %d\n", item);
	LPrintStack();

	item = LPop();
	printf("Poped item = %d\n", item);
	LPrintStack();

	item = LPop();
	printf("Poped item = %d\n", item);
	LPrintStack();

	item = LPop();
	printf("Poped item = %d\n", item);
	LPrintStack();

	LDestroyStack();
	return 0;
}