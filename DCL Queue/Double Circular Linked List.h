#pragma once

typedef char elementType;

typedef struct Node {
	struct Node* lLink;
	elementType data;
	struct Node* rLink;
} NodeType;

typedef NodeType QueueType;

extern QueueType* createQueue(void);
extern void destroyQueue(QueueType* Q);
extern int isQueueEmpty(QueueType* Q);
extern int isQueueFull(QueueType* Q);
extern void enQueue(QueueType* Q, elementType item);
extern elementType deQueue(QueueType* Q);
extern void printQueue(QueueType* Q);