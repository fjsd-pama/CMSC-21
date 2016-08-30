#include <stdio.h>

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

int main(){
	int board1[4][4] = {
		{6, 0, 0, 5},
		{0, 2, 4, 0},
		{1, 0, 0, 3},
		{0, 0, 0, 0}
	};

	printf("%s\n", "This is a test for function BRTLDiagonalSum");
	printf("%d\n", BRTLDiagonalSum(4, 4, board1, 0, 0));
	printf("%d\n", BRTLDiagonalSum(4, 4, board1, 1, 1));
	printf("%d\n", BRTLDiagonalSum(4, 4, board1, 1, 2));
	printf("%d\n", BRTLDiagonalSum(4, 4, board1, 0, 3));
	printf("%d\n", BRTLDiagonalSum(4, 4, board1, 2, 0));
	printf("%d\n\n", BRTLDiagonalSum(4, 4, board1, 2, 3));



	printf("%s\n", "This is a test for function TRBLDiagonalSum");
	printf("%d\n", TRBLDiagonalSum(4, 4, board1, 0, 0));
	printf("%d\n", TRBLDiagonalSum(4, 4, board1, 1, 1));
	printf("%d\n", TRBLDiagonalSum(4, 4, board1, 1, 2));
	printf("%d\n", TRBLDiagonalSum(4, 4, board1, 0, 3));
	printf("%d\n", TRBLDiagonalSum(4, 4, board1, 2, 0));
	printf("%d\n\n", TRBLDiagonalSum(4, 4, board1, 2, 3));

	printf("%s\n", "This is a test for function BLTRDiagonalSum");
	printf("%d\n", BLTRDiagonalSum(4, 4, board1, 0, 0));
	printf("%d\n", BLTRDiagonalSum(4, 4, board1, 1, 1));
	printf("%d\n", BLTRDiagonalSum(4, 4, board1, 1, 2));
	printf("%d\n", BLTRDiagonalSum(4, 4, board1, 0, 3));
	printf("%d\n", BLTRDiagonalSum(4, 4, board1, 2, 0));
	printf("%d\n\n", BLTRDiagonalSum(4, 4, board1, 2, 3));

	printf("%s\n", "This is a test for function TLBRDiagonalSum");
	printf("%d\n", TLBRDiagonalSum(4, 4, board1, 0, 0));
	printf("%d\n", TLBRDiagonalSum(4, 4, board1, 1, 1));
	printf("%d\n", TLBRDiagonalSum(4, 4, board1, 1, 2));
	printf("%d\n", TLBRDiagonalSum(4, 4, board1, 0, 3));
	printf("%d\n", TLBRDiagonalSum(4, 4, board1, 2, 0));
	printf("%d\n\n", TLBRDiagonalSum(4, 4, board1, 2, 3));
	return 0;
}