#include <stdio.h>

int sum(int num1, int num2); //���� �Լ�
int sub(int num1, int num2); //���� �Լ�
int mul(int num1, int num2); //���� �Լ�
float div(int num1, int num2); //������ �Լ�

int main() {
	int num1, num2;

	//���� 2�� �Է¹ޱ�
	printf("ù ��° ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &num1);
	printf("�� ��° ���� ������ �Է��ϼ���: ");
	scanf_s("%d", &num2);

	//��Ģ���� �� ��� ���
	printf("����: %d\n", sum(num1, num2));
	printf("����: %d\n", sub(num1, num2));
	printf("����: %d\n", mul(num1, num2));
	printf("������: %.2f\n", div(num1, num2));
	
	return 0;
}

//����
int sum(int num1, int num2) {
	return num1 + num2;
}

//����
int sub(int num1, int num2) {
	return num1 - num2;
}

//����
int mul(int num1, int num2) {
	return num1 * num2;
}

//������
float div(int num1, int num2) {
	return (float)num1 / (float)num2;
}