#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
	int nextSequence = 0;
	printf("%d %d ", n1, n2);
	while ((nextSequence = n1 + n2) <= n){
		printf("%d ", nextSequence);
		n1 = n2;
		n2 = nextSequence;		
	}

	printf("\n");
}

//int -> boolean
//Determines whether the given integer n is prime or not
bool isPrime(int n){
	for (int i = 2; i < n; i++){
		if (n % i == 0){
			return false;
		}
	}

	return true;
}

//int -> void
//Displays the series of 1 + 1/2 + 1/3 + ... 1/n
//and their sum
void displaySequence(int n){
	float sum = 1;
	int sth = 1;
	printf("%d ", sth);
	while (sth < n){
		sth++;
		sum += 1.0/sth;
		printf("+ 1/%d ", sth);
	}
	printf("\nTheir sum is %f.\n", sum);
}

//int -> void
//Prints the series 1 + 3 + 5 + 7 + 9 ... n
//and their sum
void displaySequence1(int n){
	int sum = 1;
	int sth = 1;
	printf("%d ", sth);
	while (sth < n){
		sth += 2;
		sum += sth;
		printf("%d ", sth);
	}
	printf("\nTheir sum is %d.\n", sum);
}

typedef struct{
	int sum;
	float average;
} SumAndAverage;

#define NUM_ELEMENTS 10
//int arr[] -> SumAndAverage
//Shows the sum of 10 elements of array and show the average
SumAndAverage sumAndAve(int arr[]){
	int sum = 0;
	float average = 0.0;
	for (int i = 0; i < NUM_ELEMENTS; i++){
		sum += arr[i];
	}
	average = (sum / 10.0);
	return (SumAndAverage){sum, average};
}

//int array[], int -> int
//Returns the maximum number in an array
int maxValueInArray(int arr[], int length){
	int maxVal = arr[0];
	for(int i = 1; i < length; i++){
		if (arr[i] > maxVal){
			maxVal = arr[i];
		}
	}
	return maxVal;

}


//int -> int
//Find the factorial of an integer n
int factorial(int n){
	int result = 1;
	for (int i = 1; i <= n; i++){
		result *= i;
	}

	return result;
}


#define VOWELS_NUM 5
//char -> char
//Converts an uppercase letter to a lowercase letter
char toUpper(char letter){
	if(letter >= 'a' && letter <= 'z'){
		return (letter - 32);
	}

	return letter;
}

//char -> boolean
//Returns true if the given character is a vowel
bool isVowel(char letter){
	char VOWELS[VOWELS_NUM] = {'a', 'e', 'i', 'o', 'u'};
	for(int i = 0; i < VOWELS_NUM; i++){
		if (toUpper(VOWELS[i]) == toUpper(letter)){
			return true;
		}
	}
	return false;
}

//char -> boolean
//Returns true if the given character is a consonant
bool isConsonant(char letter){
	if ((toUpper(letter) >= 'A' && toUpper(letter) <= 'Z') && (!(isVowel(letter)))){
		return true;
	}
	return false;
}

//char -> boolean
//Returns true if the given character is a special character
bool isSpecialChar(char sth){
	if ((sth >= '!' && sth <= '/') || (sth >= ':' && sth <= '@') ||
		(sth >= '[' && sth <= '_') || (sth >= '{' && sth <= '~')){
			return true;
	}
	return false;
}

//char -> boolean
//Determines if the given character is a letter
bool isLetter(char sth){
	if((sth >= 'a' && sth <= 'z') || (sth >= 'A' && sth <= 'Z')){
		return true;
	}

	return false;
}

//char arr[] -> int
//Counts the number of words in the given string
int numOfWords(char arr[]){
	int wordCount = 1;
	for (int i = 1; arr[i] != '\0'; i++){
		if ((arr[i] == ' ') && (isLetter(arr[i - 1]))){
			wordCount++;
		}
	}
	return wordCount;
}

//char arr[] -> int
//Counts the number of spaces in the given string
int numSpaces(char arr[]){
	int spaceCount = 0;
	for (int i = 0; arr[i] != '\0'; i++){
		if (arr[i] == ' '){
			spaceCount++;
		}
	}
	return spaceCount;
}

typedef struct{
	int numberOfvowels;
	int consonants_num;
	int specialChar_num;
	int words_num;
	int spaces_num;
} SentenceFeatures;

//char arr[] -> void
//Prints the sentence features of the given character
SentenceFeatures strFeatures(char arr[]){
	int vowels = 0;
	int consonants = 0;
	int specialChar = 0;
	int words = numOfWords(arr);
	int spaces = numSpaces(arr);
	for (int i = 0; arr[i] != '\0'; i++){
		if (isVowel(arr[i])){
			vowels ++;
		} else if(isConsonant(arr[i])){
			consonants++;
		} else if (isSpecialChar(arr[i])){
			specialChar++;
		}
	}

	return (SentenceFeatures){vowels, consonants, specialChar, words, spaces};
}

int main(){
	// printf("%d\n", reverseNum(23456));
	// printf("0 == %d\n", isLeapYear(2015));
	// printf("1 == %d\n", isLeapYear(2016));
	// printf("0 == %d\n", isEven(3));
	// printf("1 == %d\n", isEven(4));
	// display10NaturalNum();
	// Fibonacci(100);
	// Fibonacci(5);
	// printf("\nTest for function isPrime:\n");
	// printf("0 == %d\n", isPrime(10));
	// printf("1 == %d\n", isPrime(19));
	// displaySequence(7);
	// displaySequence1(7);

	// int arr1[NUM_ELEMENTS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	// int arr2[5] = {0, 7, 6, 1, 0};
	// SumAndAverage one = sumAndAve(arr1);
	// printf("The sum and average of arr1 is %d, and %f.\n", sumAndAve(arr1));
	// printf("The sum and average of arr1 is %d, and %f.\n", one.sum, one.average);

	// printf("\n\nThis is a test for function maxValueInArray:\n");
	// printf("%d\n", maxValueInArray(arr1, 10));
	// printf("%d\n", maxValueInArray(arr2, 5));

	// printf("\nFactorial: %d\n", factorial(5));

	// printf("\nTest for function isVowel:\n");
	// printf("%d\n", isVowel('e'));
	// printf("%d\n", isVowel('E'));
	// printf("%d\n", isVowel('b'));
	// printf("%d\n", isVowel('Z'));

	// printf("\nTest for function isConsonant:\n");
	// printf("%d\n", isConsonant('T'));
	// printf("%d\n", isConsonant('p'));
	// printf("%d\n", isConsonant('a'));
	// printf("%d\n", isConsonant('U'));

	// printf("1 == %d\n", isSpecialChar('*'));
	// printf("0 == %d\n", isLetter('&'));
	// printf("7 == %d\n", numOfWords("This is a test for function numOfWords."));
	// printf("6 == %d\n", numSpaces("This is a test for function numOfWords."));
	printf("HERE ARE THE FEATURES OF THE SENTENCES: \nVOWEL: %d\nCONSONANTS: %d\nSPECIAL CHARACTER: %d\nWORDS: %d\nSPACES: %d\n", strFeatures("*This is a test for function numOfWords."));
	return 0;
}