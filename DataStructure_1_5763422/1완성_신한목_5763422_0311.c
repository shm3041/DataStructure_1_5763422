#include <stdio.h>

int main() {
	int input;
	int result = 0;

	//�� �Է¹ޱ�
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &input);

	//10���� -> 2������ ��ȯ�Ͽ� ����ϱ�
	printf("�Էµ� ������ 32��Ʈ ǥ�� : ");
	for (int i = 31; i >= 0; i--) {
		result = input >> i & 1;
		printf("%d", result);
	}

	printf("dd %h", input);

	return 0;
}