#include "stdio.h"
#include "string.h"
#include "stdbool.h"

/*
Given the Binary tree of multilevel marketing sales people, create the following instructions:
-isMember : given a binary tree and a name, return true if the name is found in the tree, false otherwise. (Hint: use strcmp in string.h to check if two strings are equal)
-salesMoreThan : given a binary tree and a sales value (an integer), return the number of sales people who have exceeded the given value sales.
-displayNoRecruits: given a binary tree, displays the name of those with no recruits. (right and left trees are null).
*/

typedef struct BinTree{
	char name[10];
	int value;
	struct BinTree* left;
	struct BinTree* right;
} BinTree;


bool isMember(BinTree* root, char name[]) {
    if (root == NULL) {
        return false;
    } else {
        if (strcmp(root->name, name) == 0) {
            return true;
        } else {
            return (isMember(root->left, name) || isMember(root->right, name));
        }
    }
}


int salesMoreThan(BinTree* root, int sales) {
    if (root == NULL){
        return 0;
    } else {
        if (root->value >= sales) {
            int countSelf = 1;
            int countLeft = salesMoreThan(root->left, sales);
            int countRight = salesMoreThan(root->right, sales);
            return countSelf + countLeft + countRight;
        } else {
            int countLeft = salesMoreThan(root->left, sales);
            int countRight = salesMoreThan(root->right, sales);
            return countLeft + countRight;
        }
    }
}

void displayNoRecruits(BinTree* root) {
    if (root == NULL) {
        /* do nothing =) */
    } else {
        if ((root->left) != NULL || (root->right) != NULL) {
            displayNoRecruits(root->left);
            displayNoRecruits(root->right);
        } else {
            printf("%s\n", root);
        }
    }
    
}

int main() {
	BinTree icel = {"Icel", 20, NULL, NULL};
	BinTree lovely = {"Lovely", 22, &icel, NULL};
	BinTree candace = {"Candace", 15, &lovely, NULL};
	BinTree jean = {"Jean", 18, NULL, NULL};
	BinTree jeane = {"Jeane", 23, NULL, NULL};
	BinTree honey = {"Honey", 25, &jeane, &jean};
	BinTree jj = {"JJ", 19, &candace, &honey};

	printf("%i == 1\n", isMember(&jj, "Icel"));
	printf("%i == 1\n", isMember(&jj, "JJ"));
	printf("%i == 0\n", isMember(&lovely, "Honey"));
	printf("%d == 4\n", salesMoreThan(&jj, 20));
	printf("%d == 1\n", salesMoreThan(&icel, 20));
	printf("%d == 0\n", salesMoreThan(&icel, 24));
	displayNoRecruits(&jj);
	displayNoRecruits(&jean);
	displayNoRecruits(&honey);
	return 0;
}
