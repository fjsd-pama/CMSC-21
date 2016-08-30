#include <stdio.h>

//int arr[][] -> void
//Displays the given matrix
void display2DArray(int rowLen, int colLen, int matrix[rowLen][colLen]){
	for (int i = 0; i < rowLen; i++){
		for (int j = 0; j < colLen; j++){
			printf("%d ", matrix[i][j]);
			if(j == (colLen - 1)){
				printf("\n");
			}
		}
	}
}

/*typedef struct{
	int rowLen;
	int colLen;
	int* matrix[rowLen][colLen];
} Matrix;
*/
//int arr[][] -> void
//Adds two matrices
void addTwoMatrices(int rowLen1, int colLen1, matrix1[rowLen1][colLen2], int rowLen2, int colLen2, matrix2[rowLen2][colLen2]){
	if((rowLen1 == rowLen2) && (colLen1 == colLen2)){
		for (int i = 0; i < rowLen1; i++){
			for (int j = 0; j < colLen1; j++){
				matrix1[i][j] = (matrix1[i][j] + matrix2[i][j]);
			}
		}
	}
}


int main(){
	printf("YEHEY! 2D ARRAYS NA TA :D\nThank You, Lord.\nYou are so marvelous.\n");
	int matrix1[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	RowCol one = {3, 3};
	RowCol two = {3, 3};
	RowCol three = {3, 4};

	int matrix2[3][3] = {
		{1, 1, 1},
		{1, 1, 1},
		{1, 1, 1}
	};

	int matrix3[3][4] = {
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4}
	};

	display2DArray(3, 3, matrix1);
	addTwoMatrices(one, matrix1, two, matrix2);
	addTwoMatrices(two, matrix2, three, matrix3);
	addTwoMatrices(one, matrix1, three, matrix3);
	return 0;
}