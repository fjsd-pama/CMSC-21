#include <stdio.h>

int isRetired(int age){
	return (age >= 65);
}

int isAcid(float phLevel){
	return (phLevel < 7);
}

int isTeenager(int age){
	return ((age >= 13) && (age <= 19));
}

int isEven(int x){
	return (x % 2 == 0);
}

int isMultipleOf10(int x){
	return (x % 10 == 0);
}

int isVowel(char letter){
	return ((letter == 'a') | (letter == 'e') | (letter == 'i') | (letter == 'o') | (letter == 'u'));
}

int isConsonant(char letter){
	return !((letter == 'a') | (letter == 'e') | (letter == 'i') | (letter == 'o') | (letter == 'u'));
}

char toLower(char letter){
	if (letter >= 'A' && letter <= 'Z'){
		return letter + 32;
	}

	return letter;
}

char toUpper(char letter){
	if (letter >= 'a' && letter <= 'z'){
		return letter - 32;
	}

	return letter;
}

int toInt(char number){
	if (number >= '0' && number <= '9'){
		return number - 48;
	}

	return -1;
}

char toChar(int number){
	if (number >= toInt('0') && number <= toInt('9')){
		return number + 48;
	}

	return '\0';
}


int main(){
	/*printf("This is a test for isRetired: \n");
	printf("0 == %d\n", isRetired(19));
	printf("1 == %d\n", isRetired(65));
	printf("1 == %d\n", isRetired(70));
	printf("This is a test for isAcid: \n");
	printf("0 == %d\n", isAcid(7));
	printf("0 == %d\n", isAcid(8));
	printf("1 == %d\n", isAcid(6));
	printf("This is a test for isTeenager: \n");
	printf("0 == %d\n", isTeenager(20));
	printf("0 == %d\n", isTeenager(12));
	printf("1 == %d\n", isTeenager(13));
	printf("1 == %d\n", isTeenager(19));
	printf("1 == %d\n", isTeenager(15));
	printf("This is a test for isEven: \n");
	printf("0 == %d\n", isEven(1));
	printf("1 == %d\n", isEven(2));
	printf("This is a test for isMultipleOf10: \n");
	printf("0 == %d\n", isMultipleOf10(15));
	printf("1 == %d\n", isMultipleOf10(100));
	printf("This is a test for isVowel: \n");
	printf("0 == %d\n", isVowel('b'));
	printf("1 == %d\n", isVowel('a'));
	printf("This is a test for isConsonant: \n");
	printf("0 == %d\n", isConsonant('a'));
	printf("1 == %d\n", isConsonant('b'));
	printf("This is a test for toUpper: \n");
	printf("A == %c\n", toUpper('a'));
	printf("B == %c\n", toUpper('b'));
	printf("C == %c\n", toUpper('C'));
	printf("This is a test for toLower: \n");
	printf("a == %c\n", toLower('A'));
	printf("b == %c\n", toLower('B'));
	printf("c == %c\n", toLower('c'));
	printf("This is a test for toInt: \n");
	printf("1 == %d\n", toInt('1'));
	printf("-1 == %d\n", toInt('Z'));
	printf("This is a test for toChar: \n");
	printf("'1' == '%c'\n", toChar(1));
	printf("'%c'\n", toChar('a'));
	printf("'%c'\n", toChar(12));*/
	printf("%d\n", 1232 % 10);
	printf("%d\n", 1 % 10);
	printf("%d\n", 1232 / 10);
	return 0;
}