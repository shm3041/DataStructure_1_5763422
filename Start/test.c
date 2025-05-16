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
		//fprintf(stdout, "정상출력");
		printf("a, ptr 같다");
	else
		fprintf(stderr, "a, ptr 같지 않다");
}