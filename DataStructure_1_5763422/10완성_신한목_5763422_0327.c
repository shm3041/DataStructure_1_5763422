#include <stdio.h>
#include <stdlib.h>

int main() {
	int** arr1;
	int** arr2;

	//2���� ���� �޸� �Ҵ� arr1
	arr1 = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++) {
		arr1[i] = (int*)malloc(sizeof(int) * 2);
	}

	//2���� ���� �޸� �Ҵ� arr2
	arr2 = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++) {
		arr2[i] = (int*)malloc(sizeof(int) * 2);
	}

	//ù ��° ��� �Է�
	printf("ù ��° ��� �Է�:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &arr1[i][j]);
		}
	}

	//�� ��° ��� �Է�
	printf("�� ��° ��� �Է�:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &arr2[i][j]);
		}
	}

	//��� ���� ��� ���
	printf("��� ���� ���:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", arr1[i][j] + arr2[i][j]);
		}
		printf("\n");
	}

	//���� �޸� �Ҵ� ���� arr1
	for (int i = 0; i < 2; i++) {
		free(arr1[i]);
	}
	free(arr1);

	//���� �޸� �Ҵ� ���� arr2
	for (int i = 0; i < 2; i++) {
		free(arr2[i]);
	}
	free(arr2);

	return 0;
}