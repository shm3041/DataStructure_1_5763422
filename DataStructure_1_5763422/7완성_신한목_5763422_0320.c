#include <stdio.h>
#include <stdlib.h> // exit(1)
#include <string.h>
#include <ctype.h> // isdigit()(����, ���� ����)

#define MAX_LENGTH 100

float calculate(float num1, float num2, char operator);//��Ģ������ �ϱ� ���� �Լ� (�Ű�����: ���� 2��, ������)
float add(float a, float b); //���ϱ�
float subtract(float a, float b); //����
float multiply(float a, float b); //���ϱ�
float divide(float a, float b); //������

int main() {
    //���� �Է¹��� �迭
    char input[MAX_LENGTH];

    // scanf_s�� ����Ͽ� �Է� �ޱ�. �Է� ũ�� ������ �ξ�� �Ѵ�.
    printf("����� ������ �Է��ϼ���: ");
    scanf_s("%s", input, sizeof(input));

    float num[MAX_LENGTH / 2]; // ���� �迭(�Ҽ��� ���� �����ؾ��ϹǷ� float ����)
    char chr[MAX_LENGTH / 2]; // ���� �迭
    int numCount = 0, chrCount = 0; //����, ���� ī��Ʈ

    // ���ڿ� �����ڸ� �и��Ͽ� �迭�� ����
    int i = 0;
    while (i < strlen(input)) {
        if (isdigit(input[i]) || input[i] == '.') { //����, ���� ����
            char number[MAX_LENGTH] = { 0 };
            int j = 0;

            while (isdigit(input[i]) || input[i] == '.') {
                number[j++] = input[i++];
            }
            num[numCount++] = atof(number);
        }
        else {
            chr[chrCount++] = input[i++];
        }
    }
    // ����(*)�� ������(/) ���� ���
    for (int i = 0; i < chrCount; i++) {
        if (chr[i] == '*' || chr[i] == '/') {
            float result = calculate(num[i], num[i + 1], chr[i]);
            num[i] = result;
            for (int j = i + 1; j < numCount - 1; j++) num[j] = num[j + 1];
            numCount--;
            for (int j = i; j < chrCount - 1; j++) chr[j] = chr[j + 1];
            chrCount--;
            i = -1;
        }
    }
    // ����(+)�� ����(-) ���
    for (int i = 0; i < chrCount; i++) {
        if (chr[i] == '+' || chr[i] == '-') {
            float result = calculate(num[i], num[i + 1], chr[i]);
            num[i] = result;
            for (int j = i + 1; j < numCount - 1; j++) num[j] = num[j + 1];
            numCount--;
            for (int j = i; j < chrCount - 1; j++) chr[j] = chr[j + 1];
            chrCount--;
            i = -1;
        }
    }

    printf("��� ���: %.2f\n", num[0]);
    return 0;
}

// ���� �Լ�
float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) {
    if (b != 0) return a / b;
    printf("0���� ���� �� �����ϴ�!\n");
    exit(1);
}

float calculate(float num1, float num2, char operator) {
    switch (operator) {
    case '+': return add(num1, num2);
    case '-': return subtract(num1, num2);
    case '*': return multiply(num1, num2);
    case '/': return divide(num1, num2);
    default: return 0;
    }
}