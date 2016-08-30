#include <stdio.h>
#include <stdbool.h>

//int -> int
//Reverses a given number
int reverseNum(int n){
	int number = n;
	int digit = n;
	int result = 0;
	while (number > 0){
		digit = number % 10;
		number /= 10;
		result = (result * 10) + digit;
	}
	return result;
}

//int -> boolean
//Determines if the entered year is a leap year
bool isLeapYear(int year){
	return (year % 4 == 0);
}

//int -> boolean
//Determines if the given integer n is even of odd
bool isEven(int n){
	if (n % 2 == 0){
		return true;
		printf("%s\n", "The given number is even.");
	} else {
		printf("%s\n", "The given number is odd.");
	}
	return false;
}

//none -> void
//Display 10 natural numbers and their sum
void display10NaturalNum(){
	int num = 0;
	int sum = 0;
	while (num < 10){
		num++;
		sum += num;
		printf("%d ", num);
	}

	printf("\nTheir sum is %d.\n", sum);
}

//int -> void
//Prints the Fibonacci series up to the given integer n
void Fibonacci(int n){
	int n1 = 0;
	int n2 = 1;
	while (n1 < n){
		n1 += n2;
		n2 = n1;
		printf("%d ", n1);
	}
}

int main(){
	printf("%d\n", reverseNum(23456));
	printf("0 == %d\n", isLeapYear(2015));
	printf("1 == %d\n", isLeapYear(2016));
	printf("0 == %d\n", isEven(3));
	printf("1 == %d\n", isEven(4));
	display10NaturalNum();
	Fibonacci(100);
	return 0;
}