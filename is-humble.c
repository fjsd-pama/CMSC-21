#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int -> int
//Returns 1 if the given integer n is prime
int isPrime(int n){
	int num = 0;   //the number of factors
	for (int i = 2; i <= (n / 2); i++){
		if (n % i == 0){
			num += 1;
		}
	}

	return (num == 0);
}

/*int isHumble(int n){
	return 0;
}

int isHumble(int n){
	for (int i = 2; i < n; i++){
		...
	}

	return 0;
}*/

//int -> int
//Returns 1 if the given integer n has only prime factors
//2, 3, 5, and 7 only
int isHumble(int n){
	for (int i = 2; i < n; i++){
		if ((n % i == 0) && (isPrime(i) == 1)){
			if (i != 2 && i != 3 && i != 5 && i != 7){
				return 0;
			}
		}
	}

	return 1;
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