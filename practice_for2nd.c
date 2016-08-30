#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

//int, int -> int
//Appends a given digit to a number
int append(int num, int digit) {
  return (num * 10) + digit;
}

//float -> boolean
//Returns true if percentage score is at least the passing score;
//otherwise, returns false.
//NOTE: Passing score is a predetermined value

/*//stub
bool check_if_pass(float score){
	return false;
}

//template
bool check_if_pass(float score){
	return ... score, PASSING_SCORE;
}*/


#define PASSING_SCORE 60.00000

bool check_if_pass(float score){
	return (score >= PASSING_SCORE);
}


//int -> boolean
//Determines if the given integer n is a prime number

/*//stub
bool isPrime(int n){
	return false;
}

//template
bool isPrime(int n){
	return ... n;
}*/

bool is_prime(int n){
	int factor_count = 0;
	if ((n <= 2)){
		return false;
	}

	for (int i = 2; i <= (n / 2); i++){
		if (n % i == 0){
			factor_count++;
		}
	}
	return (factor_count == 0);
}

//Computes the total cost of items in a shopping cart: balls at 400 each,
//net at 1000 each, jerseys at 600 each
//int, int, int -> float

/*//stub
float totalCost(int balls, int net, int jerseys){
	return 0.00; //kay float man
}

//template
float totalCost(int balls, int net, int jerseys){
	return ... balls, BALLS_PRICE, net, NET_PRICE, jerseys, JERSEYS_PRICE;
}*/


#define BALLS_PRICE 400
#define NET_PRICE 1000
#define JERSEYS_PRICE 600

float totalCost(int balls, int net, int jerseys){
	return (balls * BALLS_PRICE) + (net * NET_PRICE) + (jerseys * JERSEYS_PRICE);
}

//int arr[], int -> void
//Doubles every element of the array

/*//stub
void doubleArray(int arr[], int length){
	//return None
	//You are just to manipulate every element in the array
}

//template
void doubleArray(int arr[], int length){
	for (int i = 0; i < length; i++){
		....
	}
}*/

void doubleArray(int arr[], int length){
	for (int i = 0; i < length; i++){
		arr[i] = arr[i] * 2;
	}
}

//int arr[], int -> void
//Prints every element in the given integer array
void printArray(int arr[], int arr_length){
	for (int i = 0; i < arr_length; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//char -> int
//Converts a number character to integer
int toInt(char num_char){
	if(num_char >= '0' && num_char <= '9'){
		return (num_char - 48);
	}

	return 0;
}

//char -> int
//Converts a given character to its equivalent numeric value
int keypadEquiv(char character){

	if (character >= 'A' && character <= 'C'){
		return 2;
	} else if (character >= 'D' && character <= 'F'){
		return 3;
	} else if (character >= 'G' && character <= 'I'){
		return 4;
	} else if (character >= 'J' && character <= 'L'){
		return 5;
	} else if (character >= 'M' && character <= 'O'){
		return 6;
	} else if (character >= 'P' && character <= 'R'){
		return 7;
	} else if (character >= 'T' && character <= 'V'){
		return 8;
	} else if (character >= 'W' && character <= 'Z'){
		return 9;
	}

	return toInt(character);
}

//char [] -> int
//Accept an alphanumeric phone number (a string) and returns
//the equivalent numeric phone number (an integer)

int toNumericNum(char alphaNum[]){
	int numeric = 0;
	int sth = 0;
	for (int i = 0; alphaNum[i] != '\0'; i++){
		sth = keypadEquiv(alphaNum[i]);
		numeric = (numeric * 10) + sth;
	}

	return numeric;
}



//int, int -> float
// Computes the total cost of beads
// for a necklace, given the number of 
// red and blue beads

/*//stub
float totalCostOfBeads(int nums_red, int nums_blue){
	return 0.00;
}

//template
float totalCostOfBeads(int nums_red, int nums_blue){
	return ... nums_red, REDBEADS_price, nums_blue, BLUEBEADS_price;
}*/

#define REDBEADS_price 2
#define BLUEBEADS_price 4
#define THREAD_price 10

float totalCostOfBeads(int nums_red, int nums_blue){
	return (nums_red * REDBEADS_price) + (nums_blue * BLUEBEADS_price);
}

//float -> float
// Computes the total cost of thread 
// for a necklace, given the length
// in inches

/*//stub
float totalCostOfThread(int length_inch){
	return 0.00;
}

//template
float totalCostOfThread(int length_inch){
	return ... length_inch, THREAD_price;
}*/

float totalCostOfThread(int length_inch){
	return (length_inch * THREAD_price);
}

// int, int, int -> float
// Computes the total cost of materials
// for a necklace, given the number of rea
// and blue beads and the length of thread
// in inches

/*//stub
float totalCostOfMaterials(int nums_blue, int nums_red, int length_inch){
	return 0.00;
}

//template
float totalCostOfMaterials(int nums_blue, int nums_red, int Length_inch){
	return ... nums_blue, BLUEBEADS_price, nums_red, REDBEADS_price,
	   length_inch, THREAD_price;
}
*/
float totalCostOfMaterials(int nums_blue, int nums_red, int length_inch){
	return totalCostOfBeads(nums_blue, nums_red) + totalCostOfThread(length_inch);
}

int main() {
	printf("This is a test for function append:\n");
	printf("%d\n", append(1234, 5));
	printf("%d\n", append(1, 2));
	printf("%d\n", append(101011, 0));
	printf("%d\n", append(100, 1));

	printf("This is a test for function check_if_pass:\n");
	printf("1 == %d\n", check_if_pass(60.0));
	printf("0 == %d\n", check_if_pass(59.9));
	printf("0 == %d\n", check_if_pass(59.99999));
	printf("1 == %d\n", check_if_pass(60.00000000));

	printf("This is a test for function is_prime:\n");
	printf("%d == %d\n", is_prime(1), false);
	printf("%d == %d\n", is_prime(2), false);
	printf("%d == %d\n", is_prime(3), true);
	printf("%d == %d\n", is_prime(4), false);
	printf("%d == %d\n", is_prime(5), true);
	printf("%d == %d\n", is_prime(20), false);
	printf("%d == %d\n", is_prime(21), false);
	printf("%d == %d\n", is_prime(22), false);
	printf("%d == %d\n", is_prime(23), true);
	printf("%d == %d\n", is_prime(24), false);
	printf("%d == %d\n", is_prime(25), false);

	printf("This is a test for function totalCost:\n");
	printf("%2.f == 400\n", totalCost(1, 0, 0));
	printf("%2.f == 1000\n", totalCost(0, 1, 0));
	printf("%2.f == 600\n", totalCost(0, 0, 1));
	printf("%2.f == 2000\n", totalCost(1, 1, 1));
	printf("%2.f == 4000\n", totalCost(2, 2, 2));

	printf("This is a test for function doubleArray:\n");
	int arr1[] = {1, 2, 3};
	doubleArray(arr1, 3); //this is how to call void functions
	printArray(arr1, 3);

	printf("This is a test for function toNumericNum:\n");
	printf("%d = 2436373\n", toNumericNum("243NERD")); // expect 2436373

	printf("This is a test for function totalCostOfBeads:\n");
	printf("%.2f\n", totalCostOfBeads(0, 0));
	printf("%.2f\n", totalCostOfBeads(1, 1));
	printf("%.2f\n", totalCostOfBeads(2, 1));
	printf("%.2f\n", totalCostOfBeads(1, 2));
	printf("%.2f\n", totalCostOfBeads(10, 10));

	printf("This is a test for function totalCostOfThread:\n");
	printf("%.2f\n", totalCostOfThread(0));
	printf("%.2f\n", totalCostOfThread(1));
	printf("%.2f\n", totalCostOfThread(5));

	printf("This is a test for function totalCostOfMaterials:\n");
	printf("%.2f\n", totalCostOfMaterials(0, 0, 0));
	printf("%.2f\n", totalCostOfMaterials(1, 1, 1));
	printf("%.2f\n", totalCostOfMaterials(5, 5, 5));
	return 0;
}