#pragma once

typedef int elementType; //노드에 저장할 데이터 타입 (정수)

typedef struct listNode { //연결리스트의 노드 타입 정의
	elementType data;
	elementType* link;
} listNode;

//구조체에 이름이 필요한 것은 위에 기재한 것과 같이 구조체 안에서 구조체를 사용하지 위함임.
typedef struct { //연결리스트의 헤더(다음 자료의 위치)
	listNode* head;
} linkedList_h;

extern int insertFirstNode(linkedList_h* L, elementType item);
extern int printList(linkedList_h* L);