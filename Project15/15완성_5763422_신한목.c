#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linearList.h"

int main() {
    listType* book;
    book = createList(100);

    while (1) {
        printf("===== ��ȭ��ȣ�� �޴� =====\n");
        printf("1. ����ó �߰�\n");
        printf("2. ����ó ����\n");
        printf("3. ����ó �˻�\n");
        printf("4. ��ü ����ó ���\n");
        printf("5. ����\n");
        printf("�޴��� �����ϼ��� : ");

        int input;
        scanf("%d", &input);
        switch (input) {
        case 1:            
            AddPhone(book);
            break;
        case 2:
            deletePhone(book);
            break;
        case 3:
            searchPhone(book);
            break;
        case 4:
            printList(book);
            break;
        case 5:
            destroyList(book);
            return 0;
        }
    }
}