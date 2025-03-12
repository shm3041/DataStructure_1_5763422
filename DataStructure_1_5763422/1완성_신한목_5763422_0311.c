#include <stdio.h>

int main() {
	int input;
	int result = 0;

	//값 입력받기
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &input);

	//10진수 -> 2진수로 변환하여 출력하기
	printf("입력된 정수의 32비트 표현 : ");
	for (int i = 31; i >= 0; i--) {
		result = input >> i & 1;
		printf("%d", result);
	}

	printf("dd %h", input);

	return 0;
}