#include <stdio.h>
#include <stdlib.h>

//void add1array(int* iptr);
//
//int main() {
//	int i;
//	int* iptr;
//	int iArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int iArray2[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
//
//	i = 10;
//	iptr = &i;
//
//	printf("i: %d, address of i 0x%X\n", i, &i);
//	printf("iptr : 0x%X, value of iptr pointer : %d\n", iptr, *iptr);
//	printf("\n");
//
//	iptr = iArray;
//	printf("i: %d\n", *iptr);
//	iptr = iArray + 5;
//	printf("i: %d\n", *iptr);
//	printf("\n");
//
//	printf("iArray:");
//	for (int i = 0; i < 10; i++)
//		printf(" %d ", iArray[i]);
//	printf("\n");
//
//	printf("iArray2:");
//	for (int i = 0; i < 10; i++)
//		printf(" %d ", iArray2[i]);
//	printf("\n");
//	printf("\n");
//
//	//for (int i = 0; i < 10; i++)
//	//	iArray[i] = iArray[i] + 1;
//
//	iptr = &iArray[0];
//	for (int j = 0; j < 10; j++) {
//		*iptr = *iptr + 1;
//		iptr++;
//	}
//	iptr = &iArray2[0];
//	for (int j = 0; j < 10; j++) {
//		*iptr = *iptr + 1;
//		iptr++;
//	}
//	//or 함수사용
//	add1array(iArray);
//	add1array(&iArray2[0]);
//
//
//	printf("iArray:");
//	for (int i = 0; i < 10; i++)
//		printf(" %d ", iArray[i]);
//	printf("\n");
//
//	printf("iArray2:");
//	for (int i = 0; i < 10; i++)
//		printf(" %d ", iArray2[i]);
//	printf("\n");
//
//	
//	return 0;
//}
//
//void add1array(int* iptr) {
//	for (int j = 0; j < 10; j++) {
//		*iptr = *iptr + 1;
//		iptr++;
//	}
//}
//
//int main() {
//	int i;
//	int* iptr;
//	printf("number of iArray element?\n");
//	scanf_s("%d", &i);
//
//	iptr = (int*)malloc(sizeof(int) * i);
//
//	//for (int j = 0; j < i; j++)
//	//	*(iptr + j) = j + 1;
//	for (int j = 0; j < i; j++)
//		iptr[j] = j + 1;
//
//	printf("memory alloc array:");
//	for (int j = 0; j < i; j++) {
//		printf(" %d ", *(iptr + j));
//	}
//
//	return 0;
//}

typedef struct student {
	char name[20];
	int id;
	int score;
} StdType;

int main() {
	StdType students[3] = { 
		{"Honggil Dong", 10, 90}, 
		{"Lee MongRyong", 20, 80}, 
		{"Seong ChoonHyang", 30, 70}
	};

	for (int i = 0; i < 3; i++) {
		students[i].score += 10;
	}

	StdType* sptr = students; //students[0]
	for (int i = 0; i < 3; i++) {
		//sptr->score += 10;
		(*sptr).score += 10;
	}

	return 0;
}