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

    printf("몇 명의 학생 정보를 입력하시나요? ");
    scanf_s("%d", &size);
    students = (StType*)malloc(sizeof(StType) * size);

    for (int i = 0; i < size; i++) {
        printf("[%d] 학생의 정보를 입력하세요 (이름 학번 점수): ", i);
        scanf_s("%s %d %d", students[i].name, sizeof(students[i].name), &students[i].stnum, &students[i].score);
    }

    while (1) {
        found = false;
        printf("학번을 입력하세요 (0이면 종료): ");
        scanf_s("%d", &stnum);
        if (stnum == 0) break;
        for (int i = 0; i < size; i++) {
            if (stnum == students[i].stnum) {
                printf("%s %d %d\n", students[i].name, students[i].stnum, students[i].score);
                found = true;
                break;
            }
        }
        if (!found) printf("해당 학번의 학생이 없습니다.\n");
    }

    free(students);
    return 0;
}
