#include <stdio.h>
#include <stdbool.h>
#include <string.h>


//int, int -> int
//Appends a given digit to a number
int append(int num, int digit) {
  return (num * 10) + digit;
}

//float -> boolean
//Returns true if percentage score is at least the passing score;
//otherwise, returns false.
//NOTE: Passing score is a predetermined value

//stub
bool check_if_pass(float score){
	return false;
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
	return 0;
}
