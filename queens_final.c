#include <stdio.h>
#include <stdlib.h>

//int, int, int arr[][], int -> int
//Calculates the the sum of a specified row
int rowSum(int rowLen, int colLen, int grid[rowLen][colLen], int rowIndex) {
    int sum = 0;
    for (int i = 0; i < colLen; i++){
        sum += grid[rowIndex][i];
    }
    
    return sum;

}

//int, int, int, int arr[][], int -> int
//Calculates the sum of a specified column
int colSum(int grid_size_rows, int grid_size_cols, int grid[grid_size_rows][grid_size_cols], int colIndex) {
    int sum = 0;
    for (int i = 0; i < grid_size_rows; i++){
        sum += grid[i][colIndex];
    }
    
    return sum;

}

//int, int, int arr[][], int, int -> int
//Calculates the bottom-right-to-top-left diagonal sum
//starting from a given row index i and column index j
int BRTLDiagonalSum(int rowLen, int colLen, int board[rowLen][colLen], int i, int j){
	int diagSum = 0;
	int row_index = i;
	for (int k = j; (k >= 0 && row_index >= 0); k--){
		diagSum += board[row_index][k];
		row_index--;
	}

	return diagSum;
}

//int, int, int arr[][], int, int -> int
//Calculates the top-right-to-bottom-left diagonal sum
//starting from a given row index i and column index j
int TRBLDiagonalSum(int rowLen, int colLen, int board[rowLen][colLen], int i, int j){
	int diagSum = 0;
	int row_index = i;
	for (int k = j; (k >= 0 && row_index < rowLen); k--){
		diagSum += board[row_index][k];
		row_index++;
	}

	return diagSum;
}


//int, int, int arr[][], int, int -> int
//Calculates the bottom-left-to-top-right diagonal sum
//starting from a given row index i and column index j
int BLTRDiagonalSum(int rowLen, int colLen, int board[rowLen][colLen], int i, int j){
	int diagSum = 0;
	int row_index = i;
	for (int k = j; (k < colLen && row_index >= 0); k++){
		diagSum += board[row_index][k];
		row_index--;
	}

	return diagSum;
}

//int, int, int arr[][], int, int -> int
//Calculates the top-left-to-bottom-right diagonal sum
//starting from a given row index i and column index j
int TLBRDiagonalSum(int rowLen, int colLen, int board[rowLen][colLen], int i, int j){
	int diagSum = 0;
	int col_index = j;
	for (int k = i; (k < rowLen && col_index < colLen); k++){
		diagSum += board[k][col_index];
		col_index++;
	}

	return diagSum;
}

//int, int, int arr[][], int, int -> int
//Returns 1 if the queens are safe to each other with respect
//to the diagonals
int safeDiagonal(int rowLen, int colLen, int board[rowLen][colLen], int i, int j){
	return ((BRTLDiagonalSum(rowLen, colLen, board, i, j) < 2) && (TRBLDiagonalSum(rowLen, colLen, board, i, j) < 2) && (BLTRDiagonalSum(rowLen, colLen, board, i, j) < 2) && (TLBRDiagonalSum(rowLen, colLen, board, i, j) < 2));
}

/*stub
int safeQueen(int rowLen, int colLen, int board[rowLen][colLen]){
	return 0;
}*/

/*template
int safeQueen(int rowLen, int colLen, int board[rowLen][colLen]){
	int safe = 0;
	for (int i = 0; i < rowLen; i++){
		for (int j = 0; j < colLen; j++){
			...
		}
	}
	return 1;
}
*/

//int, int, int arr[][] -> int
//Returns 1 if the the queen(s) are safe to each other
int safeQueen(int rowLen, int colLen, int board[rowLen][colLen]){
	int safe = 0;
	for (int i = 0; i < rowLen; i++){
		for (int j = 0; j < colLen; j++){
			if(board[i][j] == 1){
				safe = ((((colSum(rowLen, colLen, board, j) < 2) && (rowSum(rowLen, colLen, board, i) < 2)) && safeDiagonal(rowLen, colLen, board, i, j)));
				if (!(safe)){
					return 0;
				}
			}
		}
	}
	return 1;
	
}

int main(){
	int board1[3][3] = {
		{1, 0, 0},
		{0, 0, 0},
		{0, 0, 1}
	};

	int board2[4][4] = {
		{0, 1, 0, 0},
		{0, 0, 0, 0},
		{1, 0, 0, 0},
		{0, 0, 1, 0}
	};

	int board3[8][8] = {
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
	};


	printf("%d\n", safeQueen(3, 3, board1));
	printf("%d\n", safeQueen(4, 4, board2));
	printf("%d\n", safeQueen(8, 8, board3));
	return 0;
}