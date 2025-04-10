#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned long long int call = 0;

unsigned long long int fibo_rec(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		call++;
		return (fibo_rec(n - 1) + fibo_rec(n - 2));
	}
}

unsigned long long int fibo_itr(int n) {
	unsigned long long int f_n_2 = 0;
	unsigned long long int f_n_1 = 1;
	unsigned long long int f_n = 0;

	if (n == 0) return 0;
	else if (n == 1) return 1;

	for (int i = 2; i <= n; i++) {
		call++;

		f_n = f_n_1 + f_n_2;
		f_n_2 = f_n_1;
		f_n_1 = f_n;
	}
	return f_n;
}

int main() {
	int choice, n;

	while (1) {
		printf("�Ǻ���ġ ���� ��� ���� (1: �����, 2: ��ȯ��, 0: ����): ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("���� N�� �Է��ϼ��� (�����Ϸ��� 0 �Է�): ");
			scanf("%d", &n);

			call = 0;
			printf("F (%d) = %llu (����� ���)\n", n, fibo_rec(n));
			printf("ȣ��Ƚ��: %llu\n", call);
			break;
		case 2:
			printf("���� N�� �Է��ϼ��� (�����Ϸ��� 0 �Է�): ");
			scanf("%d", &n);

			call = 0;
			printf("F (%d) = %llu (��ȯ�� ���)\n", n, fibo_itr(n));
			printf("ȣ��Ƚ��: %llu\n", call);
			break;
		case 0:
			printf("���α׷��� ����Ǿ����ϴ�.\n");
			return 0;
		default:
			printf("�߸��� �Է��Դϴ�.\n");
			return 0;
		}
	}
	return 0;
}