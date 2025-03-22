#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //isdigit()(문자, 숫자 구분)

#define MAX_LENGTH 100

//사칙연산을 하기 위한 함수 (매개변수: 정수 2개, 연산자)
float calculate(float num1, float num2, char operator);

int main() {
    //값을 입력받을 배열
    char input[MAX_LENGTH];

    // scanf_s를 사용하여 입력 받기. 입력 크기 제한을 두어야 한다.
    printf("계산할 수식을 입력하세요: ");
    scanf_s("%s", input, sizeof(input));

    float num[MAX_LENGTH / 2]; // 숫자 배열(소수점 연산 가능해야하므로 float 선언)
    char chr[MAX_LENGTH / 2]; // 문자 배열
    int numCount = 0, chrCount = 0; //숫자, 문자 카운트

    // 숫자와 연산자를 분리하여 배열에 저장
    int i = 0;
    while (i < strlen(input)) {
        if (isdigit(input[i]) || input[i] == '.') { //문자, 숫자 구분
            // 소수점 숫자 처리
            char number[MAX_LENGTH] = { 0 };
            int j = 0;

            // 숫자와 소수점을 읽어 하나의 숫자로 처리
            while (isdigit(input[i]) || input[i] == '.') {
                number[j++] = input[i++];
            }

            // 숫자 문자열을 실수로 변환하여 num 배열에 저장
            num[numCount++] = atof(number);
        }
        else {
            chr[chrCount++] = input[i++]; // 문자는 chr 배열에 저장
        }
    }

    // 곱셈(*)과 나눗셈(/) 먼저 계산
    for (int i = 0; i < chrCount; i++) {
        if (chr[i] == '*' || chr[i] == '/') {
            float left = num[i];
            float right = num[i + 1];
            float result = calculate(left, right, chr[i]);

            num[i] = result; // 연산 결과를 num 배열에 저장
            for (int j = i + 1; j < numCount - 1; j++) {
                num[j] = num[j + 1];
            }
            numCount--;

            for (int j = i; j < chrCount - 1; j++) {
                chr[j] = chr[j + 1];
            }
            chrCount--;

            // 연산자가 끝나면 다시 처음부터 처리
            i = -1;
        }
    }

    // 덧셈(+)과 뺄셈(-) 계산
    for (int i = 0; i < chrCount; i++) {
        if (chr[i] == '+' || chr[i] == '-') {
            float left = num[i];
            float right = num[i + 1];
            float result = calculate(left, right, chr[i]);

            num[i] = result;
            for (int j = i + 1; j < numCount - 1; j++) {
                num[j] = num[j + 1];
            }
            numCount--;

            for (int j = i; j < chrCount - 1; j++) {
                chr[j] = chr[j + 1];
            }
            chrCount--;

            // 연산자가 끝나면 다시 처음부터 처리
            i = -1;
        }
    }

    // 결과 출력
    printf("계산 결과: %.2f\n", num[0]);

    return 0;
}

// 연산 수행 함수
float calculate(float num1, float num2, char operator) {
    switch (operator) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 != 0) {
            return num1 / num2;
        }
        else {
            printf("0으로 나눌 수 없습니다!\n");
            exit(1);
        }
    default:
        return 0;
    }
}