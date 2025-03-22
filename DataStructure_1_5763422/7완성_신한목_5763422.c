#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //isdigit()(����, ���� ����)

#define MAX_LENGTH 100

//��Ģ������ �ϱ� ���� �Լ� (�Ű�����: ���� 2��, ������)
float calculate(float num1, float num2, char operator);

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
            // �Ҽ��� ���� ó��
            char number[MAX_LENGTH] = { 0 };
            int j = 0;

            // ���ڿ� �Ҽ����� �о� �ϳ��� ���ڷ� ó��
            while (isdigit(input[i]) || input[i] == '.') {
                number[j++] = input[i++];
            }

            // ���� ���ڿ��� �Ǽ��� ��ȯ�Ͽ� num �迭�� ����
            num[numCount++] = atof(number);
        }
        else {
            chr[chrCount++] = input[i++]; // ���ڴ� chr �迭�� ����
        }
    }

    // ����(*)�� ������(/) ���� ���
    for (int i = 0; i < chrCount; i++) {
        if (chr[i] == '*' || chr[i] == '/') {
            float left = num[i];
            float right = num[i + 1];
            float result = calculate(left, right, chr[i]);

            num[i] = result; // ���� ����� num �迭�� ����
            for (int j = i + 1; j < numCount - 1; j++) {
                num[j] = num[j + 1];
            }
            numCount--;

            for (int j = i; j < chrCount - 1; j++) {
                chr[j] = chr[j + 1];
            }
            chrCount--;

            // �����ڰ� ������ �ٽ� ó������ ó��
            i = -1;
        }
    }

    // ����(+)�� ����(-) ���
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

            // �����ڰ� ������ �ٽ� ó������ ó��
            i = -1;
        }
    }

    // ��� ���
    printf("��� ���: %.2f\n", num[0]);

    return 0;
}

// ���� ���� �Լ�
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
            printf("0���� ���� �� �����ϴ�!\n");
            exit(1);
        }
    default:
        return 0;
    }
}