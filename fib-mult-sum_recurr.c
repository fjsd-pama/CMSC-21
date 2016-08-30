#include <stdio.h>

//returns the nth Fibonacci
int NthFibonacci(int n){
	if (n == 1){
		return 0;
	} else if (n == 2){
		return 1;
	} else{
		return NthFibonacci(n - 2) + NthFibonacci(n - 1);
	}
}

int multiply(int x, int y){
	if (y == 0){
		return 0;
	} else{
		return x + multiply(x, y - 1);
	}	
}

int sumOfDigits(int n){
	if (n == 0){
		return 0;
	} else{
		return sumOfDigits(n / 10) + (n % 10);
	}
}

int main(){
	printf("%d\n", NthFibonacci(5);
	printf("%d\n", multiply(3, 7));
	printf("%d\n", sumOfDigits(3456));
	return 0;
}