#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// You can create additional functions if needed.
#define PASSING_SCORE 60

typedef struct LinkedList{
	char name[10];
	int value;
	struct LinkedList* rest;
} LinkedList;

//must be a recursive solution
int maximum(LinkedList* head){
    if (head == NULL){
        return 0;
    } else{
    	int max = 0;
        if (head->value >= max){
            max = head->value;
        }
        return fmax(max, maximum(head->rest));
    }
}

//must be a recursive solution
void printPalindromeOfFirstLetters(LinkedList* head){
	if (head == NULL){
        // do nothing
    } else{
    	//char* temp = head->name;
    	printf("%c", (head->name)[0]);
    	printPalindromeOfFirstLetters(head->rest);
		//printf("%c", (temp)[0]);
		printf("%c", (head->name)[0]);
    }
}


int totalScoresOfPassers(LinkedList* head){
    if (head == NULL){
        return 0;
    } else{
    	int selfScore = 0;
        if (head->value >= 60){
            selfScore = head->value;
        }
        return selfScore + totalScoresOfPassers(head->rest);
    }
}

int numPassers(LinkedList* head){
    if (head == NULL){
        return 0;
    } else{
    	int countSelf = 0;
        if (head->value >= 60){
            countSelf = 1;
        }
        return countSelf + numPassers(head->rest);
    }
}

//not necessary a recursive solution
int averageScoreOfPassers(LinkedList* head){
    return (float) totalScoresOfPassers(head) / numPassers(head);
}


int factorial(int n){
    if (n == 1){
        return 1;
    } else{
        return n * factorial(n - 1);
    }
}

int power(int x, int n){
    //multiplies a number x, nth times
    if (n == 0){
        return 1;
    } else{
       return x * power(x, n - 1);
    }
}

int randomSeq(int n){
    //Find the first nth terms
    if (n == 1){
        return 7;
    } else{
        return (3 * randomSeq(n - 1)) - 11;
    }
}

int seq2(int n){
    //Find the first nth terms
    if (n == 1){
        return 12;
    } else if (n == 2){
        return 4;
    } else{
        return seq2(n - 1) + (2 * seq2(n - 2));
    }
}

int seq3(int n){
    //Find the nth term
    if (n == 1){
        return 1;
    } else{
        return seq3(n - 1) + n;
    }
}

void forSeq3(int n){
    //Find the first nth terms
    if (n == 1){
        printf("1 ");
    } else{
        forSeq3(n - 1);
        printf("%d ", seq3(n));
    }
}

int main(){
 	LinkedList a = {"Ada", 98, NULL};
 	LinkedList b = {"Knutch", 98, &a};
 	LinkedList c = {"Lewis", 40, &b};
 	LinkedList d = {"Finn", 56, &c};
 	printf("%d\n", maximum(&d));
 	printf("%d\n", totalScoresOfPassers(&d));
 	printf("%d\n", numPassers(&d));
 	printf("%d\n", averageScoreOfPassers(&d));
 	printPalindromeOfFirstLetters(&d);
    printf("\n%d\n", factorial(4));
    printf("%d\n", power(10, 2));
    printf("%d\n", randomSeq(4)); //46
    printf("%d\n", seq2(4)); //36
    printf("%d\n", seq3(5)); //15
    forSeq3(5);
}
