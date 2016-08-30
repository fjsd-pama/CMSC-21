#include <stdio.h>

//Design a funtion that determines whether or not a student
//passes a course, given the student's score and the passing
//score (both percentages from 0-100).

//float, float -> int
//Determines whether or not a student passes a course

/*stub
int isPassing(float score, float passing){
	return 0;
}
*/

/*template
int isPassing(float score, float passing){
	return ... score passing;
}*/


int isPassing(float score, float passing){
	return (score >= passing);
}

int main() {
	printf("1 == %d\n", isPassing(98, 50));
	printf("1 == %d\n", isPassing(50, 50));
	printf("0 == %d\n", isPassing(45, 50));
    return 0;
}