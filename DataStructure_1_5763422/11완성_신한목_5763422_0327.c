#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//�л� ����ü ����
typedef struct student {
    char name[20]; //�̸�
    int stnum, score; //�й�, ����
} StType;

int main() {
    int size; //students ���� �޸� �Ҵ� ũ��
    StType* students; //�л� ����ü
    int stnum; //�й�
    bool found; //�й� ���翩�� Ȯ�� (1: true, 0: false)

    //�л� �� �Է¹ޱ�
    printf("�� ���� �л� ������ �Է��Ͻó���? ");
    scanf_s("%d", &size);
    students = (StType*)malloc(sizeof(StType) * size);

    //�л� ���� �Է¹ޱ� (�̸�, �й�, ����)
    for (int i = 0; i < size; i++) {
        printf("[%d] �л��� ������ �Է��ϼ��� (�̸� �й� ����): ", i);
        scanf_s("%s %d %d", students[i].name, sizeof(students[i].name), &students[i].stnum, &students[i].score);
    }

    //�й����� �л����� �˻�
    while (1) {
        found = false;

        //�й� �Է¹ޱ�
        printf("�й��� �Է��ϼ��� (0�̸� ����): ");
        scanf_s("%d", &stnum);

        //0�Է� �� ����
        if (stnum == 0) break;

        //�л� ���� ã��
        for (int i = 0; i < size; i++) {
            if (stnum == students[i].stnum) {
                printf("%s %d %d\n", students[i].name, students[i].stnum, students[i].score);
                found = true;
                break;
            }
        }

        //�л� ������ ���ٸ� ���
        if (!found) printf("�ش� �й��� �л��� �����ϴ�.\n");
    }

    //���� �޸� �Ҵ� ����
    free(students);
    return 0;
}
