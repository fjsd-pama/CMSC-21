#include <stdio.h>
#include <stdbool.h>

//int -> boolean
//Determines if a given number n is prime
bool isPrime(int n){
	for(int i = 2; i < n; i++){
		if (n % i == 0){
			return false;
		}
	}
	return true;
}

//int -> boolean
//Determines if a given integer n is a humble number
//i.e it has only prime factors 2, 3, 5, and 7 only
bool isHumble(int n){
	for (int i = 2; i < n; i++){
		if ((n % i == 0) && isPrime(i)){
			if (i != 2 && i != 3 && i != 5 && i != 7){
				return false;
			}
		}
	}
	return true;
}

int main(){
	printf("1 == %d\n", isPrime(3));
	printf("0 == %d\n", isPrime(9));
	printf("1 == %d\n", isPrime(73));
	printf("1 == %d\n", isHumble(25));
	printf("1 == %d\n", isHumble(27));
	printf("0 == %d\n", isHumble(44));
	printf("0 == %d\n", isHumble(39));
	return 0;
}