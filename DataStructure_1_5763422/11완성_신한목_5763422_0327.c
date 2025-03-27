#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct student {
    char name[20];
    int stnum, score;
} StType;

int main() {
    int size;
    StType* students;
    int stnum;
    bool found;

    printf("�� ���� �л� ������ �Է��Ͻó���? ");
    scanf_s("%d", &size);
    students = (StType*)malloc(sizeof(StType) * size);

    for (int i = 0; i < size; i++) {
        printf("[%d] �л��� ������ �Է��ϼ��� (�̸� �й� ����): ", i);
        scanf_s("%s %d %d", students[i].name, sizeof(students[i].name), &students[i].stnum, &students[i].score);
    }

    while (1) {
        found = false;
        printf("�й��� �Է��ϼ��� (0�̸� ����): ");
        scanf_s("%d", &stnum);
        if (stnum == 0) break;
        for (int i = 0; i < size; i++) {
            if (stnum == students[i].stnum) {
                printf("%s %d %d\n", students[i].name, students[i].stnum, students[i].score);
                found = true;
                break;
            }
        }
        if (!found) printf("�ش� �й��� �л��� �����ϴ�.\n");
    }

    free(students);
    return 0;
}
