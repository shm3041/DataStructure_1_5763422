/*
BEGIN

PRINT "ù ��° ��� �Է�:\n"
FOR i = 0 TO 2 DO (i++)
	FOR j = 0 TO 2 DO (j++)
		READ integer arr1(i)(j)
PRINT "�� ��° ��� �Է�:\n"
FOR i = 0 TO 2 DO (i++)
	FOR j = 0 TO 2 DO (j++)
		READ integer arr2(i)(j)
PRINT "��� ���� ���:\n"
FOR i = 0 TO 2 DO (i++)
	FOR j = 0 TO 1 DO (j++)
		PRINT "SUM(arr1 arr2)"

END
*/

#include <stdio.h>

int main() {
	int arr1[2][2];
	int arr2[2][2];
	printf("ù ��° ��� �Է�:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &arr1[i][j]);
		}
	}

	printf("�� ��° ��� �Է�:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &arr2[i][j]);
		}
	}

	printf("��� ���� ���:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 1; j++) {
			printf("%d %d\n", arr1[i][j] + arr2[i][j], arr1[i][j + 1] + arr2[i][j + 1]);
		}
	}

	return 0;
}