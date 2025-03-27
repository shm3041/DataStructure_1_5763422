#include <stdio.h>
#include <stdlib.h>

int main() {
	int** arr1;
	int** arr2;

	arr1 = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++) {
		arr1[i] = (int*)malloc(sizeof(int) * 2);
	}

	arr2 = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++) {
		arr2[i] = (int*)malloc(sizeof(int) * 2);
	}

	printf("첫 번째 행렬 입력:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &arr1[i][j]);
		}
	}

	printf("두 번째 행렬 입력:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &arr2[i][j]);
		}
	}

	printf("행렬 덧셈 결과:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 1; j++) {
			printf("%d %d\n", arr1[i][j] + arr2[i][j], arr1[i][j + 1] + arr2[i][j + 1]);
		}
	}


	free(arr1);
	free(arr2);

	return 0;
}