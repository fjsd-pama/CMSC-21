#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define PASSING_SCORE 60

typedef struct LinkedList{
	char name[20];
	int value;
	struct LinkedList* rest;
} LinkedList;

int maximum(LinkedList* head){
	if (head == NULL){
		return 0;
	} else{
		return fmax(head->value, maximum(head->rest));
	}
}

void printPalindromeOfFirstLetters(LinkedList* head){
	if (head == NULL){
		//do nothing
	} else{
		printf("%c", (head->name)[0]);
		printPalindromeOfFirstLetters(head->rest);
		printf("%c", (head->name)[0]);
	}
}

int numPassers(LinkedList* head){
	if (head  == NULL){
		return 0;
	} else{
		if (head->value >= PASSING_SCORE){
			int countHead = 1;
			int countRest = numPassers(head->rest);
			return countHead + countRest;
		}
		return numPassers(head->rest);
	}
}

int totalScoresOfPassers(LinkedList* head){
	if (head == NULL){
		return 0;
	} else{
		if (head->value >= PASSING_SCORE){
			int head_val = head->value;
			int rest_val = totalScoresOfPassers(head->rest);
			return head_val + rest_val;
		} else{
			return totalScoresOfPassers(head->rest);
		}
	}
}

int averageScoreOfPassers(LinkedList* head){
	return totalScoresOfPassers(head) / numPassers(head);
}

int append(int x, int toBeAppended){
	return (x * 10) + toBeAppended;
}

int secretFunction(int n){
	if (n == 0){
		return n;
	} else{
		return append(((n % 10) * 10), append(secretFunction(n / 10), n % 10));
		//append(n % 10, append(secretFunction((n / 10)), n % 10));
	}
}

int reverse(int n){
	if (n <= 9){
		return n;
	} else {
		if (n > 1000)
			return n % 10 * 1000 + reverse(n/10);
		else if (n > 100)
			return n % 10 * 100 + reverse(n/10);
		else
			return n % 10 * 10 + reverse(n/10);
	}
}


int main(){
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
    printf("%d\n", reverse(134));
    printf("%d\n", append(14, 3));
    printf("%d\n", reverse(1234567890));
    return 0;
}