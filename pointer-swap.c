#include "stdio.h"

void swap(int* a, int* b, int* c) {
	int newA = *a;
	int newB = *b;
	int newC = *c;

	*a = newC;
	*b = newA;
	*c = newB;
}

int* maxOf2(int* a, int* b) {
	if (*a > *b) {
		return a;
	}
	return b;
}

int* maxOf3(int* a, int* b, int* c) {
	return maxOf2(maxOf2(a, b), c);
}

int main() {
	int a = 1;
	int b = 2;
	int c = 3;

	printf("swap\n");
	swap(&a, &b, &c);
	
	printf("3 == %d\n", a);
	printf("1 == %d\n", b);
	printf("2 == %d\n", c);

	int q = 1;
	int w = 2;
	int e = 3;

	printf("%p\n", maxOf3(&q, &w, &e));

	return 0;
}
