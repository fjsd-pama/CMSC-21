#include "stdio.h"

int fibn(int num) {
	if (num == 0) {
		return 1;
	} else if (num == 1) {
		return 2;
	} else {
		return fibn(n - 2) + fibn(n - 1);
	}
}

int sumOfDigts(int num) {
	if (num == 0) {
		return 0;
	} else {
		int inDigits = num % 10;
		int remaining = num / 10;
		return inDigits + sumOfDigts(remaining);
	}

}

int multiply(int x, int y) {
	if (y == 0) {
		return 0;
	} else {
		int currX = x;
		int currY = y - 1;
		return currX + multiply(currX, currY);
	}
}

int main() {
	printf("%d\n", fibn(0));
	printf("%d\n", sumOfDigts(1234)); // 10
	printf("%d\n", sumOfDigts(0)); // 0
	printf("%d\n", multiply(2, 4));//8
	printf("%d\n", multiply(2, 0));//0
	printf("%d\n", multiply(0, 2));//0
	return 0;
}
