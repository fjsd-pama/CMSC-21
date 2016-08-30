#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// none -> int
//Calculates the sum of all numbers from 0 to 100
//that are divisible by 4
int sum_100(){
	int sum = 1;
	int i = 0;
	while(i <= 100){
		i += 1;
		if (i % 4 == 0){
			sum += 1;
		}

	}
	return sum;
}

int min_of_2(int num1, int num2){
	if (num1 < num2){
		return num1;
	}

	return num2;
}

int GCD(int num1, int num2){
	int gcd = 0;
	int num = min_of_2(num1, num2);
	for (int i = 1; i <= num; i++){
		if ((num1 % i == 0) && (num2 % i == 0)){
			if (i > gcd){
				gcd = i;
			}
		}
	}

	return gcd;

}

bool is_prime(int n){
	int factors = 0;
	for (int i = 1; i <= n; i++){
		if (n % i == 0){
			factors += 1;
		}
	}

	return (factors <= 2);

}

//int -> void
//Generates prime number between 1 and n
void prime_numbers(int n){
	for (int i = 1; i <= n; i++){
		if (is_prime(i)){
			printf("%d ", i);
		}
	}

	printf("%s", "\n");

}

int factorial(int n){
	int result = 1;
	for (int i = 2; i <= n; i++){
		result *= i;
	}

	return result;
}

void fibonacci(int n){
	int x = 0;
	int y = 1;
	int add = 0;
	int num_of_fibonacci = 1;
	printf("%d ", 0);
	while (num_of_fibonacci < n){
		add = x + y;
		printf("%d ", add);
		x = y;
		y = add;
		num_of_fibonacci += 1;
	}

	printf("%s", "\n");

}

int main (){
	// printf("%d\n", sum_100());
	// printf("%d\n", min_of_2(8, 12));
	printf("%d\n", GCD(5, 3));
	// printf("%d\n", is_prime(2));
	// prime_numbers(2);
	// prime_numbers(10);
	// printf("%d\n", factorial(7));
	//fibonacci(20);
	return 0;
}