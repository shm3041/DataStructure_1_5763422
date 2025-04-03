#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fibo_rec(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		return (fibo_rec(n - 1) + fibo_rec(n - 2));
	}
}

int fibo_itr(int n) {
	int f_n_2 = 0;
	int f_n_1 = 1;
	int f_n = 0;

	if (n == 0) return 0;
	else if (n == 1) return 1;

	for (int i = 2; i <= n; i++) {
		f_n = f_n_1 + f_n_2;
		f_n_2 = f_n_1;
		f_n_1 = f_n;
	}
	return f_n;
}

int main() {
	int choice, n;

	while (1) {
		printf("피보나치 수열 방법 선택 (1: 재귀적, 2: 순환적, 0: 종료): ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("정수 N을 입력하세요 (종료하려면 0 입력): ");
			scanf("%d", &n);

			printf("F (%d) = %d (재귀적 방법)\n", n, fibo_rec(n));
			break;
		case 2:
			printf("정수 N을 입력하세요 (종료하려면 0 입력): ");
			scanf("%d", &n);

			printf("F (%d) = %d (순환적 방법)\n", n, fibo_itr(n));
			break;
		case 0:
			printf("프로그램이 종료되었습니다.\n");
			return 0;
		default:
			printf("잘못된 입력입니다.\n");
			return 0;
		}
	}
	return 0;
}