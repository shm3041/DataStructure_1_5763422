#include <stdio.h>
#include <stdlib.h>

int main() {
	int a;
	int b;
	int* ptr = &a;

	printf("%d\n%d\n", &a, ptr);

	freopen("1.txt", "w", stdout);
	freopen("2.txt", "w", stderr);
	if (&a == ptr)
		//fprintf(stdout, "�������");
		printf("a, ptr ����");
	else
		fprintf(stderr, "a, ptr ���� �ʴ�");
}