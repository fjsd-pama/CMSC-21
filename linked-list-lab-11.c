#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
Given a list of students with their name and score int hte exam, implement the following function:
-highestScore: Given the list of students with their scores, return the highest score.
-StudentsInitialpalindrome: Given the list of students with their names, print a palindrome of the first letter of their names.
Ex: students{Alden, Brent, Carl} // prints ABCCBA
-averageScoreOfPassers: Given the list of students with their scores and a passing score constant, return the average score of the students who passed.
*/

// You can create additional functions if needed.
#define PASSING_SCORE 60

typedef struct LinkedList
{
	char name[10];
	int value;
	struct LinkedList* rest;
} LinkedList;

//must be a recursive solution
int maximum(LinkedList* head)
{ if (head == NULL) {
    return 0;
} else {
    int currentMax = head->value;
    return fmax(currentMax, maximum(head->rest));
    }
}
	

//must be a recursive solution
void printPalindromeOfFirstLetters(LinkedList* head)
{ if (head == NULL) {
    //do nothing :)
} else {
    printf("%c", head->name[0]);
    printPalindromeOfFirstLetters(head->rest);
    printf("%c", head->name[0]);
}
}

int numPassers(LinkedList* head) {
    if (head == NULL) {
        return 0;
    } else {
        if (head->value >= PASSING_SCORE) {
            int countHead = 1;
            int countRest = numPassers(head->rest);
            return countHead + countRest;
        } else {
            int countRest = numPassers(head->rest);
            return countRest;
        }
    }
}

int totalScoresOfPassers(LinkedList* head) {
    if (head == NULL){
        return 0;
    } else {
        if (head->value >= PASSING_SCORE) {
            int total = head->value;
            int totalRest = totalScoresOfPassers(head->rest);
            return total + totalRest;
        } else {
            int totalRest = totalScoresOfPassers(head->rest);
            return totalRest;
        }
    }
}
//not necessary a recursive solution
int averageScoreOfPassers(LinkedList* head)
{
   return totalScoresOfPassers(head) / numPassers(head);
}

int main() {
    LinkedList cris = {"Cris", 61, NULL};
    LinkedList ivan = {"Ivan", 55, &cris};
    LinkedList vic = {"Vic", 60, &ivan};
    LinkedList iris = {"Iris", 59, &vic};
    LinkedList carl = {"Carl", 70, &iris};
    printf("%d\n", maximum(&carl));
    printPalindromeOfFirstLetters(&carl);
    printf("\n");
    printf("%d\n", numPassers(&carl));
    printf("%d\n", totalScoresOfPassers(&carl));
    printf("%d\n", averageScoreOfPassers(&carl));
}
